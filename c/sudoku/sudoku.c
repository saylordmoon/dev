#include <ncurses.h>
#include <stdio.h>

enum {
	ESC_KEY = 27,
	ARROW_UP = 256 + 72
};

static int get_code();


int main(int argc, char const *argv[])
{
	int x,y;
	char key;
	initscr();
	raw();
	
	while ((key = get_code()) != 'q')
	{
		getyx(stdscr,x,y);
		//printw(key);
		//printw("%d === %d" , x , y);
	}

	endwin();
	return 0;
}

static int get_code() 
{
	int x,y;
	noecho();
	int ch = getch();
	char key;

	getyx(stdscr,y,x);

	if (ch == 27){
		

		/* Arrow keys linux */
		if (getch() == 91) {

			int ch3 = getch();

			switch(ch3)
			{
				case 65:
					mvprintw(23,0,"UP   ");
					break;
				case 66:
					mvprintw(23,0,"DOWN ");
					break;
				case 67:
					mvprintw(23,0,"RIGHT");
					break;
				case 68:
					mvprintw(23,0,"LEFT ");
					break;
			}

			move(y,x);
			
		}
	}
	else
	{
		key = ch;
		printw("%c",key);
	}

	return ch;
}