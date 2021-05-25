cmake_minimum_required(VERSION 3.0)

project("Crawler")

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp)

include_directories(Loader)
include_directories(Parser)
include_directories(LinksRep)
include_directories(Website)

add_subdirectory(Loader)
add_subdirectory(Parser)
add_subdirectory(LinksRep)
add_subdirectory(Website)

set_target_properties(Loader PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/Loader/libLoader.so"
)

set_target_properties(Parser PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/Parser/libParser.so"
)

set_target_properties(LinkRepository PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/LinkRepository/libLinkRepository.so"
)

set_target_properties(Website PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/Website/libWebsite.so"
)

target_link_libraries(${PROJECT_NAME} Loader Parser LinkRepository Website)