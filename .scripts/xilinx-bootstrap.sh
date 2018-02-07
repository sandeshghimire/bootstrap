#!/bin/sh 

curl https://storage.googleapis.com/git-repo-downloads/repo > repo
chmod a+x repo 
sudo mv repo /usr/local/bin


cd ~
mkdir -p workspace 
cd workspace


repo init -u git://github.com/Xilinx/yocto-manifests.git -b rel-v2017.4
repo sync

repo start rel-v2017.4 --all

cd ~
cd workspace

source setupsdk
MACHINE=zynqmp-generic bitbake petalinux-image
