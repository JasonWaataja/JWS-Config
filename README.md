# JWS-Config
A graphical configuration tool for JWS

## Synopsis
JWS-Config is a graphical tool used to configure the command line program
[JWS](https://github.com/JasonWaataja/JWS).  It does this by creating a
configuration file to be used by JWS which is usually stored in ~/.jws and read
by JWS. This was created so that using JWS would be easy and so that having many
wallpapers would be easy to manage and sort.

## Installation
The main dependency is GTK+. On Arch Linux, install `base-devel`, `gtk3`, and
`feh`. On Ubuntu, try `build-essential`, `libgtk-3-dev`, `autotools-dev`, and
`autoconf`. I don't know exactly what they should be on Ubuntu or any other
platform so correct me if I'm wrong.

Once you have the dependencies, you should be able to build it like a normal
autotools project. Navigate into the directory containing JWS-Config and run
`./autogeh.sh`, `./configure`, `make`, and `make install`. You might need sudo
for the last one.

## Usage
As of yet, there is no desktop entry as I am currently waiting on an icon. In
the meantime, create your own and launch the program with the `jws-config`
command which you should be able to do from the command line.

From the main interface, you can use the side buttons to add files and
directories as well as move and remove them.

You can view an image on its own window by double clicking on or right clicking
and choosing "Open". From the image viewer, you can resize the image as well as
navigate the images with the buttons on the bottom or by right clicking on the
image. You can also go to the next image by clicking on the image and go to the
previous image with middle click.

Hitting apply or "Save" writes the current configuration to ~/.jws. It writes to
this file regardless of whether or not you opened a different file. You can save
to an arbitrary file using "Save as" from the File menu.
