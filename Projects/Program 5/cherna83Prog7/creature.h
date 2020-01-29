//cherna83
//creature HeaderFile

#ifndef INSECT_H
#define INSECT_H

class Insect
{
 protected:
	int x, y;
	int bugAge;
	int starvePeriod;

 public:
	Insect(int x, int y)
    {
		this->x = x;
		this->y = y;
		bugAge = 0;
		starvePeriod = 0;
	}
	bool position(int x1, int y1)
    {
        return ((x == x1) && (y == y1));
    }
	int getX()
    {
        return x;
        
    }
	int getY()
    {
        return y;
    }
	virtual void move(int x, int y)
    {
        this->x = x; this->y = y;
    }
};

#endif
