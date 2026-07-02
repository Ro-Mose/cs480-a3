########################################
# Makefile
# CS480 Summer 2026, Assignment #3
# Ronessa Mose / Nicolas Mendoza
# cssc3138 / cssc3135
########################################

CC = gcc
CFLAGS = -Wall -std=c99

simarm: main.c algs.c algs.h
	$(CC) $(CFLAGS) main.c algs.c -o simarm

clean:
	rm -f simarm

#############[ EOF : Makefile ]##########
