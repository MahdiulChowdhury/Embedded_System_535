CC=gcc

OBJS = bits.o main.o

#default: BitApp

HelloWorld: $(OBJS)
	$(CC) -o BitApp $(OBJS)

bits.o: bits.c bits.h
	$(CC) -c bits.c -o bits.o

main.o: main.c bits.h
	$(CC) -c main.c -o main.o

clean: 
	rm $(OBJS) BitApp
