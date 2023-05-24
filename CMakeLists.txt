cmake_minimum_required(VERSION 3.23)
project(OBJ_Projekat)

set(CMAKE_CXX_STANDARD 14)


add_executable(OBJ_Projekat
        src/main.cpp
        src/utils/SerializationUtils.cpp
        src/abstract/Serializable.h
        src/managers/AbstractManager.cpp
        src/exceptions/FileException.cpp
        src/entities/Korisnik.cpp
        )

target_include_directories(OBJ_Projekat
        PRIVATE src/exceptions
        PRIVATE src/utils
        PRIVATE src/managers
        PRIVATE src/entities
        PRIVATE src/abstract)

add_subdirectory(lib)
target_link_libraries(OBJ_Projekat bcrypt)
