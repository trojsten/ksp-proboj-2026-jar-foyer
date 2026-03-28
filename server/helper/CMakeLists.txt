add_library(helper)

# Collect all .cpp files in this module/src/
file(GLOB_RECURSE SOURCES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

# Add all found sources to the library
target_sources(helper PRIVATE ${SOURCES})

target_link_libraries(helper PUBLIC
    glaze::glaze
)

# Public include directory (so consumers can find headers)
target_include_directories(helper PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
