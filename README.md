





# CSE165-LabTools

Tools used for generating lab structure and grading labs for CSE165 at UC Merced. This project started as a simple bash script to generate my lab folders, but quickly evolved into a program intended for not only building the lab structure, but also grading the labs to improve demo times. 

## Features
 - Auto generate lab folder structure per the professor's requirements
 - Grade labs based on user-defined test cases (Incoming)

## Download
Sorry about the zipped tar.gz, GitHub automatically zips up all artifacts on download
[![latest-dev](https://github.com/CybrNight/CSE165-LabTools/actions/workflows/latest_dev.yml/badge.svg)](https://github.com/CybrNight/CSE165-LabTools/actions/workflows/latest.yml)
| Platform      |Releases|
| ----------- |--|
| Linux      |[Latest-Dev](https://nightly.link/CybrNight/CSE165-LabTools/workflows/bleeding_edge/master/LabTools-Ubuntu.zip) ◦ Stable (*coming soon*) |
| Mac         |[Latest-Dev](https://nightly.link/CybrNight/CSE165-LabTools/workflows/bleeding_edge/master/LabTools-Mac.zip) ◦ Stable (*coming soon*) |

## Supported Platforms
- Ubuntu
	- Other Debian based distros should work since I only use the standard C/C++ libraries
	- Non-Debian distros like Arch should also be compatible for the same reason
- MacOS 10.15 Catalina or higher (blame Apple not me)
- Sorry Windows users, but Microsoft makes things difficult

## Usage

### Quick Generate Lab Folders
If a lab number and question count is passed on the command line like so: `./LabTools 6 6` then it will generate the folder structure in the current directory automatically without a template file. As a safety measure against data loss, if a lab folder with the name `Lab#` already exists the directory exists nothing happens.
The example will generate the following structure in the directory from where the program is run:
```
Lab6
├─ 1/
├─ 2/
├─ 3/
├─ 4/
├─ 5/
├─ 6/
```
### Normal Operations
- Running from the command line/GUI with no arguments will open the main program menu

### Lab Grader (WIP)
This feature is not currently finished. Will not be supported on Windows. 

## Building

### Install Required Packages
#### Debian Based Distros
```bash
sudo apt install build-essential
sudo apt install cmake
```
#### MacOS 10.15 and higher

 - Download latest release of XCode
 - Download latest [CMake version for MacOS](https://cmake.org/install/)

### Building With CMake
```bash
git clone https://github.com/CybrNight/CSE165-LabTools.git
cd CSE165-LabTools
cmake .
cmake --build . --config Release
```
