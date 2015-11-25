//			Brandon Brewster
//			3/30/15
//			graphics.h



# include <iostream> 
# include <curses.h>
# include "LinkedList.h"
#include <string>
#include <fstream>

using namespace std;


class graphics 
{
    WINDOW *wnd;

    struct actor
    {
	int x;
	int y;
	char id;
    };


    actor player;
    int numcols;
    int numrows;
    int defaultx;
    int defaulty;

    char bumpCheck( char direction );

public:
    graphics();
    ~graphics();

    void setup( string map );
    void moveActor( char direction );
    //void displayMessage( string message );

};
