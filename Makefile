########################################
# Makefile
# CS480 Summer 2026, Assignment #3
# Ronessa Mose / Nicolas Mendoza
# cssc3138 / cssc3135
########################################

CC = gcc
CFLAGS = -Wall

simarm: main.c algorithms.c
	$(CC) $(CFLAGS) main.c algorithms.c -o simarm

clean:
	rm -f simarm

#############[ EOF : Makefile ]##########
