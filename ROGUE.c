/*بسم الله الرحمن الرحیم
403110003     
seyed mohammad moein mirmohammadi */
#include<stdio.h>
#include<ncurses.h>
#include <string.h>

void draw_title(WINDOW *win, int starty, int startx, const char *text) {
    // چاپ عنوان بزرگ
    wattron(win, A_BOLD); // فعال کردن حالت برجسته
    mvwprintw(win, starty    , startx, " ####   ###   ###  #   # #####");
    mvwprintw(win, starty + 1, startx, " #   # #   # #     #   # #    ");
    mvwprintw(win, starty + 2, startx, " ####  #   # #  ## #   # #### ");
    mvwprintw(win, starty + 3, startx, " # #   #   # #   # #   # #    ");
    mvwprintw(win, starty + 4, startx, " #  ##  ###   ###   ###  #####");
    wattroff(win, A_BOLD); // غیرفعال کردن حالت برجسته
}

void draw_buttons(WINDOW *win, int starty, int startx1, int startx2, int selected) {
    // چاپ دکمه‌ها
    if (selected == 0) wattron(win, A_REVERSE);
    mvwprintw(win, starty, startx1, "[ Sign In ]");
    if (selected == 0) wattroff(win, A_REVERSE);

    if (selected == 1) wattron(win, A_REVERSE);
    mvwprintw(win, starty, startx2, "[ Sign Up ]");
    if (selected == 1) wattroff(win, A_REVERSE);
}

int main() {
    FILE *information;
    information=fopen("information.txt","w");
    fclose(information);
    initscr();                // شروع ncurses
    cbreak();                 // غیرفعال کردن بافر خطی
    noecho();                 // جلوگیری از چاپ ورودی کاربر
    curs_set(0);              // مخفی کردن نشانگر
    keypad(stdscr, TRUE);     // فعال کردن کلیدهای خاص

    int height, width;
    getmaxyx(stdscr, height, width); // گرفتن ابعاد صفحه

    int title_width = 29; // عرض تقریبی عبارت ROGUE
    int title_startx = (width - title_width) / 2;
    int title_starty = (height / 2) - 4;

    int button_starty = title_starty + 6;
    int button_width = 12; // عرض هر دکمه
    int button1_startx = (width / 2) - button_width - 2; // محل دکمه اول
    int button2_startx = (width / 2) + 2;               // محل دکمه دوم

    int selected = 0; // دکمه انتخاب شده (0 = Sign In, 1 = Sign Up)

    while (1) {
        clear(); // پاک کردن صفحه
        draw_title(stdscr, title_starty, title_startx, "ROGUE");
        draw_buttons(stdscr, button_starty, button1_startx, button2_startx, selected);
        refresh();

        int ch = getch();
        switch (ch) {
            case KEY_LEFT:
                selected = 0; // انتخاب Sign In
                break;
            case KEY_RIGHT:
                selected = 1; // انتخاب Sign Up
                break;
            case 10: // Enter key
                if (selected == 0) {
                    endwin();
                    printf("Sign In selected\n");
                    return 0;
                } else if (selected == 1) {
                    endwin();
                    printf("Sign Up selected\n");
                    return 0;
                }
                break;
            case 'q': // خروج با کلید q
                endwin();
                return 0;
        }
    }
   

    endwin(); // پایان ncurses
    return 0;
}