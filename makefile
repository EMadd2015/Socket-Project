demo:   Foreman.o Miner.o
        g++ -lpthread main.cpp Foreman.o Miner.o -o run

Foreman.o: TCPServer.o
        g++  Foreman.cpp TCPServer.o

Miner.o: TCPClient.o
        g++  Miner.cpp TCPClient.o

TCPServer.o:
        g++ -c TCPServer.c

TCPClient.o:
        g++ -c TCPClient.c
