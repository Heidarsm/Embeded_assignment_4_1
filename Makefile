output: main.o fifo.o increment.o decrement.o
	g++ main.o -o output -pthread -I include -I src

main.o: src/main.cpp
	g++ -c -I include -pthread src/main.cpp

fifo.o: src/fifo.cpp include/fifo.h
	g++ -c -I include -pthread src/fifo.cpp

increment.o: src/increment.cpp include/increment.h
	g++ -c -I include -pthread src/increment.cpp

decrement.o: src/decrement.cpp include/decrement.h
	g++ -c -I include -pthread src/decrement.cpp

mutex3:
	g++ -o mutex3 -pthread -I include src/main.cpp
clean: 
	rm *.o output