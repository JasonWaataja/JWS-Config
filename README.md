# JWS-Config
A graphical configuration tool for JWS

## About
JWS-Config is a graphical tool used to configure the command line program JWS.
It does this by creating a configuration file to be used by JWS and is usually
stored in ~/.jws and read by JWS. This was created so that using JWS would be
easy and so that having many wallpapers would be easy to manage and sort.

## Installation
The main dependency is GTK+. On Arch Linux, install `base-devel`, `gtk3`, and
`feh`. On Ubuntu, try `build-essential`, `libgtk-3-dev`, `autotools-dev`, and
`autoconf`. I don't know exactly what the should be on Ubuntu or any other
platform so let me know and I'll add some.

Once you have the dependencies, you should be able to build it like a normal
autotools project. Run `cd JWS-Config`, `./autogeh.sh`, `./configure`, `make`,
and `make install`. You might need sudo for the last one.

##Usage
As of yet, there is no desktop entry as I am currently waiting on an icon. In
the meantime, create your own and launch the program with the `jws-config`
command which you should be able to do from the command line.

You can easily add files and directories, remove items, and sort them from the
main interface. To view an image in the image viewer, double click on it. From
here, you can use the buttons to navigate or click on the image to go forwards
and use middle click to go backwards.
