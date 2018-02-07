#!/bin/sh 

echo "Setting up system,this will take a long time"
echo "depending on our pc and internet connection"
echo "installing dependencies "
sleep 1
wget -q -O - https://pkg.jenkins.io/debian/jenkins-ci.org.key | sudo apt-key add -
sudo sh -c 'echo deb http://pkg.jenkins.io/debian-stable binary/ > /etc/apt/sources.list.d/jenkins.list'
sudo apt-get update
sudo dpkg --add-architecture i386
sudo apt install uuid  zlib1g:i386 xvfb libssl-dev tftp-server  ncurses-dev:i386 libstdc++6:i386 libselinux1:i386 lib32ncurses5-dev lib32ncurses5 lib32ncursesw5  openssh-server apt-get install net-tools  net-tools  git  vnc*  clang   samba  smba  samba  vim  gcc-arm-linux-gnueabi g++-arm-linux-gnueabi   uuid gcc-arm-linux-gnueabihf g++-arm-linux-gnueabihf  libselinux1:i386  jenkins  libc6-armel-cross libc6-dev-armel-cross  binutils-arm-linux-gnueabi  libncurses5-dev  autoconf automake libtool libexpat1-dev  libncurses5-dev bison flex patch curl cvs texinfo git bc  build-essential subversion gawk python-dev gperf unzip  pkg-config wget help2man  sed wget cvs subversion git-core coreutils unzip texi2html texinfo libsdl1.2-dev docbook-utils gawk python-pysqlite2 diffstat help2man make gcc build-essential g++ desktop-file-utils chrpath libgl1-mesa-dev libglu1-mesa-dev mercurial autoconf automake groff libtool xterm gawk wget git-core diffstat unzip texinfo build-essential chrpath socat libsdl1.2-dev xterm make xsltproc docbook-utils fop dblatex xmlto autoconf automake libtool libglib2.0-dev python-gtk2 bsdmainutils screen -y
sudo dpkg-reconfigure dash
git config --global user.name "Sandesh J. Ghimire"
git config --global user.email "sandesh@aeva.ai"
hostnamectl set-hostname 'embedded-linux-build-server'

sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib build-essential chrpath socat cpio python python3 python3-pip python3-pexpect  xz-utils debianutils iputils-ping libsdl1.2-dev xterm


curl -k https://storage.googleapis.com/git-repo-downloads/repo > repo
chmod a+x repo
sudo mv repo /usr/local/bin 