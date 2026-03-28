# Target system
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR x86_64)

# Adjust this if your musl toolchain lives elsewhere
set(TOOLCHAIN_PREFIX musl)

# Compilers
set(CMAKE_C_COMPILER   ${TOOLCHAIN_PREFIX}-gcc)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PREFIX}-gcc)

# Optional: use musl-specific binutils
set(CMAKE_AR      ${TOOLCHAIN_PREFIX}-ar)
set(CMAKE_RANLIB  ${TOOLCHAIN_PREFIX}-ranlib)
set(CMAKE_STRIP   ${TOOLCHAIN_PREFIX}-strip)

# Prevent CMake from picking host includes/libs
set(CMAKE_SYSROOT /usr/${TOOLCHAIN_PREFIX})

set(CMAKE_FIND_ROOT_PATH ${CMAKE_SYSROOT})

# Search behavior
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# Static linking (optional, remove if you want dynamic)
set(CMAKE_EXE_LINKER_FLAGS "-static")

# Avoid try-run (since we’re cross compiling)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
