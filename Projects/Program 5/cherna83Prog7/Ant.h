//cherna83
//AntClass Header
#include "creature.h"


class Ant: public Insect 
{
 private:
 
 public:
    Ant(int x, int y):Insect(x,y){}
 	
    static Ant *forAllAnts[400];
 	void move();
 	void spawn();
 	
    void move(int x, int y)
    {
		Insect::move(x,y);
	}
	static int antCounter;
	static void deleteAnt(int a);
};
