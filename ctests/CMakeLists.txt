# test c make 

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(test_psych_item_market test_psych_item_market.c)
target_link_libraries(test_psych_item_market PRIVATE psychs)
add_test(PsychMarket_Item test_psych_item_market)