<h3 align=center> John Horton Conway's Game of Life PSP! </h3>
<br/>
This is the PSP (PlayStation Portable) version of Conway's game of life.

If you want to test this out, you can use the pre-binary/stable version from release section

### How to run?

- If you don't have a actual PSP (I've didn't test it on actual bare metal yet, then dw :>) you can run the .EBP file from release section on your emulator

- Or maybe you want to build the game by yourself, for building the game you need [_PSPDEV_](https://pspdev.github.io/quickstart.html) development kit. you can download the latest version form their repository

### Build

Be sure to do all of the instructions that you need to install pspdev development environment.

After that you can make a build directory and build the Game:
```
mkdir -p build
psp-cmake ..
make
```
If everything goes well, you will see a .EBP file.

### More

If you wanna change the source code you need to re-compile the source, there is a *comp* bash script that will compile the source code for you and make a copy of your game binary to a special place that you installed your game emulator. you can change that path to your custome emualtor 

Or you can make the game by go to build folder and do the ```make```

If you want to test this on actual device, you can follow the instruction from original pspdev website: https://pspdev.github.io/psplinkusb/

### Why?

There is multiple reasons that I made that, but in a nutshell it's Fun!.
