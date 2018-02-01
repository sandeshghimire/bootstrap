cmake_minimum_required(VERSION 3.0)

list(APPEND OUR_SCRIPTS
  down.sh
  mute.sh
  play_pause.sh
  up.sh
)

install(
    FILES ${OUR_SCRIPTS}
    DESTINATION share/gpioexpanderd
    PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_READ
)
