# WLED Word Clock edition

Welcome to our custom fork of WLED! This repository represents a modified version of the original WLED project, tailored to address specific needs and enhancements. If you're searching for the original README, you can locate it [here](WLED.md).

## Custom Usermod: Word Clock Usermod

One of the unique features of our fork is the custom usermod "usermod_v2_lubro_word_clock." This usermod can be found in the `usermods/usermod_v2_lubro_word_clock` directory. It introduces an enchanting word clock functionality to your LED setup, transforming your lights into a captivating and functional time display.

To utilize this usermod, simply follow the provided instructions in the directory. Comprehensive details on integrating and configuring the word clock usermod seamlessly into your LED project are available.

## Updating ESP8266 Firmware with PlatformIO

If you're utilizing an ESP8266 board and require a firmware update, follow these steps using Visual Studio Code and the PlatformIO extension:

1. **USB-C Connection:** To initiate the firmware update process, establish a connection between your ESP8266 board and your computer using a USB-C cable.

2. **Enter Firmware Update Mode:** Place your ESP8266 board into firmware update mode. This typically entails holding down a designated button or pin while powering up the board. Consult your board's documentation for precise guidelines.

3. **Visual Studio Code and PlatformIO:** Open your project in Visual Studio Code and make sure you have the PlatformIO extension installed. PlatformIO simplifies the firmware update process.

4. **Select Board and Port:** Using the PlatformIO status bar at the bottom, select your ESP8266 board model and the appropriate port.

5. **Upload Firmware:** With your ESP8266 in firmware update mode, press the PlatformIO "Upload" button in the toolbar. PlatformIO will compile the firmware and flash it onto the ESP8266.

6. **Complete Update:** Following the successful firmware update, your ESP8266 board will restart. At this point, you can begin enjoying the enhanced features presented by this custom WLED fork.

We encourage you to delve into the assorted modifications and enhancements that we've implemented in this fork. Should inquiries arise or challenges manifest, please consult the documentation provided both here and in the specific directories. Happy exploration and LED experimentation!

## License

This custom WLED fork is released under the same license as the original WLED project. Refer to the license documentation for comprehensive information.
