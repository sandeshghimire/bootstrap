#include <fcntl.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>

#include <unistd.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>

#ifndef I2C_EVAI2C_HPP
#define I2C_EVAI2C_HPP

class CoreI2C
{
 public:
    CoreI2C();
    CoreI2C(int address);
    CoreI2C(std::string deviceFile, int address);
    ~CoreI2C();

    bool fail();

    int setAddress(int address);
    int getAddress();
    const char *getErrorMessage();
    int setDevicefile(std::string filename);

    int receive(unsigned char *rxBuf, int length);
    int receive(unsigned char registerAddress, unsigned char *rxBuf, int length);

    int send(unsigned char *txBuf, int length);
    int send(unsigned char registerAddress, unsigned char *txBuf, int length);
    int send(unsigned char value);

 private:
    bool _error_flag;
    int _slave_address;
    std::string _devicefile;
    std::string _errorMessage;
    int _fd;

 private:
    int _errorMsg(std::string message);
    int _open_fd();
    void _close_fd();
    void _init(std::string deviceFile, int address);
    int _stringToNumber(std::string str);
    std::string _numberToString(int num);
    int _hexstringToNumber(std::string str);
};

#endif /*end of I2C_EVAI2C_HPP*/