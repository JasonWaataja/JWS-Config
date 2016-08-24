# JWS-Config
A graphical configuration tool for JWS

## Synopsis
JWS-Config is a graphical tool used to configure the command line program
[JWS](https://github.com/JasonWaataja/JWS). It does this by creating a
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
You can launch the program with the `jws-config` command. There should also be a
desktop entry in your system that you can use.

From the main interface, you can use the side buttons to add files and
directories as well as move and remove them.

For a summary of what each of the options do, consult the documentation for JWS.
This includes information about each option, what it does, and how to use it in
the configuration file.

You can view an image in its own window by double clicking on it or right
clicking and choosing "Open". From the image viewer, you can resize the image as
well as navigate the images with the buttons on the bottom or by right clicking
on the image. You can also go to the next image by clicking on the image and go
to the previous image with middle click.

You can edit a file by running `jws-config filename`.
