#!/bin/bash

UE_ENGINE_PATH="/path/to/Linux_Unreal_Engine_5.2.1/Engine"
PLUGIN_PATH="/path/to/PaperZD/PaperZD.uplugin"
PACKAGE_PATH="/path/to/PaperZD/build" # This is where the plugin will be built, make the directory if it doesn't exist

${UE_ENGINE_PATH}/Build/BatchFiles/RunUAT.sh BuildPlugin -plugin=${PLUGIN_PATH} -package=${PACKAGE_PATH} -Rocket -TargetPlatforms=Linux -PackageDir=${PACKAGE_PATH}