//cherna83

#include "Ant.h"
#include "Doodlebug.h"


#include <iostream>
#include <cstdlib>
using namespace std;

//--------------------------------------------------------------------------------------------------------------
Doodlebug *Doodlebug::forAllDoodlebugs[400];
int	Doodlebug::doodlebugCounter = 0;

//checking to see if there is an ant to eat
void Doodlebug::hunt()
{
	int eatAnt = -1;
	for (int i=0; i<Ant::antCounter; i++) {

        // for right position = 0
        if (x < 19 && Ant::forAllAnts[i]->position(x+1, y))
        {
            eatAnt = i;
            move(x+1, y);
            break;
        }
        
        // for left position = 1
		if (x > 0 && Ant::forAllAnts[i]->position(x-1, y))
        {
			eatAnt = i;
			move(x-1, y);
			break;
		}

        // for down/bottom position = 2
        if (y < 19 && Ant::forAllAnts[i]->position(x, y+1))
        {
            eatAnt = i;
            move(x, y+1);
            break;
        }
        
        // for up/forward position = 3
		if (y > 0 && Ant::forAllAnts[i]->position(x, y-1))
        {
			eatAnt = i;
			move(x, y-1);
			break;
		}

	}
	
    //if ant is found, delete ant
	if (eatAnt != -1)
    {
		starvePeriod = 0;
		Ant::deleteAnt(eatAnt);
		return;
	}
				
	//continue to move
	bool invalidMove = false;
	int path = rand()%4;
    
    //right path
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
            }
        }
    }
    
    //left path
	if (path == 1)
    {
		if (x-1 < 0)
        {
			invalidMove = true;
        }
		else
        {
			for (int i=0; i<Doodlebug::doodlebugCounter; i++)
            {
				if (Doodlebug::forAllDoodlebugs[i]->position(x-1, y))
                {
					invalidMove = true;
                }
            }
            
        }
	}

    
    //up/forward path
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
        }
    }
    
    //down/bottom path
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
        }
	}
	
	
    if (!invalidMove)
    {
		switch (path)
        {
            case 0: move(x+1, y); break;
            case 1: move(x-1, y); break;
            case 2: move(x, y+1); break;
            case 3: move(x, y-1); break;
		}
    }
}//end of doodlebug::hunt()

//--------------------------------------------------------------------------------------------------------------
//time to check for near by doodlebug positions if taken or not
void Doodlebug::spawn() {
	
    bugAge++;
	
    if (bugAge < 8)
    {
        return;
    }
	bool bugCreation = true;
    
    if (x<19)
    {
        bugCreation = true;
        for (int i=0; i<Doodlebug::doodlebugCounter; i++)
        {//right position
            if (Doodlebug::forAllDoodlebugs[i]->position(x+1, y))
            {
                bugCreation = false;
            }
        }
        for (int i=0; i<Ant::antCounter; i++)
        {
            if (Ant::forAllAnts[i]->position(x+1, y))
            {
                bugCreation = false;
            }
        }
        if (bugCreation)
        {
            Doodlebug::forAllDoodlebugs[Doodlebug::doodlebugCounter++] = new Doodlebug(x+1, y);
            bugAge = 0;
            return;
        }
    }
    if (x>0)
    {
		for (int i=0; i<Doodlebug::doodlebugCounter; i++)
        {
			if (Doodlebug::forAllDoodlebugs[i]->position(x-1, y))
            {//left position
				bugCreation = false;
            }
        }
		for (int i=0; i<Ant::antCounter; i++)
        {
			if (Ant::forAllAnts[i]->position(x-1, y))
            {
				bugCreation = false;
            }
        }
		if (bugCreation)
        {//doodlebug left creations
			Doodlebug::forAllDoodlebugs[Doodlebug::doodlebugCounter++] = new Doodlebug(x-1, y);
			bugAge = 0;
			return;	
		}
	}

    if (y<19)
    {
        bugCreation = true;
        for (int i=0; i<Doodlebug::doodlebugCounter; i++)
        {
            if (Doodlebug::forAllDoodlebugs[i]->position(x, y+1))
            {//down/bottom position creation
                bugCreation = false;
            }
        }
        for (int i=0; i<Ant::antCounter; i++)
        {
            if (Ant::forAllAnts[i]->position(x, y+1))
            {
                bugCreation = false;
            }
        }
        if (bugCreation)
        {
            Doodlebug::forAllDoodlebugs[Doodlebug::doodlebugCounter++] = new Doodlebug(x, y+1);
            bugAge = 0;
            return;
        }
    }

    if (y>0) {
        
		bugCreation = true;

		for (int i=0; i<Doodlebug::doodlebugCounter; i++)
        {
			if (Doodlebug::forAllDoodlebugs[i]->position(x, y-1))
            {//up/forward position creation
				bugCreation = false;
            }
        }
		for (int i=0; i<Ant::antCounter; i++)
        {
			if (Ant::forAllAnts[i]->position(x, y-1))
            {
				bugCreation = false;
            }
        }
		if (bugCreation)
        {
			Doodlebug::forAllDoodlebugs[Doodlebug::doodlebugCounter++] = new Doodlebug(x, y-1);
			bugAge = 0;
			return;	
		}
	}
}//end of doodlebug::spawn()

//--------------------------------------------------------------------------------------------------------------

void Doodlebug::starve()
{
	starvePeriod++;
    
	if (starvePeriod > 3)//3 days
    {
		int iDoodlebug; //re-intializing
        
		for (int i=0; i<doodlebugCounter; i++)
        {
			if (forAllDoodlebugs[i] == this)
            {
				iDoodlebug = i;//new doodlebug
            }
        }
		Doodlebug *temp = forAllDoodlebugs[iDoodlebug];
		
		for (int i=iDoodlebug; i<doodlebugCounter-1; i++)
        
            forAllDoodlebugs[i] = forAllDoodlebugs[i+1];
            doodlebugCounter--;//starving bugs
            delete(temp);
    
    }
}//end of doodlebug::starve()

