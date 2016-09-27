CC:=gcc
CFLAGS:=-Wall -pedantic -ansi -g -O2

restaUm: restaUm.o f_matriz.o f_pilha.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf *.o