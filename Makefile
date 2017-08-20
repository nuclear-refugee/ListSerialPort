CC = gcc
CFLAGS = -Wall -gdwarf-2 -std=gnu99 -o2
LIBSRC = rs232.c
LIBOBJ = ${LIBSRC:.c=.o}

listsp :
	@gcc main.c rs232.c -Wall -Wextra -lpthread -o2 -o listsp
