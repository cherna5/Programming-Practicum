//cherna83
//Doodlebug class Headerfile

#include "creature.h"

class Doodlebug: public Insect 
{
 private:
 
 public:
	Doodlebug(int x, int y):Insect(x,y){}
	
    void hunt();
	void spawn();
	void starve();
    static Doodlebug *forAllDoodlebugs[];
	static int doodlebugCounter;
};
