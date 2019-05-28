cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)

#Główny projekt, nie usuwać
project(glowny)
#dołącz folder z plikami nagłówkowymi
include_directories(include)
#dodaj wszystkie pliki źródłowe z src do zmiennej ${GLOWNY_SOURCES}
file(GLOB GLOWNY_SOURCES "src/*.cpp")
#dodaj pliki źródłowe do projektu
add_executable(glowny ${GLOWNY_SOURCES})

#projekty do testowania (własne, można dodawać)
project(wojtek)
#dodaj wybrane pliki źródłowe do własnego projektu do testowania
add_executable(wojtek src/wojtek.cpp src/PrzydzialZasobow.cpp)

