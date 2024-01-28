# PufferStarter-cli
An application written in C++, that will help you control your PufferPanel servers using your CLI. 


### Dependencies
- cURL
- A hosted PufferPanel instance

### Building instructions

Check the [Windows Instructions](https://docs.smoliicek.xyz/#/Building/WIndows) & [Linux Instructions](https://docs.smoliicek.xyz/#/Building/Linux_Unix)

### What works? And what doesn't?
Right now, this works:
- Basic auth
  - The app will get, and send the request to the server, it parses it, and stores the raw ID in a variable
- Listing the server information (id, name, port, status)
- Changing the status of the server 
- Listing all the servers

Also, check the [Feature tour - Interactive mode](https://docs.smoliicek.xyz/#/Basics/FeatureTourInteractive) & [Feature tour - Non-Interactive mode](https://docs.smoliicek.xyz/#/Basics/featuretournoint)


<img src="https://forthebadge.com/images/featured/featured-made-with-crayons.svg" alt="Made With Crayons" width="300"/>
<img src="https://forthebadge.com/images/badges/made-with-c-plus-plus.svg" alt="Made with C++" width="175"/>
<img src="https://forthebadge.com/images/featured/featured-built-with-love.svg" alt="drawing" width="175"/>