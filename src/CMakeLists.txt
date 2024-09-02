# archiver sources
target_sources(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/archiver/Archiver.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/archiver/Cli.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/archiver/CommandInfo.cpp

)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/archiver)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/infra)