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

## Updating via the Cloud

In addition to updating your firmware locally, you can also perform updates via the cloud, providing a convenient alternative method for keeping your LED setup up-to-date. This process involves compiling the firmware build on your computer and then uploading the new `firmware.bin` file through the web interface. Follow these steps to update your firmware via the cloud:

1. **Compile Firmware Locally:** Begin by compiling the firmware build on your local computer using the same instructions as provided earlier for updating via PlatformIO. Make sure to follow steps 1 through 4 mentioned in the "Updating ESP8266 Firmware with PlatformIO" section.

2. **Generate Firmware Binary:** Once the firmware is successfully compiled, locate the generated `firmware.bin` binary file. This file contains the updated firmware that you will upload to the cloud.

3. **Access Web Interface:** Open a web browser and navigate to the web interface of your ESP8266 board. This is typically done by entering the IP address of the board in the browser's address bar.

4. **Initiate Firmware Update:** Within the web interface, navigate to the "Info" section or a similarly named menu option. Look for an option labeled "Update WLED" or a similar term that indicates firmware updates.

5. **Upload Firmware:** Click on the "Update WLED" option, and a file upload dialog will appear. Select the previously generated `firmware.bin` file from your local computer and confirm the upload. The web interface will handle the rest, updating the firmware on your ESP8266 board.

6. **Completion and Restart:** Once the upload process is complete, the ESP8266 board will automatically restart with the newly updated firmware. You can now enjoy the latest features and enhancements introduced by this custom WLED fork.

We encourage you to delve into the assorted modifications and enhancements that we've implemented in this fork. Should inquiries arise or challenges manifest, please consult the documentation provided both here and in the specific directories. Happy exploration and LED experimentation!

## License

This custom WLED fork is released under the same license as the original WLED project. Refer to the license documentation for comprehensive information.
