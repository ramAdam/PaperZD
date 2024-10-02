# PaperZD UE5 Plugin Version 2.0.5 for Linux

This repository contains the PaperZD plugin for Unreal Engine 5.1.2. 
For questions, join our [Discord Community](https://discord.gg/VzuJRas)

## Compiling for Linux (Tested on Arch)

To compile the plugin for Linux, you can use the provided shell script. Follow these steps:

1. Open a terminal window.

2. Navigate to the directory containing the shell script.

3. Make the script executable:
   ```bash
   chmod +x build_plugin.sh

4. Make sure to replace the placeholders /path/to/Linux_Unreal_Engine_5.2.1/Engine, /path/to/PaperZD/PaperZD.uplugin,
   and /path/to/PaperZD/build with your actual paths in build_plugin.sh

   Note: This script assumes you have the necessary permissions and dependencies installed to compile and build the plugin.

5. The script compiles and creates build folder with all necessary file

6. Rename the build folder to PaperZD and move it to plugin/MarketPlace folder in your engine (create the directory if doesn't exist)

## Credits
This plugin is based on the PaperZD plugin available on the Unreal Engine Marketplace. For more information and additional features, please visit the official marketplace page. [PaperZD](https://www.unrealengine.com/marketplace/en-US/product/paperzd)
