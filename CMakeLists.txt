cmake_minimum_required(VERSION 3.1)

project(psych)

# This sets the package specific versioning
set(PSYCH_MAJOR_VERSION 0)
set(PSYCH_MINOR_VERSION 0)
set(PSYCH_PATCH_VERSION 2)

message("-- Building psych version: ${PSYCH_MAJOR_VERSION}.${PSYCH_MINOR_VERSION}.${PSYCH_PATCH_VERSION}")

# Option to install targets to env location
if(DEFINED ENV{PSYCH_HOME})
     message("-- Will install PSYCH_HOME binaries and libraries to location: " $ENV{PSYCH_HOME})
	 set(CMAKE_INSTALL_PREFIX $ENV{PSYCH_HOME})
else(DEFINED ENV{PSYCH_HOME})
     message("-- Will install PSYCH_HOME binaries and libraries to location: " ${CMAKE_CURRENT_BINARY_DIR})
	 set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR})
endif(DEFINED ENV{PSYCH_HOME})


# Disable some windows specific warnings for using more modern c functions
if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif(MSVC)

find_file(HAVE_STDINT_HEADER stdint.h)
if(HAVE_STDINT_HEADER)
   message("** stdint.h found")
   add_definitions(-DPSYCH_HAVE_STDINT_HEADER)
else(HAVE_STDINT_HEADER)
   message("** stdint.h not found")
endif(HAVE_STDINT_HEADER)

# Options
option(WITH_testing "Allows tests to be run" ON)

if(WITH_testing MATCHES ON)
   enable_testing()
endif(WITH_testing MATCHES ON)

add_subdirectory(src)

if(WITH_testing MATCHES ON)
   add_subdirectory(ctests)
endif(WITH_testing MATCHES ON)