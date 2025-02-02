#include <locale.h>
#include <ncurses.h>
#include <wchar.h>

int main(void)
{
    // تنظیم locale به گونه‌ای که از UTF-8 پشتیبانی شود
    setlocale(LC_ALL, "");

    // شروع محیط ncurses
    initscr();
    cbreak();
    noecho();

    // تعریف رشته wide شامل کاراکتر U+2692
    wchar_t symbol_str[] = L"\u2692";

    // چاپ کاراکتر در موقعیت (5,5)
    mvaddwstr(5, 5, symbol_str);

    refresh();
    getch();
    endwin();
    return 0;
}
