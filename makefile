#!/bin/bash


CC = gcc
CFLAGS = -g -ansi -pedantic -Wall

TARGET = main
	
file: $(TARGET)
	./$(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

.PHONEY : clean help
clean :
	-rm $(TARGET)
help :
	@echo "make TARGET={filename_without.C} [clean]"
