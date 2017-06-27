CC=gcc
CFLAGS = -c -std=c99 -Wall

all: Proiect_TP

Proiect_TP: main.o functii.o generare.o
	$(CC) main.o functii.o generare.o -o Proiect_TP #linking

main.o: main.c
	$(CC) $(CFLAGS) main.c #compile

functii.o: functii.c
	$(CC) $(CFLAGS) functii.c #compile
  
generare.o: generare.c
        $(CC) $(CFLAGS) generare.c #compile
	
clean:
	rm -f *o

#%: %.c; = tab space
#gcc main.c functii.c generare.c -o Proiect_TP
