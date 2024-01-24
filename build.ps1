Remove-Item -r .\build
mkdir build
Set-Location build
cmake .. -g "MinGW Makefiles"
cmake --build .
Set-Location Debug
Write-Output "Your file is in this folder named 'pufferstarter_cli.exe'"