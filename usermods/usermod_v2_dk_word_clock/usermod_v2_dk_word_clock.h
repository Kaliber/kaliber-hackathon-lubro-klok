#pragma once

#include "wled.h"

/*
 * Usermods allow you to add own functionality to WLED more easily
 * See: https://github.com/Aircoookie/WLED/wiki/Add-own-functionality
 * 
 * Modified version of usermod_v2_word_clock. This usermod can be used to drive
 * a word clock with 12x10 pixel matrix with WLED.
 */

//class name. Use something descriptive and leave the ": public Usermod" part :)
class UsermodDKWordClock : public Usermod {
  private:
    unsigned long lastTime = 0;

    // set your config variables to their boot default value (this can also be done in readFromConfig() or a constructor if you prefer)
    bool usermodActive = false;
    bool heartEnabled = false;
    
    // defines for mask sizes
    #define maskSizeLeds        120
    #define maskSizeMinutes     12
    #define maskSizeHours       6
    #define maskSizeItIs        5
    #define maskSizeAlmost      5

    // "minute" masks
    const int maskMinutes[12][maskSizeMinutes] = 
    {
      {116, 117, 118,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, // :00 uur
      { 12,  13,  14,  15,  32,  33,  34,  35,  -1,  -1,  -1,  -1}, // :05 vijf over
      { 20,  21,  22,  23,  32,  33,  34,  35,  -1,  -1,  -1,  -1}, // :10 tien over
      { 36,  37,  38,  39,  40,  48,  49,  50,  51,  -1,  -1,  -1}, // :15 kwart over
      { 20,  21,  22,  23,  24,  25,  26,  27,  42,  43,  44,  45}, // :20 tien voor half
      { 12,  13,  14,  15,  24,  25,  26,  27,  42,  43,  44,  45}, // :25 vijf voor half
      { 42,  43,  44,  45,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, // :30 half
      { 12,  13,  14,  15,  32,  33,  34,  35,  42,  43,  44,  45}, // :35 vijf over half
      { 20,  21,  22,  23,  32,  33,  34,  35,  42,  43,  44,  45}, // :40 tien over half
      { 36,  37,  38,  39,  40,  56,  57,  58,  59,  -1,  -1,  -1}, // :45 kwart voor
      { 20,  21,  22,  23,  24,  25,  26,  27,  -1,  -1,  -1,  -1}, // :50 tien voor
      { 12,  13,  14,  15,  24,  25,  26,  27,  -1,  -1,  -1,  -1}, // :55 vijf voor
    };

    // hour masks
    const int maskHours[12][maskSizeHours] = 
    {
      {108, 109, 110, 111, 112, 113}, // 00: => twaalf
      { 60,  61,  62,  -1,  -1,  -1}, // 01: een
      { 64,  65,  66,  67,  -1,  -1}, // 02: twee
      { 68,  69,  70,  71,  -1,  -1}, // 03: drie
      { 72,  73,  74,  75,  -1,  -1}, // 04: vier
      { 76,  77,  78,  79,  -1,  -1}, // 05: vijf
      { 81,  82,  83,  -1,  -1,  -1}, // 06: zes
      { 84,  85,  86,  87,  88,  -1}, // 07: zeven
      { 96,  97,  98,  99,  -1,  -1}, // 08: acht
      { 91,  92,  93,  94,  95,  -1}, // 09: negen
      {101, 102, 103, 104,  -1,  -1}, // 10: tien
      {105, 106, 107,  -1,  -1,  -1}  // 11: elf
    };

    // mask "het is"
    const int maskItIs[maskSizeItIs] = {0, 1, 2, 4, 5};

    // mask "bijna"
    const int maskAlmost[maskSizeAlmost] = {7, 8, 9, 10, 11};

    // heart matrix location
    const int heartPin = 119;

    // overall mask to define which LEDs are on
    int maskLedsOn[maskSizeLeds] = 
    {
      0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0
    };

    // update led mask
    void updateLedMask(const int wordMask[], int arraySize) {
      // loop over array
      for (int x=0; x < arraySize; x++) {
        // check if mask has a valid LED number
        if (wordMask[x] >= 0 && wordMask[x] < maskSizeLeds) {
          // turn LED on
          maskLedsOn[wordMask[x]] = 1;
        }
      }
    }

    // set hours
    void setHours(int hours) {
      int index = hours;

      if (hours == 12) {
        index = 0;
      }

      // update led mask
      updateLedMask(maskHours[index], maskSizeHours);
    }

    // set minutes
    void setMinutes(int index) {
      // update led mask
      updateLedMask(maskMinutes[index], maskSizeMinutes);
    }

    // update the display
    void updateDisplay(uint8_t hours, uint8_t minutes) {
      // clear complete matrix at the beginning
      for (int x = 0; x < maskSizeLeds; x++) {
        maskLedsOn[x] = 0;
      }
      
      // display "het is"
      updateLedMask(maskItIs, maskSizeItIs);

      // show heart if enabled
      if (heartEnabled) {
        maskLedsOn[heartPin] = 1;
      }

      switch (minutes) {
        case 0:
        case 1:
        case 2:
          setMinutes(0);
          setHours(hours);
          break;
        case 3:
        case 4:
          updateLedMask(maskAlmost, maskSizeAlmost);
          setMinutes(1);
          setHours(hours);
          break;
        case 5:
        case 6:
        case 7:
          setMinutes(1);
          setHours(hours);
          break;
        case 8:
        case 9:
          updateLedMask(maskAlmost, maskSizeAlmost);
          setMinutes(2);
          setHours(hours);
          break;
        case 10:
        case 11:
        case 12:
          setMinutes(2);
          setHours(hours);
          break;
        case 13:
        case 14:
          updateLedMask(maskAlmost, maskSizeAlmost);
          setMinutes(3);
          setHours(hours);
          break;
        case 15:
        case 16:
        case 17:
          setMinutes(3);
          setHours(hours);
          break;
        case 18:
        case 19:
          updateLedMask(maskAlmost, maskSizeAlmost);
          setMinutes(4);
          setHours(hours);
          break;
        case 20:
        case 21:
        case 22:
          setMinutes(4);
          setHours(hours);
          break;
        case 23:
        case 24:
          updateLedMask(maskAlmost, maskSizeAlmost);
          setMinutes(5);
          setHours(hours + 1);
          break;
        case 25:
        case 26:
        case 27:
          setMinutes(5);
          setHours(hours + 1);
          break;
        case 28:
        case 29:
          updateLedMask(maskAlmost, maskSizeAlmost);
          setMinutes(6);
          setHours(hours + 1);
          break;
        case 30:
        case 31:
        case 32:
          setMinutes(6);
          setHours(hours + 1);
          break;
        case 33:
        case 34:
          updateLedMask(maskAlmost, maskSizeAlmost);
          setMinutes(7);
          setHours(hours + 1);
          break;
        case 35:
        case 36:
        case 37:
          setMinutes(7);
          setHours(hours + 1);
          break;
        case 38:
        case 39:
          updateLedMask(maskAlmost, maskSizeAlmost);
          setMinutes(8);
          setHours(hours + 1);
          break;
        case 40:
        case 41:
        case 42:
          setMinutes(8);
          setHours(hours + 1);
          break;
        case 43:
        case 44:
          updateLedMask(maskAlmost, maskSizeAlmost);
          setMinutes(9);
          setHours(hours + 1);
          break;
        case 45:
        case 46:
        case 47:
          setMinutes(9);
          setHours(hours + 1);
          break;
        case 48:
        case 49:
          updateLedMask(maskAlmost, maskSizeAlmost);
          setMinutes(10);
          setHours(hours + 1);
          break;
        case 50:
        case 51:
        case 52:
          setMinutes(10);
          setHours(hours + 1);
          break;
        case 53:
        case 54:
          updateLedMask(maskAlmost, maskSizeAlmost);
          setMinutes(11);
          setHours(hours + 1);
          break;
        case 55:
        case 56:
        case 57:
          setMinutes(11);
          setHours(hours + 1);
          break;
        case 58:
        case 59:
          updateLedMask(maskAlmost, maskSizeAlmost);
          setMinutes(0);
          setHours(hours + 1);
          break;
      }
    }

  public:
    //Functions called by WLED

    /*
     * setup() is called once at boot. WiFi is not yet connected at this point.
     * You can use it to initialize variables, sensors or similar.
     */
    void setup() {}

    /*
     * connected() is called every time the WiFi is (re)connected
     * Use it to initialize network interfaces
     */
    void connected() {}

    /*
     * loop() is called continuously. Here you can check for events, read sensors, etc.
     * 
     * Tips:
     * 1. You can use "if (WLED_CONNECTED)" to check for a successful network connection.
     *    Additionally, "if (WLED_MQTT_CONNECTED)" is available to check for a connection to an MQTT broker.
     * 
     * 2. Try to avoid using the delay() function. NEVER use delays longer than 10 milliseconds.
     *    Instead, use a timer check as shown here.
     */
    void loop() {
      // if usermod is disabled or called during strip updating just exit
      // NOTE: on very long strips strip.isUpdating() may always return true so update accordingly
      if (!usermodActive || strip.isUpdating()) return;

      // do it every 5 seconds
      if (millis() - lastTime > 5000) {
        // update the display with new time
        updateDisplay(hourFormat12(localTime), minute(localTime));

        // remember last update
        lastTime = millis();
      }
    }

    /*
     * addToJsonInfo() can be used to add custom entries to the /json/info part of the JSON API.
     * Creating an "u" object allows you to add custom key/value pairs to the Info section of the WLED web UI.
     * Below it is shown how this could be used for e.g. a light sensor
     */
    /*
    void addToJsonInfo(JsonObject& root)
    {
    }
    */

    /*
     * addToJsonState() can be used to add custom entries to the /json/state part of the JSON API (state object).
     * Values in the state object may be modified by connected clients
     */
    void addToJsonState(JsonObject& root) {}

    /*
     * readFromJsonState() can be used to receive data clients send to the /json/state part of the JSON API (state object).
     * Values in the state object may be modified by connected clients
     */
    void readFromJsonState(JsonObject& root) {}

    /*
     * addToConfig() can be used to add custom persistent settings to the cfg.json file in the "um" (usermod) object.
     * It will be called by WLED when settings are actually saved (for example, LED settings are saved)
     * If you want to force saving the current state, use serializeConfig() in your loop().
     * 
     * CAUTION: serializeConfig() will initiate a filesystem write operation.
     * It might cause the LEDs to stutter and will cause flash wear if called too often.
     * Use it sparingly and always in the loop, never in network callbacks!
     * 
     * addToConfig() will make your settings editable through the Usermod Settings page automatically.
     *
     * Usermod Settings Overview:
     * - Numeric values are treated as floats in the browser.
     *   - If the numeric value entered into the browser contains a decimal point, it will be parsed as a C float
     *     before being returned to the Usermod.  The float data type has only 6-7 decimal digits of precision, and
     *     doubles are not supported, numbers will be rounded to the nearest float value when being parsed.
     *     The range accepted by the input field is +/- 1.175494351e-38 to +/- 3.402823466e+38.
     *   - If the numeric value entered into the browser doesn't contain a decimal point, it will be parsed as a
     *     C int32_t (range: -2147483648 to 2147483647) before being returned to the usermod.
     *     Overflows or underflows are truncated to the max/min value for an int32_t, and again truncated to the type
     *     used in the Usermod when reading the value from ArduinoJson.
     * - Pin values can be treated differently from an integer value by using the key name "pin"
     *   - "pin" can contain a single or array of integer values
     *   - On the Usermod Settings page there is simple checking for pin conflicts and warnings for special pins
     *     - Red color indicates a conflict.  Yellow color indicates a pin with a warning (e.g. an input-only pin)
     *   - Tip: use int8_t to store the pin value in the Usermod, so a -1 value (pin not set) can be used
     *
     * See usermod_v2_auto_save.h for an example that saves Flash space by reusing ArduinoJson key name strings
     * 
     * If you need a dedicated settings page with custom layout for your Usermod, that takes a lot more work.  
     * You will have to add the setting to the HTML, xml.cpp and set.cpp manually.
     * See the WLED Soundreactive fork (code and wiki) for reference.  https://github.com/atuline/WLED
     * 
     * I highly recommend checking out the basics of ArduinoJson serialization and deserialization in order to use custom settings!
     */
    void addToConfig(JsonObject& root) {
      JsonObject top = root.createNestedObject("UsermodDKWordClock");
      top["active"] = usermodActive;
      top["heartSymbol"] = heartEnabled;
    }

    /*
     * readFromConfig() can be used to read back the custom settings you added with addToConfig().
     * This is called by WLED when settings are loaded (currently this only happens immediately after boot, or after saving on the Usermod Settings page)
     * 
     * readFromConfig() is called BEFORE setup(). This means you can use your persistent values in setup() (e.g. pin assignments, buffer sizes),
     * but also that if you want to write persistent values to a dynamic buffer, you'd need to allocate it here instead of in setup.
     * If you don't know what that is, don't fret. It most likely doesn't affect your use case :)
     * 
     * Return true in case the config values returned from Usermod Settings were complete, or false if you'd like WLED to save your defaults to disk (so any missing values are editable in Usermod Settings)
     * 
     * getJsonValue() returns false if the value is missing, or copies the value into the variable provided and returns true if the value is present
     * The configComplete variable is true only if the "exampleUsermod" object and all values are present.  If any values are missing, WLED will know to call addToConfig() to save them
     * 
     * This function is guaranteed to be called on boot, but could also be called every time settings are updated
     */
    bool readFromConfig(JsonObject& root) {
      // default settings values could be set here (or below using the 3-argument getJsonValue()) instead of in the class definition or constructor
      // setting them inside readFromConfig() is slightly more robust, handling the rare but plausible use case of single value being missing after boot (e.g. if the cfg.json was manually edited and a value was removed)

      JsonObject top = root["UsermodDKWordClock"];

      bool configComplete = !top.isNull();

      configComplete &= getJsonValue(top["active"], usermodActive);
      configComplete &= getJsonValue(top["heartSymbol"], heartEnabled);

      return configComplete;
    }

    /*
     * handleOverlayDraw() is called just before every show() (LED strip update frame) after effects have set the colors.
     * Use this to blank out some LEDs or set them to a different color regardless of the set effect mode.
     * Commonly used for custom clocks (Cronixie, 7 segment)
     */
    void handleOverlayDraw() {
      // check if usermod is active
      if (usermodActive == true) {
        // loop over all leds
        for (int x = 0; x < maskSizeLeds; x++) {
          // check mask
          if (maskLedsOn[x] == 0) {
            // set pixel off
            strip.setPixelColor(x, RGBW32(0,0,0,0));
          }
        }

        if (heartEnabled) {
          strip.setPixelColor(heartPin, RGBW32(255,0,0,0)); // Making sure the heart is always "red"
        }
      }
    }

    /*
     * getId() allows you to optionally give your V2 usermod an unique ID (please define it in const.h!).
     * This could be used in the future for the system to determine whether your usermod is installed.
     */
    uint16_t getId() {
      return USERMOD_ID_WORDCLOCK;
    }

   //More methods can be added in the future, this example will then be extended.
   //Your usermod will remain compatible as it does not need to implement all methods from the Usermod base class!
};
