cmake_minimum_required(VERSION 3.13.2)
set(CMAKE_CXX_STANDARD 14)

#Główny projekt, nie usuwać
project(glowny)
#dołącz folder z plikami nagłówkowymi
include_directories(include)
#dodaj pliki źródłowe do projektu
add_executable(glowny
        src/main.cpp
        src/Drzewo.cpp
        src/Graf.cpp
        src/Node.cpp
        src/PrzydzialZasobow.cpp
        src/Wczytywanie.cpp
        src/Interfejs.cpp
        src/Random.cpp
        )

#projekty do testowania (własne, można dodawać)
project(wojtek)
#dodaj wybrane pliki źródłowe do własnego projektu do testowania
add_executable(wojtek
        src/wojtek.cpp
        src/Random.cpp
        )

project(gosia)
add_executable(gosia src/main.cpp)

project(aleksandra)
add_executable(aleksandra src/ola.cpp)

project(radek)