cmake_minimum_required(VERSION 3.13.2)
set(CMAKE_CXX_STANDARD 14)

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
