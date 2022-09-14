OBJECTS = BankAccount.o BankSystemManager.o View.o main.o
CFLAGS = -Wall -g
CXX = g++


Bank: $(OBJECTS)
	@ $(CXX) $^ -o $@

BankAccount.cpp : BankAccount.h
BankSystemManager.cpp : BankSystemManager.h
View.cpp : View.h
main.cpp :

.phony: clean
clean:
	@ rm *.o Bank


