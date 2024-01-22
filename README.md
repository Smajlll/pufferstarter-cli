# PufferStarter-cli
An application written in C++, that will help you control your PufferPanel servers using your CLI. 

### Dependencies
- cURL
- A hosted PufferPanel instance

### Building instructions
Right  now, I don't have any scripts for building, but, you can build PufferStarter by running these commands:

#### Compiling now works only for linux, i don't know why, i will try to fix it in the next commits, sorry :(

``` bash
git clone https://github.com/Smajlll/pufferstarter-cli.git
cd pufferstarter-cli
mkdir build
cd build
cmake ..
cmake build
```
then for Linux you also need to write these commands:
```
chmod +x ./pufferstarter-cli
./pufferstarter-cli
```

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