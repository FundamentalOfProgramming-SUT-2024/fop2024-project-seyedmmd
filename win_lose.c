#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <wchar.h>
#include <unistd.h>
int WIDTH, HEIGHT;

void color()
{
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_RED);
    init_pair(2, COLOR_RED, COLOR_CYAN);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_BLACK, COLOR_GREEN);
    init_pair(5, COLOR_BLACK, COLOR_GREEN);
}

void margin()
{
    attron(A_BOLD);

    getmaxyx(stdscr, HEIGHT, WIDTH);
    mvprintw(20, 20, "%d %d", WIDTH, HEIGHT);

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            int num_char = (rand() % 26 + 65); // انتخاب کد کاراکتر های کپتال حروف
            if (x == 0 || x == WIDTH - 1)
                mvaddch(y, x, num_char);
            else if ((y == 0 && x % 2 == 0) || (y == HEIGHT - 1 && x % 2 == 0))
                mvaddch(y, x, num_char);
            else if (x == 1 || x == WIDTH - 2)
                mvaddch(y, x, ' ');
            else if ((y == 1 || y == HEIGHT - 2) && (x == 2 || x == WIDTH - 3))
                mvaddch(y, x, ' ');
            else if (y == 2 || y == HEIGHT - 3)
                mvaddch(y, x, '=');
            else if ((x == 2 && y != 2) || x == WIDTH - 3 && y != 2)
                mvaddch(y, x, '|');
        }
    }
    attroff(A_BOLD);
}

void win_lose()
{
    for (int i = 0; i < 70; i++)
    {
        int n = i;
        n = n % 6;
        attron(COLOR_PAIR(n));
        margin();
        attroff(COLOR_PAIR(n));
        refresh();
        napms(50);
    }
    if (win == 0)
    {
        mvprintw(22, 90, " YOU LOSE");
        mvwprintw(23, 87, "your score is %d", score);
    }
    else if (win == 1)
    {
        mvprintw(22, 90, " YOU WIN");
        mvwprintw(23, 87, "your score is %d", score);
    }
}
int main()
{
    initscr();
    color();
    noecho();
    keypad(stdscr, TRUE);
    cbreak();
    curs_set(0);
    win_lose();
    endwin();
}