CXX=g++
BINARIES=program

program: program.o
	${CXX} -std=c++11 $^ -o $@

clean:
	rm *.o ${BINARIES}