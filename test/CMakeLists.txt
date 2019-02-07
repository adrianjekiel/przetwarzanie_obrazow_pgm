file(GLOB SRCS *.cpp)
include_directories(
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/test
)

add_executable(${PROJECT_NAME}-test ${SRCS})
target_link_libraries(${PROJECT_NAME}-test gmock_main)
add_test(NAME ${PROJECT_NAME}-test COMMAND ${PROJECT_NAME}-test)
