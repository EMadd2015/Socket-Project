demo:   Foreman.o Miner.o TCPServer.o TCPClient.o
	g++ -lpthread main.cpp Foreman.o Miner.o TCPServer.o TCPClient.o -o run

Foreman.o:
	g++ -c Foreman.cpp

Miner.o:
	g++ -c Miner.cpp

TCPServer.o:
	g++ -c TCPServer.c

TCPClient.o:
	g++ -c TCPClient.c