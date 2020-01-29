#include "GridDisplay.h"
#include "creature.h"
#include "Ant.h"
#include "Doodlebug.h"

#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main ( int argc, char** argv )
{
 int i, j, sleepTime = 1000;

 if (argc > 1)
 {
	//debugging
	if (strcmp(argv[1], "-d") == 0)
    {
		sleepTime = atoi(argv[2]);
    }
	 
 }	
 
 cerr << "executing sleepTime: " << sleepTime << endl;
 cerr << "******************* new entry *******************\n";
//---------------------------------------------------------------------------------------------------
//intial 5 Doodlebugs
	for (i=0; i<5; )
    {
		int x = rand()%20;
		int y = rand()%20;
		bool found = false;
		for (j=0; j< Doodlebug::doodlebugCounter; j++)
        {
			if (Doodlebug::forAllDoodlebugs[j]->position(x, y)) found = true;
		}
        //if not found will create a doodlebug
		if (!found)
        {
			Doodlebug::forAllDoodlebugs[Doodlebug::doodlebugCounter++] = new Doodlebug(x, y);
			i++;
		}
	}		
 
 // creating 100 ants
	for (i=0; i<100; )
    {
		int x = rand()%20;
		int y = rand()%20;
		bool found = false;
        
		for (j=0; j< Doodlebug::doodlebugCounter; j++)
        {
			if (Doodlebug::forAllDoodlebugs[j]->position(x, y)) found = true;
		}
		for (j=0; j< Ant::antCounter; j++)
        {
			if (Ant::forAllAnts[j]->position(x, y)) found = true;
		}		
		if (!found)
        {
			Ant::forAllAnts[Ant::antCounter++] = new Ant(x, y);
			i++;//Ants created
		}
	}		
 
//---------------------------------------------------------------------------------------------------
//to display whole grid
GridDisplay gd(20, 20);

 for (j=0; j< Doodlebug::doodlebugCounter; j++)
 {
	gd.setChar(Doodlebug::forAllDoodlebugs[j]->getX(), Doodlebug::forAllDoodlebugs[j]->getY(), 'd');
 }
 for (j=0; j< Ant::antCounter; j++)
 {
	gd.setChar(Ant::forAllAnts[j]->getX(), Ant::forAllAnts[j]->getY(), 'A');
 }		

 gd.showGrid ( );
 
 // show 20 days
 for ( i = 0 ; i < 20 ; i++ )
 {	
    gd.mySleep ( sleepTime );

   // display movement and action doodlebugs
   for (j=0; j< Doodlebug::doodlebugCounter; j++)
    {
       Doodlebug::forAllDoodlebugs[j]->hunt();
       Doodlebug::forAllDoodlebugs[j]->spawn();
       Doodlebug::forAllDoodlebugs[j]->starve();
    }
   
   //display ants movement
   for (j=0; j< Ant::antCounter; j++)
    {
       Ant::forAllAnts[j]->move();
       Ant::forAllAnts[j]->spawn();
    }
   
     //display all of the creatures
   gd.init(20, 20);
   
     for (j=0; j< Doodlebug::doodlebugCounter; j++)
     {
         gd.setChar(Doodlebug::forAllDoodlebugs[j]->getX(), Doodlebug::forAllDoodlebugs[j]->getY(), 'd');
     }
     
   for (j=0; j< Ant::antCounter; j++)
    {
        gd.setChar(Ant::forAllAnts[j]->getX(), Ant::forAllAnts[j]->getY(), 'A');
    }

     gd.showGrid ( );
 }

 return 1;
}
