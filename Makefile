OBJECTS = BankAccount.o BankSystemManager.o main.o
CFLAGS = -Wall -g
CXX = g++


Bank: $(OBJECTS)
	@ $(CXX) $^ -o $@

BankAccount.cpp : BankAccount.h
BankSystemManager.cpp : BankSystemManager.h
main.cpp :

.phony: clean
clean:
	@ rm *.o Bank


