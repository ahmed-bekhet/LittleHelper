set(TARGET_NAME "little-helper")

add_executable( ${TARGET_NAME}
    main.cpp
    IntentManager.cpp
    StaticDataParser.cpp
    StaticQueryEngine.cpp
)

target_include_directories(${TARGET_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/intents
    ${CMAKE_SOURCE_DIR}/src/interfaces
)