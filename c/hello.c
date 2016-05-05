#include <ncurses.h>

int main(){
    
    initscr();

    raw();

    printw("Hello ncurses");

    getch();

    endwin();

    return 0;

}
