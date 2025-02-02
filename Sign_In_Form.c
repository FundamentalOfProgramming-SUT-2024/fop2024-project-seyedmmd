#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
// تابع برای ساخت قاب مستطیلی دور یوزرنیم و پسورد
void input_box(int starty, int startx, int height, int width)
{
    attron(A_BOLD);
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (y == 0 || y == height - 1)
            {
                mvaddch(starty + y, startx + x, '=');
            }
            else if (x == 0 || x == width - 1)
            {
                mvaddch(starty + y, startx + x, '#');
            }
            else
            {
                mvaddch(starty + y, startx + x, ' ');
            }
        }
    }
    attroff(A_BOLD);
}

// تابع برای ساخت رنگ ها
void init_colors()
{
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_BLACK, COLOR_CYAN);
}

#define max_size 30

int main()
{
    /*

    */
    initscr();
    cbreak();
    echo();
    keypad(stdscr, TRUE);
    /*


    */
    while (1)
    {
        echo();
        char username[max_size];
        char password[max_size];
        const char *text = "Sign In Now!";
        const char *text2 = "press the <Ctrl + B> to back";
        const char *text3 = "press the <Ctrl + G> to login as a GUEST USER!";
        int height, width;
        getmaxyx(stdscr, height, width);
        int x = (width - strlen(text)) / 2;
        int y = 0;
        int x2 = (width - strlen(text2)) / 2;
        int y2 = (height - 1);
        int y3 = (height / 2 - 5);

        // چاپ متن در موقعیت محاسبه شده
        mvprintw(y, x, "%s", text);
        mvprintw(y2, x2, "%s", text2);
        mvprintw(y2 - 3, x2 - 5, "%s", text3);

        input_box(y3, x2 - 5, 5, 40);
        mvprintw(y3 + 2, x2 - 4, "Username: ");
        getnstr(username, max_size);
        strcat(username, ".txt");

        FILE *user;
        char user_data[max_size];
        user = fopen(username, "r");

        int check_username = 0;

        if (user == NULL)
            mvprintw(y3 - 2, x2 - 5, "usernam not found; try again by pressing <Enter>");
        else
        {
            mvprintw(y3 - 2, x2 - 5, "                                                      ");
            check_username = 1;
            input_box(y3 + 4, x2 - 5, 5, 40);
            mvprintw(y3 + 6, x2 - 4, "Password: ");
            getnstr(password, max_size);
            fgets(user_data, strlen(password) + 1, user);
        }
        if (strcmp(password, user_data) == 0)
        {
            mvprintw(y3 + 10, x2 - 5, "                         ");
            clear();
            printw("welcom!");
            getch();
        }
        else
        {
            if (check_username != 0)
                mvprintw(y3 + 10, x2 - 5, "The password is incorrect");
        }
        noecho();
        char c = getch();
        if (c == 2) // کد ascii برای کلید ترکیبی <ctrl+b>   |    back
            break;
        else if (c == 7) // کد ascii برای کلید ترکیبی <ctrl+g>  |   guest
        {
            clear();
            getch();
        }
    }
    refresh();
    endwin();
}