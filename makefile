main: main.o
	g++ -std=gnu++98 main.o -o main

main.o: main.cpp
	g++ -c -std=gnu++98 main.cpp

run: main
	./main

clean: 
	del *.o main