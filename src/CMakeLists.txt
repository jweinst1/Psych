# src c make

include_directories(${PROJECT_SOURCE_DIR}/include)

set(PSYCH_CLIB_SOURCES
    psych_item_market.c
)

add_library(psych SHARED "${PSYCH_CLIB_SOURCES}")
add_library(psychs STATIC "${PSYCH_CLIB_SOURCES}")