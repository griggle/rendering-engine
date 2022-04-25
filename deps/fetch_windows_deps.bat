@echo off 

Rem Dependancy versions and links
set sdl2_version=2.0.20
set sdl2_dl_link=https://www.libsdl.org/release/SDL2-devel-%sdl2_version%-VC.zip


Rem Download SDL2 for visual studio

powershell.exe "curl %sdl2_dl_link% -o SDL2_temp.zip; Expand-Archive SDL2_temp.zip; Move-Item SDL2_temp/* ./; Remove-Item SDL2_temp; Move-Item SDL2-%sdl2_version% SDL2-vc; Remove-Item SDL2_temp.zip; Copy-Item cmake_configs/sdl2-config.cmake SDL2-vc/sdl2-config.cmake"
