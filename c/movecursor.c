#include<ncurses.h>

int main(){

	initscr();
    raw();

    int number = 4;

    printw("Number %d position 0,0",number);

    move(10,10);

    printw("Number %d position 10,10",number);

    getch();
    endwin();

    return 0;
}
