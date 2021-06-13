project(Indexer)

add_library( 
    Indexer SHARED
    
    Indexer.h 
    Indexer.cpp
)

target_link_libraries(Indexer)