//
// Created by Sandesh Ghimire on 6/6/17.
//

#include "gpio_expander.hpp"

GpioExpander::GpioExpander()
{

}
GpioExpander::~GpioExpander()
{

}
unsigned char GpioExpander::getPause() const
{
    return _pause;
}
void GpioExpander::setPause(unsigned char pause)
{
    GpioExpander::_pause = pause;
}
unsigned char GpioExpander::getPlay() const
{
    return _play;
}
void GpioExpander::setPlay(unsigned char play)
{
    GpioExpander::_play = play;
}
unsigned char GpioExpander::getMute() const
{
    return _mute;
}
void GpioExpander::setMute(unsigned char mute)
{
    GpioExpander::_mute = mute;
}
unsigned char GpioExpander::getVolumeUp() const
{
    return _volumeUp;
}
void GpioExpander::setVolumeUp(unsigned char volumeUp)
{
    GpioExpander::_volumeUp = volumeUp;
}
unsigned char GpioExpander::getVolumeDown() const
{
    return _volumeDown;
}
void GpioExpander::setVolumeDown(unsigned char volumeDown)
{
    GpioExpander::_volumeDown = volumeDown;
}

void GpioExpander::playPauseAction()
{
    system("/usr/share/gpioexpanderd/play_pause.sh");
}
void GpioExpander::muteUnmuteAction()
{
    system("/usr/share/gpioexpanderd/mute.sh");
}
void GpioExpander::volumeUpAction()
{
    system("/usr/share/gpioexpanderd/up.sh");
}
void GpioExpander::volumeDownAction()
{
    system("/usr/share/gpioexpanderd/down.sh");
}

void GpioExpander::FaultAction()
{

}
