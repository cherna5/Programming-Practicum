//cherna83

#include "Ant.h"
#include "Doodlebug.h"


#include <iostream>
#include <cstdlib>
using namespace std;

//--------------------------------------------------------------------------------------------------------------
Ant *Ant::forAllAnts[400] = {};
int	Ant::antCounter = 0;
	
void Ant::deleteAnt(int a)
{//a for ant
    for (int i=a; i<antCounter-1; i++)
    {//placing a counter to remove ant
		forAllAnts[i] = forAllAnts[i+1];
    }
	antCounter--; //deleting
}

//--------------------------------------------------------------------------------------------------------------
// This will move the ant randamoly in 4 different paths
void Ant::move()
{
	// just move
	bool invalidMove = false;
	int path = rand()%4;
	
    //first path
    if (path == 0)
    {
        if (x+1 > 19)
        {
            invalidMove = true;
        }
        else
        {
            for (int i=0; i<Doodlebug::doodlebugCounter; i++)
            {
                if (Doodlebug::forAllDoodlebugs[i]->position(x+1, y))
                {
                    invalidMove = true;
                }
            }//end of doodlebug
            for (int i=0; i<Ant::antCounter; i++)
            {
                if (Ant::forAllAnts[i]->position(x+1, y))
                {
                    invalidMove = true;
                }
            }//end of for loop ant
        }
    }//end of path 0
    
    if (path == 1)
    {
		if (x-1 < 0)
        {
			invalidMove = true;
        }
		else
        {
			for (int i=0; i<Doodlebug::doodlebugCounter; i++)
            { //placing a counter to remove doodlebug
				if (Doodlebug::forAllDoodlebugs[i]->position(x-1, y))
                {//check doodlebug paths so they can go random
					invalidMove = true;
                }
            }//end of for loop
			for (int i=0; i<Ant::antCounter; i++)
            {//check ant paths so they can go randomly
				if (Ant::forAllAnts[i]->position(x-1, y))
                {
					invalidMove = true;
                }
            }//end of for loop
		}					
	}


	
    //path2
    if (path == 2)
    {
        if (y+1 > 19)
        {
            invalidMove = true;
        }
        
        else
        {
            for (int i=0; i<Doodlebug::doodlebugCounter; i++)
            {
                if (Doodlebug::forAllDoodlebugs[i]->position(x, y+1))
                {
                    invalidMove = true;
                }
            }
            for (int i=0; i<Ant::antCounter; i++)
            {
                if (Ant::forAllAnts[i]->position(x, y+1))
                {
                    invalidMove = true;
                }
            }
        }
        
    }//end of path 2

    if (path == 3)
    {
		if (y-1 < 0)
        {
			invalidMove = true;
        }
		else
        {
			for (int i=0; i<Doodlebug::doodlebugCounter; i++)
            {
				if (Doodlebug::forAllDoodlebugs[i]->position(x, y-1))
                {
					invalidMove = true;
                }
            }
			for (int i=0; i<Ant::antCounter; i++)
            {
				if (Ant::forAllAnts[i]->position(x, y-1))
                {
					invalidMove = true;
                }
            }
		}
	}//end of path 3
    
    
	//once positions are not empty it cannot make that move
    if (!invalidMove)
    {
		switch (path)
        {
			case 0: move(x+1, y); break;//right
            case 1: move(x-1, y); break;//left
			case 2: move(x, y+1); break;//up/forward
            case 3: move(x, y-1); break;//down/bottom
			
		}
    }
}
//--------------------------------------------------------------------------------------------------------------
void Ant::spawn()
{
    bugAge++;
    
    if (bugAge < 3)
    {
        return;
    }
    
    bool bugCreation = true;
    //create ants to nearby positions as long as its empty
    // left Position
    if (x<19)
    {
        
        //create ants to nearby positions as long as its empty
        // right Position
        
        bugCreation = true;
        for (int i=0; i<Doodlebug::doodlebugCounter; i++)
        {
            if (Doodlebug::forAllDoodlebugs[i]->position(x+1, y))
            {
                bugCreation = false;
            }
        }
        for (int i=0; i<antCounter; i++)
        {
            if (forAllAnts[i]->position(x+1, y))
            {
                bugCreation = false;
            }
        }
        if (bugCreation)
        {
            forAllAnts[antCounter++] = new Ant(x+1, y);
            bugAge = 0;
            return;
        }
    }
    
	if (x>0)
    {
		for (int i=0; i<Doodlebug::doodlebugCounter; i++)
        {
			if (Doodlebug::forAllDoodlebugs[i]->position(x-1, y))
            {
				bugCreation = false;
            }
        }
		for (int i=0; i<antCounter; i++)
        {
			if (forAllAnts[i]->position(x-1, y))
            {
				bugCreation = false;
            }
        }
		
        if (bugCreation)  // ant creation for left Position
        {
			forAllAnts[antCounter++] = new Ant(x-1, y);
			bugAge = 0;
			return;	
		}
	}
    if (y<19)
    {
        bugCreation = true;
        
        //create ants to nearby positions as long as its empty
        // down/bottom Position
        
        for (int i=0; i<Doodlebug::doodlebugCounter; i++)
        {
            if (Doodlebug::forAllDoodlebugs[i]->position(x, y+1))
            {
                bugCreation = false;
            }
        }
        for (int i=0; i<antCounter; i++)
        {
            if (forAllAnts[i]->position(x, y+1))
            {
                bugCreation = false;
            }
        }
        if (bugCreation)
        {
            forAllAnts[antCounter++] = new Ant(x, y+1);
            bugAge = 0;
            return;
        }
    }

    if (y>0)
    {
		bugCreation = true;
        //create ants to nearby positions as long as its empty
        // up/forward Position
        
		for (int i=0; i<Doodlebug::doodlebugCounter; i++)
        {
			if (Doodlebug::forAllDoodlebugs[i]->position(x, y-1))
            {
				bugCreation = false;
            }
        }
		for (int i=0; i<antCounter; i++)
        {
			if (forAllAnts[i]->position(x, y-1))
            {
				bugCreation = false;
            }
        }
		if (bugCreation)
        {
			forAllAnts[antCounter++] = new Ant(x, y-1);
			bugAge = 0;
			return;	
		}
	}
}//end of Ant::spawn()

