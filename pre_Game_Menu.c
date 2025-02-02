#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
void pre_game_menu()
{
    initscr();
    noecho();
    cbreak();

    int WIDTH, HEIGHT;
    getmaxyx(stdscr, WIDTH, HEIGHT);

    int width = 40;
    int height = 40;
    int startx = HEIGHT / 2 - height / 2;
    int starty = WIDTH / 2 - width / 2;
    WINDOW *kadr = newwin(height, width, startx, starty);
    box(kadr, 0, 0);
    getch();
    endwin();
}
int main()
{

    initscr();
    noecho();
    cbreak();

    int WIDTH, HEIGHT;
    getmaxyx(stdscr, WIDTH, HEIGHT);

    int width = 40;
    int height = 40;
    int startx = HEIGHT / 2 - height / 2;
    int starty = WIDTH / 2 - width / 2;
    WINDOW *kadr = newwin(height, width, startx, starty);
    box(kadr, 0, 0);
    getch();
    endwin();
    return 0;
}