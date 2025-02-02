/*بسم الله الرحمن الرحیم
403110003
seyed mohammad moein mirmohammadi */
#include <stdio.h>
#include <ncurses.h>
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

// تابع برای بررسی اعتبار پسورد
int password_validity(char *password)
{
    int captal, small, num, length;
    captal = small = num = length = 0;

    for (int i = 0; password[i] != '\0'; i++)
    {
        if (password[i] < 91 && password[i] > 64) // code ASCII for captal letter
            captal = 1;
        else if (password[i] < 123 && password[i] > 96) // code ASCII for small letter
            small = 1;
        else if (password[i] < 58 && password[i] > 47) // code ASCII for numbers
            num = 1;
        length += 1;
    }
    if ((captal + small + num) == 3 && length > 6)
        return 1;
    else
        return 0;
}

// تابع برای بررسی اعتبار ایمیل
int Email_validity(char *email)
{
    int check, number_at, number_dot;
    check = number_at = number_dot = 0;
    for (int i = 0; email[i] != '\0'; i++)
    {
        if (email[i] == '@')
        {
            check += 1;
            number_at = i;
        }
        else if (email[i] == '.')
        {
            check += 1;
            number_dot = i;
        }
    }
    if ((number_dot - number_at) > 1)
        check += 1;
    if (number_at > 2)
        check += 1;
    if (number_dot < (strlen(email) - 2))
        check += 1;
    if (check == 5)
        return 1;
    else
        return 0;
}

#define max_size 30
int main()
{

    initscr();
    cbreak();
    echo();
    keypad(stdscr, TRUE);

    while (1)
    {
        echo();
        char username[max_size];
        char password[max_size];
        char repeat_password[max_size];
        char Email[2 * max_size];

        const char *text = "Sign Up Now!";
        const char *text2 = "press the <Ctrl + B> to back";

        int height, width;
        getmaxyx(stdscr, height, width);

        int x = (width - strlen(text)) / 2;
        int y1 = 0;
        int y2 = (height - 1);
        int y3 = (height / 2 - 8);

        mvprintw(y1, x, "%s", text);
        mvprintw(y2, x, "%s", text2);

        input_box(y3, x - 5, 5, 40); // input username
        mvprintw(y3 + 2, x - 4, "Username: ");
        getnstr(username, max_size);

        if (strlen(username) == 0) // خالی نبودن نام کاربری
            mvprintw(y3 - 1, x, "please enter the username!");
        else
        {

            if (strstr(username, " ") != NULL) // معتبر بودن نام کاربری
                mvprintw(y3 - 1, x, "please enter the username without \" \"");
            else
            {
                mvprintw(y3 - 1, x, "                                        ");
                strcat(username, ".txt");

                FILE *user;
                user = fopen(username, "r");

                if (user || strlen(username) == 4)
                {
                    mvprintw(y3 - 1, x, "username already exists; try again.");
                    fclose(user);
                }
                else
                {

                    mvprintw(y3 - 1, x, "                                    ");

                    input_box(y3 + 6, x - 5, 5, 40); // input password
                    mvprintw(y3 + 8, x - 4, "password: ");
                    getnstr(password, max_size);

                    if (password_validity(password) == 0)
                        mvprintw(y3 + 5, x - 40, "The password must contain one lowercase letter, one uppercase letter, and one number. also ,its length must be greater than 7 characters.");
                    else
                    {
                        mvprintw(y3 + 5, x - 40, "                                                                                                                                          ");

                        input_box(y3 + 12, x - 5, 5, 40); // input reapeat password
                        mvprintw(y3 + 14, x - 4, "repeat password: ");
                        getnstr(repeat_password, max_size);
                        if (strcmp(password, repeat_password) != 0)
                            mvprintw(y3 + 11, x - 5, "the passwords do not match");
                        else
                        {
                            mvprintw(y3 + 11, x - 5, "                           ");

                            input_box(y3 + 18, x - 5, 5, 40); // input Email
                            mvprintw(y3 + 20, x - 4, "your Email: ");
                            getnstr(Email, 2 * max_size);

                            if (Email_validity(Email) == 0)
                                mvprintw(y3 + 17, x - 5, "your email is invalid(valid format: xxx@y.zzz)");
                            else
                            {
                                mvprintw(y3 + 17, x - 5, "                                               ");
                                mvprintw(y3 + 24, x - 5, "press <Enter> to save information or any key for edit");

                                char a = getch();
                                if (a == 10) // code ASCII for ENTER KEY
                                {
                                    FILE *user2;
                                    user2 = fopen(username, "w");
                                    fprintf(user2, password);
                                    fprintf(user2, "\n---------------------------------------------------------\n");
                                    fprintf(user2, Email);
                                    fclose(user2);
                                }
                            }
                        }
                    }
                }
            }
        }
        char c = getch();
        if (c == 2) // کد ascii برای کلید ترکیبی <ctrl+b>   |    back
            break;
    }
    refresh();
    endwin();
}