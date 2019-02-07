include_directories(
    ${PROJECT_SOURCE_DIR}/src
)

file(GLOB SRCS *.cpp)
file(GLOB HPPS *.hpp)

add_executable(${PROJECT_NAME}
        ${SRCS}
        ${HPPS}
)
