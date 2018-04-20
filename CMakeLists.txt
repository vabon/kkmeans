cmake_minimum_required(VERSION 3.2)

project(kkmeans VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(dlib REQUIRED COMPONENTS)

configure_file(version.h.in version.h)

add_executable(kkmeans kkmeans.cpp)

set_target_properties(kkmeans PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

target_link_libraries(kkmeans
    dlib::dlib
)

install(TARGETS kkmeans RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@mail.com)

include(CPack)
