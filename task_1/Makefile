 OPT = -O1
 ArraySize = 100000
 Iterations = 10000

default: runall

runall: run1 run2

#run cache tests
run1: cachetest1
	./cachetest1 --array_size $(ArraySize) --repetitions $(Iterations)
	
run2: cachetest2
	./cachetest2 --array_size $(ArraySize) --repetitions $(Iterations)

#Build the cachetests
cachetest1: cachetest1.o 
	gcc $(OPT) -o cachetest1 cachetest1.o
    
cachetest2: cachetest2.o 
	gcc $(OPT) -o cachetest2 cachetest2.o    

    
#Create .o object files for cache tests    
cachetest1.o: cachetest1.c
	gcc $(OPT) -c cachetest1.c
    
cachetest2.o: cachetest2.c
	gcc $(OPT) -c cachetest2.c


clean:
	rm -f *.o
	rm -f cachetest1
	rm -f cachetest2

