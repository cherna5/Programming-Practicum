codeMain: codeMain.cpp Ant.o Doodlebug.o GridDisplay.o creature.h
	g++ -o codeMain codeMain.cpp Ant.o Doodlebug.o GridDisplay.o

GridMain:  GridMain.cpp GridDisplay.o
	g++ -o GridMain GridMain.cpp GridDisplay.o

gddemo: gddemo.cpp GridDisplay.o
	g++ -o gddemo gddemo.cpp GridDisplay.o

GridDisplay.o: GridDisplay.cpp GridDisplay.h
	g++ -c GridDisplay.cpp

Doodlebug.o: Doodlebug.cpp Doodlebug.h creature.h
	g++ -c Doodlebug.cpp

Ant.o: Ant.cpp Ant.h creature.h
	g++ -c Ant.cpp

clean:
	rm -f *.o GridMain

