#include <iostream>
#include "gpio_expander.hpp"

#define  I2C_GPIO_DEV_ADDR0 0x59
#define  I2C_GPIO_DEV_ADDR1 0x1c
#define  I2C_GPIO_REG_ADDR 0x01
#define DEFAULT_KEY 240
#define VOLUME_UP_KEY 176
#define VOLUME_DOWN_KEY 112
#define PLAY_PAUSE_KEY 224
#define MUTE_UNMUTE_KEY 208
#define UNDEFINED_KEY 0xFF
#define LED_ON_ADDR 0x40
#define LED_OFF_ADDR 0x44
#define LED_ON_CMD 0x40
#define LED_OFF_CMD 0x00

static const int kSizeOfBuffer = 8;
static const int kSizeOfRGBBuffer = 3;

unsigned char txBuf[kSizeOfBuffer];
unsigned char rxBuf[kSizeOfBuffer];
unsigned char rgbBuf[kSizeOfRGBBuffer];

static const unsigned int kSleepMs = 100 * 1000;
static const unsigned int kLedInterval = kSleepMs * 2;

static unsigned long long ledTimer = 0;
static unsigned long long lastLedTimer = 0;
static bool ledOnFlag = false;



int main(int argc, char **argv)
{
    int led_count = 0;
    static unsigned int last_status = UNDEFINED_KEY;
    unsigned int debounceCounter = 0;

    sleep(5);

    auto i2c0 = std::make_shared<CoreI2C>(I2C_GPIO_DEV_ADDR0);
    auto i2c1 = std::make_shared<CoreI2C>("/dev/i2c-0", I2C_GPIO_DEV_ADDR1);
    auto gpio = std::make_shared<GpioExpander>();

    for (;;)
    {
        i2c0->send(I2C_GPIO_REG_ADDR, txBuf, 1);
        i2c0->receive(I2C_GPIO_REG_ADDR, rxBuf, 1);
        unsigned int status = (unsigned int) rxBuf[0];
        if (last_status == status)
        {
            debounceCounter++;

        } else
        {
            switch (status)
            {
                case DEFAULT_KEY:
                    break;
                case VOLUME_UP_KEY:
                    gpio->setVolumeUp(1);
                    gpio->volumeUpAction();
                    lastLedTimer = ledTimer;
                    ledOnFlag = true;
                    txBuf[0] = LED_ON_CMD;
                    i2c1->send(LED_OFF_ADDR, txBuf, 1);
                    break;
                case VOLUME_DOWN_KEY:
                    gpio->setVolumeDown(1);
                    gpio->volumeDownAction();
                    lastLedTimer = ledTimer;
                    ledOnFlag = true;
                    txBuf[0] = LED_ON_CMD;
                    i2c1->send(LED_OFF_ADDR, txBuf, 1);
                    break;
                case PLAY_PAUSE_KEY:
                    gpio->setPlay(1);
                    gpio->playPauseAction();
                    lastLedTimer = ledTimer;
                    ledOnFlag = true;
                    txBuf[0] = LED_ON_CMD;
                    i2c1->send(LED_OFF_ADDR, txBuf, 1);

                    break;
                case MUTE_UNMUTE_KEY:
                    gpio->setMute(1);
                    gpio->muteUnmuteAction();
                    lastLedTimer = ledTimer;
                    ledOnFlag = true;
                    txBuf[0] = LED_ON_CMD;
                    i2c1->send(LED_OFF_ADDR, txBuf, 1);

                    break;
                default:
                    gpio->FaultAction();
                    break;
            }
        }

        if (debounceCounter > 5)
        {
            last_status = UNDEFINED_KEY;
            debounceCounter = 0;
        } else
        {
            last_status = status;
        }

        if (ledOnFlag)
        {
            if ((ledTimer - lastLedTimer) > kLedInterval)
            {
                txBuf[0] = LED_OFF_CMD;
                i2c1->send(LED_OFF_ADDR, txBuf, 1);
                ledOnFlag = false;
            }
        }
        ledTimer += kSleepMs;
        usleep(kSleepMs);
    }

    return 0;
}