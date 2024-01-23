# Configuration File - PufferStarter Documentation
PufferStarter allows you to write a config file, so you don't have to write your IP, OAuth Secret and Client ID every time you start it. 

## Creating a config file
There are 3 ways you can create a config file:
1) By using the function to create the configuration file (recommended)
   - Start PufferStarter
   - At the Authentication Menu, select number 3 (create config file)
   - If the config file isn't present it will create it, if it is, it will ask you if you want to rewrite it.
   - The program will Quit
   - Your config file is now present at `~/.config/PufferStarter.conf if you are on Linux`, or `%USERPROFILE%\.pufferstarter\PufferStarter.conf`
2) By using the "Load my credentials from the config file" function
   - Start PufferStarter
   - At the Authentication Menu, select number 2 (Load my credentials from the config file)
   - If the config file isn't present it will create it, and then fall back to the manual authentication, if it is, but you have not specified anything in it, it will do the same thing.
   - Your config file is now present at `~/.config/PufferStarter.conf` if you are on Linux, or `%USERPROFILE%\.pufferstarter\PufferStarter.conf`
Both of these functions will create a configuration file with columns already created, the file will look something like this:
```
ip=""
id=""
secret=""
```
3) Manually creating the config file (not recommended)
Instructions for Windows:
   - Go into your User folder, you can get there by holding `Windows + R` together, and then typing `%USERPROFILE%` into the textbox and pressing enter.
   - Create a folder called `.pufferstarter` 
   - Go into the folder and create a file called `PufferStarter.conf` and paste in this:
   ```
   ip=""
   id=""
   secret=""
   ```
   - Save the file.
Instructions for Linux and macOS:
   - Open your terminal
   - Go into your home folder by typing `cd ~`
   - If it doesn't exist already, create a folder called `.config`
   - Go into the folder and create file called `PufferStarter.conf`
   - Open the file and paste this into it:
   ```
   ip=""
   id=""
   secret=""
   ```
   - Save the file

## Configuring the config file
After you create the config file by using one of these 3 methods, you can start configuring it. We will go after each of these 3 parameters.
1) `ip` parameter:
   - This parameter stores the IP of your PufferPanel server, it is the same address, you use to access PufferPanel in your browser, you do not need to include the `https://` or `http://`, but if you use some port to access PufferPanel, include that too.
   - Examples:
     1) `ip="panel.example.com:8080"`
     2) `ip="panel.example.org"`
2) `id` parameter:
   - This parameter stores your OAuth ClientID, you can generate that after you log into your PufferPanel, after you go to the `User` tab, in the `OAuth2 Credentials` section.
   - Example:
     1) `id="example"`
3) `secret` parameter:
   - This parameter stores your OAuth Secret, you can generate that after you log into your PufferPanel, after you go to the `User` tab, in the `OAuth2 Credentials` section. - BE ADVISED, you can only see the secret once, so write it somewhere before you close the PufferPanel tab.
   - Example:
     1) `secret=""example"` 

## What if I want to log in with another credentials, when using a config file?
It's pretty simple, and you have two ways of doing so:
1) By using the `Enter my credentials manually` function on the Authentication Menu
   - Start PufferStarter
   - On the Authentication Menu select the second option
   - You can now enter your credentials manually.
2) By using the `Change your credentials` function on the Main Menu
   - Return to the Main menu, if you aren't in it
   - Select the first option
   - You can now reauthenticate and enter your credentials manually

   ****This won't affect your config file.****

## Future of config files
I hope that in the future, PufferStarter will have multiple config files, from witch you could choose after you start it. 

## Closing thoughts 
I hope this pseudo-documentation helped you, a real documentation website is in the works, so please wait. I also hope the config file made your UX with PufferStarter at least a little bit better :).
- Made with <3, by Smajl
 
     

