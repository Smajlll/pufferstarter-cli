# PufferStarter-cli
An application written in C++, that will help you control your PufferPanel servers using your CLI. 

### Dependencies
- cURL
- A hosted PufferPanel instance

### Building instructions
I will provide build instructions, after I bring the program to some functioning state.

### What works? And what doesn't?
Right now, this works:
- Basic auth
  - The app will get, and send the request to the server, it doesn't parse it or anything, just gets the full JSON returned and stores it in a variable

What will work?:
  - The program will parse the JSON to get the raw token and use it in its requests
    - With that, changing the status (shutting down, restarting, starting) of the servers, and getting the information about them will also be implemented.

What I hope to implement in the future?:
- List all the server available to you, as well as its id.
- Saving your Client ID and Secret somewhere in a config file

[![forthebadge](https://forthebadge.com/images/featured/featured-made-with-crayons.svg)](https://forthebadge.com)