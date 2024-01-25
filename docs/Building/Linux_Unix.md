# Building instructions for Linux
This document will guide you through the process of building PufferStarter on your Windows system.

### Prerequisites
This guide requires you to have sudo privileges on your user account (for installing necessary software), and also know how to navigate in the command line. Even though all the commands in this file ****are safe to run****, it's not recommended to copy and run code and/or commands from a random website you find on the internet. With this out of the way, we can continue.

### Building dependencies
- gcc
- g++
- cmake
- git

!> Make sure you have all of these programs installed, and in your PATH variable on your system before continuing.

## Building process
1) Automatic way
- Clone PufferStarters repository by running `git clone https://github.com/smajlll/pufferstarter-cli`
- Change your working directory to the cloned repo 'cd pufferstarter-cli'
- Run the automatic build file `bash ./build.sh`
- Your compiled executable is now present at `./pufferstarter_cli`
2) Manual way
- Clone PufferStarters repository by running `git clone https://github.com/smajlll/pufferstarter-cli`
- Change your working directory to the cloned repo 'cd pufferstarter-cli'
- Create a new folder for your build files, and cd into it `mkdir build && cd build`
- Generate CMake build files by running `cmake .."`
- Build the project by running `cmake --build .`
- Make the compiled file executable by running `chmod +x ./pufferstarter_cli`
- Your compiled executable is now present at this location `./pufferstartel_cli`

### And what next?
You can start using the program right away. But I recommend you look into the [Config file](../Configuration/configuration-file.md), so you can make your user experience better.
