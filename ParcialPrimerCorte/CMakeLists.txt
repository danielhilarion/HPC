cmake_minimum_required(VERSION 3.5)

project(ParcialPrimerCorte LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(project_sources
    main.cpp
    Functions/functions.cpp)

set(project_headers
    Functions/functions.h)




add_executable(${PROJECT_NAME}
                ${project_sources}
                ${project_headers})
