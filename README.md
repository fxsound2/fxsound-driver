# FxSound

FxSound is a digital audio program built for Windows PC's. The background processing, built on the highest-fidelity audio engine possible, acts as a sort of digital soundcard for your system. This means that your signals will have the cleanest possible passthrough when FxSound is active. There are active effects for shaping and boosting your sound's volume, timbre, and equalization included on top of this clean processing, allowing you to customize and enhance your sound.

This repository contains the source code for FxSound Audio Enhancer driver which is a Windows virtual audio driver based on https://github.com/uri247/wdk81/tree/master/Microsoft%20Virtual%20Audio%20Device%20Driver%20Sample

## General Information
* Website: https://www.fxsound.com
* Installer: https://download.fxsound.com/fxsoundlatest
* Source code: https://github.com/fxsound2/fxsound-app
* Issue tracker: https://github.com/fxsound2/fxsound-app/issues
* Forum: https://forum.fxsound.com
* [Donate to FxSound](https://www.paypal.com/donate/?hosted_button_id=JVNQGYXCQ2GPG)
  
## Build Instructions
### Prerequisites
* Install [Visual Studio 2022](https://visualstudio.microsoft.com/vs)
* Install [Windows WDK](https://learn.microsoft.com/en-us/windows-hardware/drivers/download-the-wdk)
  
### Build FxSound from Visual Studio
* Open [fxsound-driver/fxvad/fxvad.sln](https://github.com/fxsound2/fxsound-driver/blob/main/fxvad/fxvad.sln) in Visual Studio
* Build the required configuration
* The driver package files will be in fxvad/[Platform]/[Configration]/package directory

## How to contribute
We welcome anyone who wants to contribute to this project. For more details on how to contribute, follow [this contributing guideline](./CONTRIBUTING.md).

## License
[GPL v3.0](https://github.com/fxsound2/fxsound-driver/blob/main/LICENSE)

[MICROSOFT LIMITED PUBLIC LICENSE version 1.1](https://github.com/fxsound2/fxsound-driver/blob/dev/license.rtf)