cmake_minimum_required( VERSION 3.5.0 )
project( TuyaExample LANGUAGES C )

# super build this project with
# 1. no toolchainfile -> native x86 build
# 2. given toolchainfile -> cross build
option( SUPERBUILD "" ON )
if ( SUPERBUILD )
    include( ExternalProject )
    ExternalProject_Add( x64
        PREFIX x64
        SOURCE_DIR ${CMAKE_SOURCE_DIR}
        BINARY_DIR ${CMAKE_BINARY_DIR}/x64
        CMAKE_CACHE_ARGS
            -DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}
            -DSUPERBUILD:BOOL=OFF
        BUILD_ALWAYS ON
        INSTALL_COMMAND ""
    )
    if ( ${CMAKE_CROSSCOMPILING} )
        ExternalProject_Add( arm
            PREFIX arm
            SOURCE_DIR ${CMAKE_SOURCE_DIR}
            BINARY_DIR ${CMAKE_BINARY_DIR}/arm
            CMAKE_CACHE_ARGS
                -DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}
                -DCMAKE_TOOLCHAIN_FILE:FILEPATH=${CMAKE_TOOLCHAIN_FILE}
                -DSUPERBUILD:BOOL=OFF
            BUILD_ALWAYS ON
            INSTALL_COMMAND ""
        )
    endif()
    return()
endif()


# add Tuya IoT Core SDK
add_subdirectory( tuya-iot-core-sdk )

# my project as executable
# (we can simply use / start from a copy of a Tuya SDK example source file we copy to our local project
#  e.g. tuya-iot-core-sdk/examples/data_model_basic_demo/data_model_basic_demo.c)
add_executable( tuya_demo
    src/data_model_basic_demo.c
)

# Tuya SDK provides a platform_port for posix only - add/link sample dummy implementation if cross built
if( ${CMAKE_CROSSCOMPILING} )
    target_sources( tuya_demo
        PUBLIC src/platform/dummy/system_wrapper.c
               src/platform/dummy/storage_wrapper.c
               src/platform/dummy/mbedtls_sockets_wrapper.c
    )
endif()

# link Tuya SDK as dependency to my project
add_dependencies( tuya_demo tuya-iot-core-sdk )
target_link_libraries( tuya_demo tuya-iot-core-sdk )
