project(Parser)

add_library( 
    Parser SHARED
    
    Parser.h
    Parser.cpp
)

target_link_libraries(Parser -lgumbo)