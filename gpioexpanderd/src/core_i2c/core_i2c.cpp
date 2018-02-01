#include "core_i2c.hpp"

#define DEFAULTDEVICE "/dev/i2c-1"

CoreI2C::CoreI2C()
{
    _init(DEFAULTDEVICE, -1);
}

CoreI2C::CoreI2C(int address)
{
    _init(DEFAULTDEVICE, address);
}

CoreI2C::CoreI2C(std::string deviceFile, int address)
{
    _init(deviceFile, address);
}

CoreI2C::~CoreI2C()
{
    _close_fd();
}

void CoreI2C::_init(std::string deviceFile, int address)
{
    _devicefile = deviceFile;
    _slave_address = address;
    _error_flag = false;
    _fd = 0;
}

int CoreI2C::_errorMsg(std::string message)
{
    _errorMessage = message;
    std::cout << message << std::endl;
    _error_flag = true;
    _close_fd();
    return -1;
}

void CoreI2C::_close_fd()
{
    if (_fd)
    {
        close(_fd);
        _fd = 0;
    }
}

int CoreI2C::_open_fd()
{
    _error_flag = false;

    if (_fd)
    {
        _close_fd();
        _fd = 0;
    }

    if (_slave_address == -1)
        return _errorMsg("I2C::ERROR slave address is not set\n");

    if ((_fd = open(_devicefile.c_str(), O_RDWR)) < 0)
        return _errorMsg("I2C::ERROR opening: " + _devicefile + "\n");

    if (ioctl(_fd, I2C_SLAVE, _slave_address) < 0)
        return _errorMsg("I2C::ERROR address: " + _numberToString(_slave_address) + "\n");

    return 0;
}

bool CoreI2C::fail()
{
    return _error_flag;
}

int CoreI2C::setAddress(int address)
{
    _slave_address = address;
    return _open_fd();
}

int CoreI2C::getAddress()
{
    return _slave_address;
}

const char *CoreI2C::getErrorMessage()
{
    return _errorMessage.c_str();
}

int CoreI2C::setDevicefile(std::string filename)
{
    _devicefile = filename;
    return _open_fd();
}

int CoreI2C::receive(unsigned char *rxBuf, int length)
{

    if (rxBuf == 0)
        return _errorMsg("I2C::Receive  a null TxBuf pointer.\n");
    if (length < 1)
        return _errorMsg("I2C::Receive an invalid buffer length.\n");

    if (!_fd)
        if (_open_fd() == -1)
            return -1;

    _error_flag = false;

    if (read(_fd, rxBuf, length) != length)
        return _errorMsg("I2C::Read error! Address: " + _numberToString(_slave_address) + " dev file: " + _devicefile + "\n");

    return 1;
}

int CoreI2C::receive(unsigned char registerAddress, unsigned char *rxBuf, int length)
{

    if (rxBuf == 0)
        return _errorMsg("I2C::Receive null TxBuf pointer.\n");
    if (length < 1)
        return _errorMsg("I2C::Receive invalid buffer length.\n");

    if (!_fd)
        if (_open_fd() == -1)
            return -1;

    _error_flag = false;

    if (write(_fd, &registerAddress, 1) != 1)
        return _errorMsg("i2c write error!\n");

    if (read(_fd, rxBuf, length) != length)
        return _errorMsg("I2C::Read error! Address: " + _numberToString(_slave_address) + " dev file: " + _devicefile + "\n");

    return 1;
}

int CoreI2C::send(unsigned char *txBuf, int length)
{

    if (txBuf == 0)
        return _errorMsg("I2C::Received null txBuf pointer.\n");
    if (length < 1)
        return _errorMsg("I2C::Received invalid buffer length.\n");

    if (!_fd)
        if (_open_fd() == -1)
            return -1;

    _error_flag = false;

    if (write(_fd, txBuf, length) != length)
        return _errorMsg("I2C::Write error!\n");

    return 1;
}

int CoreI2C::send(unsigned char registerAddress, unsigned char *txBuf, int length)
{
    int i;
    unsigned char data[length + 1];
    data[0] = registerAddress;

    for (i = 0; i < length; i++)
    {
        data[i + 1] = txBuf[i];
    }

    if (txBuf == 0)
        return _errorMsg("I2C::Received null txBuf pointer.\n");
    if (length < 1)
        return _errorMsg("I2C::Received invalid buffer length.\n");

    if (!_fd)
        if (_open_fd() == -1)
            return -1;

    _error_flag = false;

    if (write(_fd, data, length + 1) != length + 1)
        return _errorMsg("I2C::Write error!\n");

    return 1;
}

int CoreI2C::send(unsigned char value)
{

    if (!_fd)
        if (_open_fd() == -1)
            return -1;

    _error_flag = false;

    if (write(_fd, &value, 1) != 1)
        return _errorMsg("I2C::Write error!\n");

    return 1;
}
int CoreI2C::_stringToNumber(std::string str)
{
    std::stringstream strin;
    int var;

    strin << str;
    strin >> var;

    return var;
}
std::string CoreI2C::_numberToString(int num)
{
    std::ostringstream strout;
    std::string str;

    strout << num;
    str = strout.str();

    return str;
}
int CoreI2C::_hexstringToNumber(std::string str)
{
    std::stringstream strin;
    int var;

    strin << std::hex << str;
    strin >> var;

    return var;
}
