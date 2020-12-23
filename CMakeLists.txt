cmake_minimum_required(VERSION 3.15)
project(lcm-demo)

set(CMAKE_CXX_STANDARD 11)

# ------------------------------
add_executable(
    publisher
    src/publisher.cpp
)
target_link_libraries(
    publisher
    lcm
)

# ------------------------------
add_executable(
    subscriber
    src/subscriber.cpp
)
target_link_libraries(
    subscriber
    lcm
)