/* cursed adventure v2
 * Brandon Brewster
 */

#include <iostream>
#include <fstream>
#include <string>
#include <curses.h>

using namespace std;

#include "graphics.h"

/* necessary classes
 *
 * #include "character.h"
 * #include "item.h"
 * #include "npc.h"
 */

int main()
{
    int input;
    string mapName = "ship.map";
    graphics window;
    keypad( stdscr, TRUE );
    window.setup( mapName );

    input = getch();
    bool done = false;
    while( !done )
    {
	input = getch();
	switch( input ) 
	{
	    case KEY_UP: window.moveActor( 'N' );
		break;
	    case KEY_DOWN: window.moveActor( 'S' );
		break;
	    case KEY_LEFT: window.moveActor( 'W' );
		break;
	    case KEY_RIGHT: window.moveActor( 'E' );
		break;
	    default: done = true;
	}
    }
    return 0;
}
