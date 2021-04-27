
########################## StaticQueryEngine ##############################

add_executable( static_query_engine_unit_test
    unittest/StaticQueryEngine/StaticQueryEngine_Test.cpp
    ${CMAKE_SOURCE_DIR}/src/StaticQueryEngine.cpp
)

target_include_directories(static_query_engine_unit_test PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/interfaces/
)

target_link_libraries( static_query_engine_unit_test
   gtest
   pthread
)

########################## IntentManager ##############################

add_executable( intent_manager_unit_test
    unittest/IntentManager/IntentManager_Test.cpp
    ${CMAKE_SOURCE_DIR}/src/IntentManager.cpp
)

target_include_directories(intent_manager_unit_test PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/interfaces/
)

target_link_libraries( intent_manager_unit_test
   gtest
   pthread
)

########################## DataParser ##############################

add_executable( static_data_parser_unit_test
    unittest/StaticDataParser/StaticDataParser_Test.cpp
    ${CMAKE_SOURCE_DIR}/src/StaticDataParser.cpp
)

target_include_directories(static_data_parser_unit_test PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/interfaces/
    ${CMAKE_SOURCE_DIR}/src/intents/
)

target_link_libraries( static_data_parser_unit_test
   gtest
   pthread
)