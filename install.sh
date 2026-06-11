#!/bin/bash
echo "Updating system & installing system dependencies"

if [ -f /etc/debian_version ]; then
    sudo apt update && sudo apt install -y build-essential git libasound2-dev mesa-common-dev libx11-dev libxrandr-dev libxi-dev xorg-dev libgl1-mesa-dev libglu1-mesa-dev
elif [ -f /etc/fedora-release ]; then
    sudo dnf groupinstall -y "Development Tools"
    sudo dnf install -y git alsa-lib-devel mesa-libGL-devel libX11-devel libXrandr-devel libXi-devel libXcursor-devel libXinerama-devel
elif [ -f /etc/arch-release ]; then
    sudo pacman -S --noconfirm base-devel git raylib
fi

mkdir ./build
make
