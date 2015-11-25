//			Brandon Brewster
//			3/30/15
//			lab 9



#include <iostream> 
#include <curses.h>
#include <string>
#include <fstream>

using namespace std;

#include "graphics.h"

graphics::graphics()
{
    numcols = 70;
    numrows = 34;
    defaultx = 0;
    defaulty = numrows;
    player.x = 50;
    player.y = 15;
    player.id = '@';
    
    wnd = initscr();	//initializes the window
    noecho();
    clear();
    refresh();
}

graphics::~graphics()
{
    endwin();
    cout << "The window has been returned." << endl;
}

/* Sets up the room, adding walls, and the robot */
void graphics::setup( string map ) 
{
    ifstream data;
    data.open( "ship.map" );
    
    int i;
	    
    for( int i = 0; i < numrows; i++ )
    {
    char c = '0';
	for( int j = 0; c != ';'; j++ )
	{
	    data >> noskipws >> c;
	    if( c != ';' ) {
		move ( i, j );
		delch();
		insch( c );
	    }
	}
    }

    move( player.y, player.x );
    delch();
    insch( player.id );

    refresh();
}

char graphics::bumpCheck(char direction )
{
    int checkRow = player.y;
    int checkColumn = player.x;
    switch (direction) {
    case 'W':
 	checkColumn = player.x-1;
	break;
    case 'E':
	checkColumn = player.x+1;
	break;
    case 'N':
	checkRow = player.y-1;
	break;
    case 'S':
	checkRow = player.y+1;
	break;
    default: return true;
    }

    move(checkRow, checkColumn);
    return inch();
}

void graphics::moveActor( char direction )
{
    char bump;
    if( bumpCheck( direction ) == ' ' ) {
	move(player.y, player.x);
	delch();
	insch(' ');
	switch (direction) {
	case 'W': 
	    player.x -= 1;
	    break;
	case 'E':
	    player.x += 1;
	    break;
	case 'N':
	    player.y -= 1;
	    break;
	case 'S':
	    player.y += 1;
	    break;
	}
	move(player.y, player.x);
	delch();
	insch(player.id);

    }
    move( defaulty, defaultx );
    refresh();
}

