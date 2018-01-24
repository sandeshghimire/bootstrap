#!/bin/sh 

echo "Setting up system,this will take a long time"
echo "depending on our pc and internet connection"


echo "installing dependencies "
sudo apt-get install autoconf automake libtool libexpat1-dev  libncurses5-dev bison flex patch curl cvs texinfo git bc  build-essential subversion gawk python-dev gperf unzip  pkg-config wget help2man  sed wget cvs subversion git-core coreutils unzip texi2html texinfo libsdl1.2-dev docbook-utils gawk python-pysqlite2 diffstat help2man make gcc build-essential g++ desktop-file-utils chrpath libgl1-mesa-dev libglu1-mesa-dev mercurial autoconf automake groff libtool xterm gawk wget git-core diffstat unzip texinfo build-essential chrpath socat libsdl1.2-dev xterm make xsltproc docbook-utils fop dblatex xmlto autoconf automake libtool libglib2.0-dev python-gtk2 bsdmainutils screen


setup host name
hostnamectl set-hostname 'bowers-wilkins-yocto-dev'
wget -q -O - https://pkg.jenkins.io/debian/jenkins-ci.org.key | sudo apt-key add -
sudo sh -c 'echo deb http://pkg.jenkins.io/debian-stable binary/ > /etc/apt/sources.list.d/jenkins.list'
sudo apt-get update
sudo apt-get install jenkins


sudo dpkg --add-architecture i386
sudo apt-get install libselinux1:i386
sudo dpkg-reconfigure dash
sudo apt-get install ncurses-dev:i386 libstdc++6:i386 libselinux1:i386 lib32ncurses5-dev lib32ncurses5 lib32ncursesw5