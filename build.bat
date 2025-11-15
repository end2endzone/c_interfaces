@echo off
cd /d "%~dp0"
mkdir build 2>NUL
cd build
cmake ..
pause
