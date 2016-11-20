 OPT = -O1 			
 ArraySize = 1000 

default: runall

#Run the tests
runall: run1 run2 run3
	

run1: matrix1
	./matrix1 --array_size $(ArraySize)

run2: matrix2
	./matrix2 --array_size $(ArraySize)

run3: matrix3
	./matrix3 --array_size $(ArraySize)	



#Build the files to run
matrix1: matrix1.o 
	gcc $(OPT) -o matrix1 matrix1.o

matrix1.o: matrix1.c
	gcc $(OPT) -c matrix1.c
	
matrix2: matrix2.o 
	gcc $(OPT) -o matrix2 matrix2.o

matrix2.o: matrix2.c
	gcc $(OPT) -c matrix2.c	
	
matrix3: matrix3.o 
	gcc $(OPT) -o matrix3 matrix3.o

matrix3.o: matrix3.c
	gcc $(OPT) -c matrix3.c


clean:
	rm -f *.o
	rm -f matrix1
	rm -f matrix2
	rm -f matrix3

