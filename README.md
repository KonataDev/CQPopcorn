## CQPopcorn
A command line tool be able to loading a coolq (or compatible) extension, cross platform.

## How it works
`cqp.dll` (this project) is not a dll library but a general exe file, there's no magic.  
Interestly, it's a exe file with dll exports. You can execute it directly in the prompt.

## Usage
```bash
# Load and run the extension directly.
> cqp.dll -f app.dll

# Load and run the extension with a websocket connection.
> cqp.dll -f app.dll -c ws://localhost:8000

# Load and run the extension with stdin/out (slient).
> cqp.dll -f app.dll -c std

# For more command please refer the help messages.
```

## LICENSE
Licensed under MIT with ❤.
