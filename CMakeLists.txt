cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

project(szeregowanieZadan)
#dołącz folder z plikami nagłówkowymi
include_directories(include)
#dodaj pliki źródłowe do projektu
add_executable(szeregowanieZadan
        src/main.cpp
        src/Drzewo.cpp
        src/Graf.cpp
        src/Node.cpp
        src/PrzydzialZasobow.cpp
        src/Wczytywanie.cpp
        src/Interfejs.cpp
        src/Random.cpp
        )
