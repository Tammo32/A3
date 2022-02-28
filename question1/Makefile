.default: all

all: question1

clean:
	rm -rf qwirkle *.o *.dSYM

qwirkle: Node.o LinkedList.o Patient.o PatientRegister.o WaitingList.o question1.o
	g++ -Wall -Wextra -Werror -std=c++14 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^
