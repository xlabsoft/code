prepend(SERVER_SOURCES_ENGINE ${SOURCE_DIR}/engine
    server.cpp command.cpp worldio.cpp)

prepend(SERVER_SOURCES_FPSGAME ${SOURCE_DIR}/fpsgame
    server.cpp entities.cpp)

set(SERVER_SOURCES ${SERVER_SOURCES_FPSGAME}
  ${SERVER_SOURCES_ENGINE} ${COMMON_SOURCES}
  CACHE INTERNAL "")

# Set Binary name
set(SERVER_BINARY server CACHE INTERNAL "Server binary name.")

add_definitions(-DSERVER -DSTANDALONE)

if(OS_LINUX)
  set(ADDITIONAL_LIBRARIES ${ADDITIONAL_LIBRARIES} dl -pthread)
endif()

add_app(${SERVER_BINARY} ${SERVER_SOURCES})

target_link_libs(${SERVER_BINARY} ${COMMON_LIBS}
  ${ADDITIONAL_LIBRARIES})

config_net(${SERVER_BINARY})
config_rpc(${SERVER_BINARY})
config_util(${SERVER_BINARY})
config_muparser(${SERVER_BINARY})
