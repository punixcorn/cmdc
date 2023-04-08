CC=gcc
FLAGS= -std=gnu17 -g --all-warnings
File=test.c
catfile=temp
Debug=
exe: outfile.o
	$(CC) outfile.o -o exe

outfile.o : $(File)
	$(CC) -c $(File) $(FLAGS) $(Debug) -o outfile.o

run: exe
	./exe

cat: 
	@cat ${catfile}

copy:
	cp ./.temp temp

clean:
	@touch some.o exe 
	rm *.o exe 



