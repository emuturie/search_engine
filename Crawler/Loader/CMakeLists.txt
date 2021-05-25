project(Loader)

add_library( 
    Loader SHARED
    
    Loader.h
    Loader.cpp
)

target_link_libraries(Loader -lcurl)