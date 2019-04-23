
FLAGS = -Wall -std=c++11

output: ./obj/main.o ./obj/graal.o
	mkdir -p bin
	g++ $(FLAGS) ./obj/main.o ./obj/graal.o -o ./bin/graal

./obj/main.o: ./test/main.cpp
	mkdir -p obj
	g++ -c ./test/main.cpp -I ./include -o ./obj/main.o $(FLAGS)

./obj/graal.o: ./src/graal.cpp ./include/graal.h
	mkdir -p obj
	g++ -c ./src/graal.cpp -I ./include -o ./obj/graal.o $(FLAGS)

clear:
	rm -r ./obj ./bin
