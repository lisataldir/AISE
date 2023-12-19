project(AISE)
cmake_minimum_required(VERSION 3.10)

add_executable(main.exe main.c serveur.c commandes.c hachage.c prime.c)

target_link_libraries(main.exe m)