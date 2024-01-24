# PufferStarter-cli
An application written in C++, that will help you control your PufferPanel servers using your CLI. 

### Dependencies
- cURL
- A hosted PufferPanel instance

### Building instructions
You can use the scripts in the root of the projects called `build.sh` and `build.ps1` respectively

Manual Building:

Linux and other unix systems
``` bash
git clone https://github.com/Smajlll/pufferstarter-cli.git
cd pufferstarter-cli
mkdir build
cd build
cmake ..
cmake --build .
chmod +x ./pufferstarter-cli
./pufferstarter-cli
```

Windows:
``` bash
git clone https://github.com/Smajlll/pufferstarter-cli.git
cd pufferstarter-cli
mkdir build
cd build
cmake ..
cmake --build .
```
The .exe will be in the newly created Debug folder.

### What works? And what doesn't?
Right now, this works:
- Basic auth
  - The app will get, and send the request to the server, it parses it, and stores the raw ID in a variable
- Listing the server information (id, name, port, status)
- Changing the status of the server 
- Listing all the servers


What I hope to implement in the future?:
- List all the server available to you, as well as its id.
- Saving your Client ID and Secret somewhere in a config file

<img src="https://forthebadge.com/images/featured/featured-made-with-crayons.svg" alt="Made With Crayons" width="300"/>
<img src="https://forthebadge.com/images/badges/made-with-c-plus-plus.svg" alt="Made with C++" width="175"/>
<img src="https://forthebadge.com/images/featured/featured-built-with-love.svg" alt="drawing" width="175"/>