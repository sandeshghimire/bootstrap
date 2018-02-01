add_library(gpioexpander gpio_expander.cpp gpio_expander.hpp)
target_link_libraries(gpioexpander evaI2C)
include_directories(../core_i2c)
