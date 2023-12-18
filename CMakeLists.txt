project(AISE)
cmake_minimum_required(VERSION 3.10)

add_executable(serveur.exe serveur.c hachage.c prime.c)

target_link_libraries(serveur.exe m)