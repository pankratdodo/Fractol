#!/bin/bash

sudo apt-get update

# Install X11 XShm extension
#sudo apt-get install --assume-yes libxext-dev
#sudo apt-get install  libbsd-dev

# Setup your OS
sudo git clone https://github.com/abouvier/minilibx
sudo mkdir /usr/X11
sudo mkdir /usr/X11/include
sudo mkdir /usr/X11/lib
sudo mkdir /usr/local/lib
cd minilibx
make
sudo cp mlx.h /usr/X11/include
sudo cp mlx.h /usr/local/include
sudo cp libmlx.a /usr/X11/lib
sudo cp libmlx.a /usr/local/lib
echo "Finished -- Give to your compilator these instructions :"
echo ""
echo "-L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11"
