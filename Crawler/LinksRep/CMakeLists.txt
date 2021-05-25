project(LinkRepository)

add_library( 
    LinkRepository SHARED
    
    Link.h
    Link.cpp

    LinkRepository.h
    LinkRepository.cpp
)

target_link_libraries(LinkRepository)