cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)

#Główny projekt, nie usuwać
project(glowny)
#dołącz folder z plikami nagłówkowymi
include_directories(include)
#dodaj pliki źródłowe do projektu
add_executable(glowny src/main.cpp src/Graf.cpp src/PrzydzialZasobow.cpp)

#projekty do testowania (własne, można dodawać)
project(wojtek)
#dodaj wybrane pliki źródłowe do własnego projektu do testowania
add_executable(wojtek src/wojtek.cpp src/Graf.cpp src/PrzydzialZasobow.cpp)

project(gosia)
add_executable(gosia src/main.cpp)