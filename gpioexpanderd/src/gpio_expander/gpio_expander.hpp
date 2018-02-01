//
// Created by Sandesh Ghimire on 6/6/17.
//

#ifndef I2C_GpioExpander_HPP
#define I2C_GpioExpander_HPP

#include "../core_i2c/core_i2c.hpp"
class GpioExpander
{
 public:
    GpioExpander();
    virtual ~GpioExpander();

 public:
    unsigned char getPause() const;
    void setPause(unsigned char pause);
    unsigned char getPlay() const;
    void setPlay(unsigned char play);
    unsigned char getMute() const;
    void setMute(unsigned char mute);
    unsigned char getVolumeUp() const;
    void setVolumeUp(unsigned char volumeUp);
    unsigned char getVolumeDown() const;
    void setVolumeDown(unsigned char volumeDown);

 public:
    void playPauseAction();
    void muteUnmuteAction();
    void volumeUpAction();
    void volumeDownAction();
    void FaultAction();

 private:
    unsigned char _volumeUp;
    unsigned char _volumeDown;
    unsigned char _pause;
    unsigned char _play;
    unsigned char _mute;
};

#endif //I2C_GpioExpander_HPP
