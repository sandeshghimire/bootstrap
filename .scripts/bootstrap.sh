#!/bin/sh 

echo "Setting up system,this will take a long time"
echo "depending on our pc and internet connection"

echo "installing dependencies "
sudo apt-get install autoconf automake libtool libexpat1-dev  libncurses5-dev bison flex patch curl cvs texinfo git bc  build-essential subversion gawk python-dev gperf unzip  pkg-config wget help2man  sed wget cvs subversion git-core coreutils unzip texi2html texinfo libsdl1.2-dev docbook-utils gawk python-pysqlite2 diffstat help2man make gcc build-essential g++ desktop-file-utils chrpath libgl1-mesa-dev libglu1-mesa-dev mercurial autoconf automake groff libtool xterm gawk wget git-core diffstat unzip texinfo build-essential chrpath socat libsdl1.2-dev xterm make xsltproc docbook-utils fop dblatex xmlto autoconf automake libtool libglib2.0-dev python-gtk2 bsdmainutils screen
setup host name

wget -q -O - https://pkg.jenkins.io/debian/jenkins-ci.org.key | sudo apt-key add -
sudo sh -c 'echo deb http://pkg.jenkins.io/debian-stable binary/ > /etc/apt/sources.list.d/jenkins.list'
sudo apt-get update
sudo apt-get install jenkins

sudo apt-get install libc6-armel-cross libc6-dev-armel-cross
sudo apt-get install binutils-arm-linux-gnueabi
sudo apt-get install libncurses5-dev

sudo dpkg --add-architecture i386
sudo apt-get install libselinux1:i386

sudo apt-get install gcc-arm-linux-gnueabi
sudo apt-get install g++-arm-linux-gnueabi

sudo apt-get install gcc-arm-linux-gnueabihf
sudo apt-get install g++-arm-linux-gnueabihf



sudo apt-get install ncurses-dev:i386 libstdc++6:i386 libselinux1:i386 lib32ncurses5-dev lib32ncurses5 lib32ncursesw5
sudo apt-get install openssh-server apt-get install net-tools  net-tools  git  vnc*  clang   samba  smba  samba  vim 


sudo dpkg-reconfigure dash
 git config --global user.name "Sandesh J. Ghimire"
 git config --global user.email "sandesh@aeva.ai"

sudo apt install uuid
hostname=uuid 
hostnamectl set-hostname 'embedded-linux-build-server'-$(hostname)