rmdir -r .\build
mkdir build
cd build
cmake ..
cmake --build .
cd Debug
echo "Your file is in this folder named 'pufferstarter_cli.exe'"