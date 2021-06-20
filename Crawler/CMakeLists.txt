cmake_minimum_required(VERSION 3.0)

project(Crawler)

set(CMAKE_CXX_STANDARD 17) #c++17

add_executable(${PROJECT_NAME} main.cpp)

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