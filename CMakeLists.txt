cmake_minimum_required(VERSION 3.23)
project(OBJ_Projekat)

set(CMAKE_CXX_STANDARD 17)


add_executable(OBJ_Projekat
        src/main.cpp
        src/abstract/Serializable.h
        src/managers/AbstractManager.cpp
        src/exceptions/FileException.cpp
        src/entities/Korisnik.cpp
        src/utils/MiscUtils.cpp
        src/managers/KorisnikManager.cpp
        src/exceptions/NotFoundException.cpp
        src/exceptions/AuthException.cpp
        src/abstract/Serializable.cpp src/abstract/Manager.h src/commands/AbstractCommand.cpp src/commands/AbstractCommand.h src/commands/CommandHandler.cpp src/commands/CommandHandler.h src/commands/main/LoginCommand.cpp src/commands/main/LoginCommand.h src/commands/main/RegisterCommand.cpp src/commands/main/RegisterCommand.h src/exceptions/KorisnikExistException.h src/entities/Smestaj.cpp src/entities/Smestaj.h src/entities/Apartman.cpp src/entities/Apartman.h lib/include/Table.h src/entities/Hotel.cpp src/entities/Hotel.h src/managers/HotelManager.cpp src/managers/HotelManager.h src/exceptions/SmestajExistException.h src/commands/admin/KorisnikCommand.cpp src/commands/admin/KorisnikCommand.h src/commands/HotelCommand.cpp src/commands/HotelCommand.h src/managers/ApartmanManager.cpp src/managers/ApartmanManager.h src/commands/ApartmanCommand.cpp src/commands/ApartmanCommand.h src/entities/Rezervacija.cpp src/entities/Rezervacija.h src/managers/RezervacijeManager.cpp src/managers/RezervacijeManager.h)

target_include_directories(OBJ_Projekat
        PRIVATE src/exceptions
        PRIVATE src/utils
        PRIVATE src/managers
        PRIVATE src/entities
        PRIVATE src/abstract
        PRIVATE src/commands
        PRIVATE src/commands/main
        PRIVATE src/commands/admin)

add_subdirectory(lib)
target_link_libraries(OBJ_Projekat bcrypt)
