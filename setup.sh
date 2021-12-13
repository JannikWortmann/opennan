#!/bin/sh

echo "Installing Dependencies now...\n"

sudo apt install -y libpcap-dev libev-dev libnl-3-dev libnl-genl-3-dev libnl-route-3-dev


echo "Building now...\n"

mkdir "build"
cd "build"
cmake ..
make