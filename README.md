# Project - TCP Server

## Usage

First, you have to create a folder name 'clients' in the current directory and to compile the program with Cmake.
To use CMakeLists.txt, create a folder name build in the current directory and write the following line in your shell :
```bash
$ cd build
$ cmake ..
$ make
```

Then, to execute the program, write './main.exe 8080' for example (but it can be an different number than 8080) and write 'nc localhost 8080' via a new shell to log in the server. Note : You can repeat 'nc localhost 8080' in a new shell to have more than one client connected.

## List of commands (commandes.h)

HELP : print all the available commands
PING : print PONG
SET [x] : save [x] in a table
GET [x] : search [x] in the table and print it if found
DEL [x] : delete [x] from the table
ACL_USERS : print the list of all the clients connected to the server
COPY [x] [y] : 
ECHO [x] : print x, but do not save it in a table
INCR [x] : increment [x] (note: x has to be set before)
SAVE : saves the variables previously set in a file
