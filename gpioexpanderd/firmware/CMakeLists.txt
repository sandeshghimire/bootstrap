cmake_minimum_required(VERSION 3.0)

list(APPEND OUR_SCRIPTS
  appledemo.bin
)

install(FILES ${OUR_SCRIPTS} DESTINATION share/gpioexpanderd/fimware) 
