# Non-Interactive mode
From version 3.0.0 PufferStarter also supports non-interactive mode by using options to control PufferStarter. 

!> Usage of non-interactive mode REQUIRES you to have a config file. See [Configuration File](../Configuration/configuration-file.md) documentation for more information

### Available options
```
Usage:
  pufferstarter-cli [OPTION...]

 Generic options options:
  -h, --help         Print the help message
  -i, --interactive  Start the interactive mode

 Configuration options options:
      --id <Server ID>  Set the Server ID (length: 8)
  -r, --createConfig    Creates the config at the default location

 Functions options:
  -s, --setStatus <start, stop, kill>
                                Set the status of the server
                                Requires --id
  -l, --listAll                 Lists all servers and IDs
  -g, --getInfo                 Gets the info about a server
                                Requires --id

```

### Explaining time!
- `-h, --help` option
  - Displays the help dialog, as seen above.
- `-i, --interactive` option
  - Starts PufferStarter interactively, see [Starting PufferStarter](../Basics/starting.md)
- `--id` option
  - Sets the ServerID. This option cannot be the only option set while starting PufferStarter.
- `-r, --createConfig` option
  - This option will create the config file at `~/.config/PufferStarter.conf if you are on Linux`, or `%USERPROFILE%\.pufferstarter\PufferStarter.conf`. See also [Configuring PufferStarter](../Configuration/configuration-file.md).
- `-l, --listAll` option
    - Lists all server names and IDs
- `-g, --getInfo` option
  - Gets information about the specified server
  - Must be run with `--id` set
- `-s, --setStatus` option
  - The only valid arguments for this option is `off`, `on` and `kill`
  - This option will set the server status to the specified status
    - off - Stop the server
    - on - Start the server
    - kill - Kill the server
  - Must be run with `--id` set


### Limitations
1) Users cannot specify an ID, Secret and IP manually, these parameters are always read from the Config File.
2) Killing a server doesn't require any additional confirmation. The server will just be killed.
3) When changing the status of the server, current status will not be shown.
4) You cannot run more than one function each time you run PufferStarter

- Limitation 1 will be fixed in the future.
- Limitation 2 won't be fixed, as the usage of non-interactive mode is planned to be used as a backend for GUI interface.
- Limitations 3 and 4 are not planned to be fixed/can't be fixed.