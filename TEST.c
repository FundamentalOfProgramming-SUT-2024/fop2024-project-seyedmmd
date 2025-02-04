#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    initscr();   // آغاز حالت ncurses
    noecho();    // عدم نمایش کلید‌های ورودی
    curs_set(0); // مخفی کردن نشانگر

    // آرایه‌ای از رشته‌ها که ASCII art برای "YOU LOSE" را تعریف می‌کند
    char *youLoseArt[] = {
        " __   __  _______  __   __  _______  ______   _______ ",
        "|  | |  ||       ||  | |  ||       ||    _ | |       |",
        "|  |_|  ||    ___||  | |  ||    ___||   | || |    ___|",
        "|       ||   |___ |  |_|  ||   |___ |   |_||_|   |___ ",
        "|       ||    ___||       ||    ___||    __  |    ___|",
        "|   _   ||   |___  |     | |   |___ |   |  | |   |___ ",
        "|__| |__||_______|  |___|  |_______||___|  |_|_______|"};

    // تعداد خطوط ASCII art
    int artLines = sizeof(youLoseArt) / sizeof(youLoseArt[0]);

    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x); // دریافت ابعاد صفحه

    // محاسبه موقعیت شروع به گونه‌ای که متن در وسط صفحه قرار بگیرد
    int start_y = (max_y - artLines) / 2;
    int max_line_length = 0;
    for (int i = 0; i < artLines; i++)
    {
        int len = strlen(youLoseArt[i]);
        if (len > max_line_length)
            max_line_length = len;
    }
    int start_x = (max_x - max_line_length) / 2;

    // چاپ هر خط از ASCII art در موقعیت مناسب
    for (int i = 0; i < artLines; i++)
    {
        mvprintw(start_y + i, start_x, "%s", youLoseArt[i]);
    }

    refresh(); // به‌روزرسانی صفحه
    getch();   // منتظر فشردن یک کلید از کاربر
    endwin();  // خروج از حالت ncurses

    return 0;
}
