set(TOOLCHAIN gcc-arm-none-eabi)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_C_COMPILER "arm-none-eabi-gcc" CACHE INTERNAL "")
set(CMAKE_CXX_COMPILER "arm-none-eabi-g++" CACHE INTERNAL "")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

#set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY") # hack to drop cmakes sample program call with unknown '-rdynamic'

# Architecture flags
set(COM_FLAGS "-mlittle-endian -mthumb -mcpu=cortex-m0 -mfloat-abi=soft -specs=nano.specs -specs=nosys.specs -fno-exceptions")
set(TUNE_FLAGS "-fdata-sections -ffunction-sections -Wl,--gc-sections")
set(CMAKE_C_FLAGS "${COM_FLAGS} ${TUNE_FLAGS}" CACHE INTERNAL "")

# Build Variant flags
set(CMAKE_C_FLAGS_DEBUG "-Og -g3" CACHE INTERNAL "")
set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG" CACHE INTERNAL "")
