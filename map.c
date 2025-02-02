#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <wchar.h>

int WIDTH, HEIGHT;
int startx[35];
int starty[35];
int height[35];
int width[35];
int x_door_down[50], y_door_down[50];
int x_door_up[50], y_door_up[50];
int x_door_left[50], y_door_left[50];
int x_door_right[50], y_door_right[50];

char map1[45][184];
char map2[45][184];

char floor1_food[45][184];
int x_floor1_food[2];
int y_floor1_food[2];
int statuse_food_floor1[2];
int food_floor1[2];

int stair1;
void color()
{
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_RED);
    init_pair(2, COLOR_RED, COLOR_CYAN);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_BLACK, COLOR_GREEN);
    init_pair(5, COLOR_BLACK, COLOR_GREEN);
}

void room1()
{
    starty[0] = rand() % 5 + 4;
    startx[0] = rand() % 10 + 3;
    height[0] = rand() % 10 + 6;
    width[0] = rand() % 15 + 6;

    x_door_down[0] = rand() % (width[0] - 2);
    y_door_down[0] = height[0] - 1;

    attron(A_BOLD);
    for (int y = 0; y < height[0]; y++)
    {
        for (int x = 0; x < width[0]; x++)
        {
            if (y == y_door_down[0] && (x == x_door_down[0] + 1))
            {

                map1[starty[0] + y][startx[0] + x] = '=';
            }
            else if ((x == 0 || x == width[0] - 1) && y != 0)
            {

                map1[starty[0] + y][startx[0] + x] = '|';
            }
            else if (y == 0 || y == height[0] - 1)
            {
                map1[starty[0] + y][startx[0] + x] = '_';
            }

            else
            {
                map1[starty[0] + y][startx[0] + x] = '.';
            }
        }
    }
    attroff(A_BOLD);

    starty[1] = rand() % 10 + 4;
    startx[1] = rand() % 10 + 40;
    height[1] = rand() % 10 + 6;
    width[1] = rand() % 15 + 6;

    x_door_down[1] = rand() % (width[1] - 2);
    y_door_down[1] = height[1] - 1;

    x_door_right[1] = width[1] - 1;
    y_door_right[1] = rand() % (height[1] - 2);

    attron(A_BOLD);
    for (int y = 0; y < height[1]; y++)
    {
        for (int x = 0; x < width[1]; x++)
        {
            if (y == y_door_down[1] && (x == x_door_down[1] + 1))
            {

                map1[starty[1] + y][startx[1] + x] = '=';
            }
            else if (y == y_door_right[1] + 1 && (x == x_door_right[1]))
            {
                map1[starty[1] + y][startx[1] + x] = '=';
            }
            else if ((x == 0 || x == width[1] - 1) && y != 0)
            {
                map1[starty[1] + y][startx[1] + x] = '|';
            }
            else if (y == 0 || y == height[1] - 1)
            {
                map1[starty[1] + y][startx[1] + x] = '_';
            }

            else
            {
                map1[starty[1] + y][startx[1] + x] = '.';
            }
        }
    }
    attroff(A_BOLD);

    starty[2] = rand() % 10 + 4;
    startx[2] = rand() % 10 + 90;
    height[2] = rand() % 10 + 6;
    width[2] = rand() % 15 + 6;

    x_door_down[2] = rand() % (width[2] - 2);
    y_door_down[2] = height[2] - 1;

    x_door_left[2] = 0;
    y_door_left[2] = rand() % (height[2] - 2);

    x_door_right[2] = width[2] - 1;
    y_door_right[2] = rand() % (height[2] - 2);

    attron(A_BOLD);
    for (int y = 0; y < height[2]; y++)
    {
        for (int x = 0; x < width[2]; x++)
        {
            if (y == y_door_down[2] && (x == x_door_down[2] + 1))
            {

                map1[starty[2] + y][startx[2] + x] = '=';
            }
            else if ((y == y_door_left[2] + 1) && (x == x_door_left[2]))
            {

                map1[starty[2] + y][startx[2] + x] = '=';
            }
            else if ((y == y_door_right[2] + 1) && (x == x_door_right[2]))
            {

                map1[starty[2] + y][startx[2] + x] = '=';
            }
            else if ((x == 0 || x == width[2] - 1) && y != 0)
            {
                map1[starty[2] + y][startx[2] + x] = '|';
            }
            else if (y == 0 || y == height[2] - 1)
            {
                map1[starty[2] + y][startx[2] + x] = '_';
            }

            else
            {
                map1[starty[2] + y][startx[2] + x] = '.';
            }
        }
    }
    attroff(A_BOLD);

    starty[3] = rand() % 10 + 4;
    startx[3] = rand() % 10 + 130;
    height[3] = rand() % 10 + 6;
    width[3] = rand() % 15 + 6;

    x_door_left[3] = 0;
    y_door_left[3] = rand() % (height[3] - 2);

    x_door_right[3] = width[3] - 1;
    y_door_right[3] = rand() % (height[3] - 2);

    attron(A_BOLD);
    for (int y = 0; y < height[3]; y++)
    {
        for (int x = 0; x < width[3]; x++)
        {
            if (y == y_door_left[3] + 1 && (x == x_door_left[3]))
            {
                map1[starty[3] + y][startx[3] + x] = '=';
            }
            else if (y == y_door_right[3] + 1 && (x == x_door_right[3]))
            {
                map1[starty[3] + y][startx[3] + x] = '=';
            }

            else if ((x == 0 || x == width[3] - 1) && y != 0)
            {
                map1[starty[3] + y][startx[3] + x] = '|';
            }
            else if (y == 0 || y == height[3] - 1)
            {
                map1[starty[3] + y][startx[3] + x] = '_';
            }

            else
            {
                map1[starty[3] + y][startx[3] + x] = '.';
            }
        }
    }
    attroff(A_BOLD);

    starty[4] = rand() % 3 + 30;
    startx[4] = rand() % 10 + 3;
    height[4] = rand() % 3 + 6;
    width[4] = rand() % 15 + 6;

    x_door_up[4] = rand() % (width[4] - 2);
    y_door_up[4] = 0;

    attron(A_BOLD);
    for (int y = 0; y < height[4]; y++)
    {
        for (int x = 0; x < width[4]; x++)
        {
            if (y == y_door_up[4] && (x == x_door_up[4] + 1))
            {
                map1[starty[4] + y][startx[4] + x] = '=';
            }
            else if ((x == 0 || x == width[4] - 1) && y != 0)
            {
                map1[starty[4] + y][startx[4] + x] = '|';
            }
            else if (y == 0 || y == height[4] - 1)
            {
                map1[starty[4] + y][startx[4] + x] = '_';
            }

            else
            {
                map1[starty[4] + y][startx[4] + x] = '.';
            }
        }
    }
    attroff(A_BOLD);

    starty[5] = rand() % 3 + 30;
    startx[5] = rand() % 10 + 50;
    height[5] = rand() % 3 + 6;
    width[5] = rand() % 30 + 20;

    x_door_up[5] = rand() % (width[5] - 2);
    y_door_up[5] = 0;

    x_door_right[5] = width[5] - 1;
    y_door_right[5] = rand() % (height[5] - 2);

    attron(A_BOLD);
    for (int y = 0; y < height[5]; y++)
    {
        for (int x = 0; x < width[5]; x++)
        {
            if (y == y_door_right[5] + 1 && (x == x_door_right[5]))
            {
                map1[starty[5] + y][startx[5] + x] = '=';
            }
            else if (y == y_door_up[5] && (x == x_door_up[5] + 1))
            {

                map1[starty[5] + y][startx[5] + x] = '=';
            }
            else if ((x == 0 || x == width[5] - 1) && y != 0)
            {
                map1[starty[5] + y][startx[5] + x] = '|';
            }
            else if (y == 0 || y == height[5] - 1)
            {
                map1[starty[5] + y][startx[5] + x] = '_';
            }

            else
            {
                map1[starty[5] + y][startx[5] + x] = '.';
            }
        }
    }
    attroff(A_BOLD);

    starty[6] = rand() % 3 + 30;
    startx[6] = rand() % 10 + 115;
    height[6] = rand() % 3 + 6;
    width[6] = rand() % 20 + 20;

    x_door_left[6] = 0;
    y_door_left[6] = rand() % (height[6] - 2);

    attron(A_BOLD);
    for (int y = 0; y < height[6]; y++)
    {
        for (int x = 0; x < width[6]; x++)
        {
            if (y == y_door_left[6] + 1 && (x == x_door_left[6]))
            {

                map1[starty[6] + y][startx[6] + x] = '=';
            }
            else if ((x == 0 || x == width[6] - 1) && y != 0)
            {
                map1[starty[6] + y][startx[6] + x] = '|';
            }
            else if (y == 0 || y == height[6] - 1)
            {
                map1[starty[6] + y][startx[6] + x] = '_';
            }

            else
            {
                map1[starty[6] + y][startx[6] + x] = '.';
            }
        }
    }
    attroff(A_BOLD);
}

///////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
void room2()
{
    attron(A_BOLD);

    starty[7] = rand() % 3 + 4;
    startx[7] = rand() % 10 + 3;
    height[7] = rand() % 10 + 6;
    width[7] = rand() % 15 + 6;

    x_door_down[7] = rand() % (width[0] - 2);
    y_door_down[7] = height[0] - 1;

    x_door_right[7] = width[7] - 1;
    y_door_right[7] = rand() % (height[7] - 2);

    attron(A_BOLD);
    for (int y = 0; y < height[7]; y++)
    {
        for (int x = 0; x < width[7]; x++)
        {
            if (y == y_door_down[7] && (x == x_door_down[7] + 1))
            {

                map1[starty[7] + y][startx[7] + x] = '=';
            }
            else if ((y == y_door_right[7] + 1) && (x == x_door_right[7]))
            {
                map2[starty[7] + y][startx[7] + x] = '=';
            }
            else if ((x == 0 || x == width[7] - 1) && y != 0)
            {

                map1[starty[7] + y][startx[7] + x] = '|';
            }
            else if (y == 0 || y == height[7] - 1)
            {
                map1[starty[7] + y][startx[7] + x] = '_';
            }

            else
            {
                map1[starty[0] + y][startx[0] + x] = '.';
            }
        }
    }
    attroff(A_BOLD);

    starty[8] = rand() % 3 + 4;
    startx[8] = rand() % 10 + 140;
    height[8] = rand() % 1 + 6;
    width[8] = rand() % 15 + 10;

    x_door_left[8] = 0;
    y_door_left[8] = rand() % (height[8] - 2);

    x_door_down[8] = rand() % (width[8] - 2);
    y_door_down[8] = height[8] - 1;

    attron(A_BOLD);
    for (int y = 0; y < height[8]; y++)
    {
        for (int x = 0; x < width[8]; x++)
        {
            if (y == y_door_left[8] + 1 && (x == x_door_left[8]))
            {
                map2[starty[8] + y][startx[8] + x] = '=';
            }
            else if (y == y_door_down[8] && (x == x_door_down[8] + 1))
            {
                map2[starty[8] + y][startx[8] + x] = '=';
            }

            else if ((x == 0 || x == width[8] - 1) && y != 0)
            {
                map2[starty[8] + y][startx[8] + x] = '|';
            }
            else if (y == 0 || y == height[8] - 1)
            {
                map2[starty[8] + y][startx[8] + x] = '_';
            }

            else
            {
                map2[starty[8] + y][startx[8] + x] = '.';
            }
        }
    }
    attroff(A_BOLD);

    starty[9] = rand() % 5 + 4;
    startx[9] = rand() % 10 + 48;
    height[9] = rand() % 5 + 6;
    width[9] = rand() % 15 + 15;

    x_door_down[9] = rand() % (width[9] - 2);
    y_door_down[9] = height[9] - 1;

    x_door_right[9] = width[9] - 1;
    y_door_right[9] = rand() % (height[9] - 2);

    attron(A_BOLD);
    for (int y = 0; y < height[9]; y++)
    {
        for (int x = 0; x < width[9]; x++)
        {
            if (y == y_door_down[9] && (x == x_door_down[9] + 1))
            {

                map2[starty[9] + y][startx[9] + x] = '=';
            }
            else if (y == y_door_right[9] + 1 && (x == x_door_right[9]))
            {
                map2[starty[9] + y][startx[9] + x] = '=';
            }
            else if ((x == 0 || x == width[9] - 1) && y != 0)
            {
                map2[starty[9] + y][startx[9] + x] = '|';
            }
            else if (y == 0 || y == height[9] - 1)
            {
                map2[starty[9] + y][startx[9] + x] = '_';
            }

            else
            {
                map2[starty[9] + y][startx[9] + x] = '.';
            }
        }
    }
    attroff(A_BOLD);

    starty[10] = rand() % 15 + 4;
    startx[10] = rand() % 10 + 92;
    height[10] = rand() % 5 + 6;
    width[10] = rand() % 15 + 15;

    x_door_down[10] = rand() % (width[10] - 2);
    y_door_down[10] = height[10] - 1;

    x_door_left[10] = 0;
    y_door_left[10] = rand() % (height[10] - 2);

    x_door_up[10] = rand() % (width[10] - 2);
    y_door_up[10] = 0;

    attron(A_BOLD);
    for (int y = 0; y < height[10]; y++)
    {
        for (int x = 0; x < width[10]; x++)
        {
            if (y == y_door_down[10] && (x == x_door_down[10] + 1))
            {

                map2[starty[10] + y][startx[10] + x] = '=';
            }
            else if (y == y_door_left[10] + 1 && (x == x_door_left[10]))
            {

                map2[starty[10] + y][startx[10] + x] = '=';
            }
            else if (y == y_door_up[10] && (x == x_door_up[10] + 1))
            {

                map2[starty[10] + y][startx[10] + x] = '=';
            }
            else if ((x == 0 || x == width[10] - 1) && y != 0)
            {
                map2[starty[10] + y][startx[10] + x] = '|';
            }
            else if (y == 0 || y == height[10] - 1)
            {
                map2[starty[10] + y][startx[10] + x] = '_';
            }

            else
            {
                map2[starty[10] + y][startx[10] + x] = '.';
            }
        }
    }
    attroff(A_BOLD);

    starty[11] = rand() % 15 + 4;
    startx[11] = rand() % 10 + 137;
    height[11] = rand() % 1 + 6;
    width[11] = rand() % 15 + 10;

    x_door_up[11] = rand() % (width[11] - 2);
    y_door_up[11] = 0;

    attron(A_BOLD);
    for (int y = 0; y < height[11]; y++)
    {
        for (int x = 0; x < width[11]; x++)
        {
            if (y == y_door_up[11] && (x == x_door_up[11] + 1))
            {
                map2[starty[11] + y][startx[11] + x] = '=';
            }
            else if ((x == 0 || x == width[11] - 1) && y != 0)
            {
                map2[starty[11] + y][startx[11] + x] = '|';
            }
            else if (y == 0 || y == height[11] - 1)
            {
                map2[starty[11] + y][startx[11] + x] = '_';
            }

            else
            {
                map2[starty[11] + y][startx[11] + x] = '.';
            }
        }
    }
    attroff(A_BOLD);

    starty[12] = rand() % 3 + 25;
    startx[12] = rand() % 10 + 3;
    height[12] = rand() % 10 + 6;
    width[12] = rand() % 15 + 6;

    x_door_up[12] = rand() % (width[12] - 2);
    y_door_up[12] = 0;

    x_door_right[12] = width[12] - 1;
    y_door_right[12] = rand() % (height[12] - 2);

    attron(A_BOLD);
    for (int y = 0; y < height[12]; y++)
    {
        for (int x = 0; x < width[12]; x++)
        {
            if (y == y_door_up[12] && (x == x_door_up[12] + 1))
            {
                map2[starty[12] + y][startx[12] + x] = '=';
            }
            else if ((y == y_door_right[12] + 1) && (x == x_door_right[12]))
            {
                map2[starty[12] + y][startx[12] + x] = '=';
            }
            else if ((x == 0 || x == width[12] - 1) && y != 0)
            {
                map2[starty[12] + y][startx[12] + x] = '|';
            }
            else if (y == 0 || y == height[12] - 1)
            {
                map2[starty[12] + y][startx[12] + x] = '_';
            }

            else
            {
                map2[starty[12] + y][startx[12] + x] = '.';
            }
        }
    }
    attroff(A_BOLD);

    /*







    */
}
void print_room(int n)
{

    if (n == 1)
    {
        attron(A_BOLD);
        for (int y = 0; y < height[0]; y++)
        {
            for (int x = 0; x < width[0]; x++)
            {
                if (map1[y + starty[0]][x + startx[0]] == '>')
                {
                    attron(COLOR_PAIR(5));
                    mvaddch(y + starty[0], x + startx[0], '>');
                    attroff(COLOR_PAIR(5));
                }
                else if (y == y_door_down[0] && (x == x_door_down[0] + 1))
                {
                    attron(COLOR_PAIR(1));
                    mvaddch(starty[0] + y, startx[0] + x, '=');
                    attroff(COLOR_PAIR(1));
                }
                else if ((x == 0 || x == width[0] - 1) && y != 0)
                {
                    mvaddch(starty[0] + y, startx[0] + x, '|');
                }
                else if (y == 0 || y == height[0] - 1)
                {
                    mvaddch(starty[0] + y, startx[0] + x, '_');
                }

                else
                {
                    mvaddch(starty[0] + y, startx[0] + x, '.');
                }
            }
        }
        attroff(A_BOLD);
    }

    else if (n == 2)
    {
        attron(A_BOLD);
        for (int y = 0; y < height[1]; y++)
        {
            for (int x = 0; x < width[1]; x++)
            {
                if (map1[y + starty[1]][x + startx[1]] == '>')
                {
                    attron(COLOR_PAIR(5));
                    mvaddch(y + starty[1], x + startx[1], '>');
                    attroff(COLOR_PAIR(5));
                }
                else if (y == y_door_down[1] && (x == x_door_down[1] + 1))
                {
                    attron(COLOR_PAIR(1));
                    mvaddch(starty[1] + y, startx[1] + x, '=');
                    attroff(COLOR_PAIR(1));
                }
                else if (y == y_door_right[1] + 1 && (x == x_door_right[1]))
                {
                    attron(COLOR_PAIR(1));
                    mvaddch(starty[1] + y, startx[1] + x, '=');
                    attroff(COLOR_PAIR(1));
                }
                else if ((x == 0 || x == width[1] - 1) && y != 0)
                {
                    mvaddch(starty[1] + y, startx[1] + x, '|');
                }
                else if (y == 0 || y == height[1] - 1)
                {
                    mvaddch(starty[1] + y, startx[1] + x, '_');
                }

                else
                {
                    mvaddch(starty[1] + y, startx[1] + x, '.');
                }
            }
        }
        attroff(A_BOLD);
    }

    else if (n == 3)
    {
        attron(A_BOLD);
        for (int y = 0; y < height[2]; y++)
        {
            for (int x = 0; x < width[2]; x++)
            {
                if (map1[y + starty[2]][x + startx[2]] == '>')
                {
                    attron(COLOR_PAIR(5));
                    mvaddch(y + starty[2], x + startx[2], '>');
                    attroff(COLOR_PAIR(5));
                }
                else if (y == y_door_down[2] && (x == x_door_down[2] + 1))
                {
                    attron(COLOR_PAIR(1));
                    mvaddch(starty[2] + y, startx[2] + x, '=');
                    attroff(COLOR_PAIR(1));
                }
                else if (y == y_door_left[2] + 1 && (x == x_door_left[2]))
                {
                    attron(COLOR_PAIR(1));
                    mvaddch(starty[2] + y, startx[2] + x, '=');
                    attroff(COLOR_PAIR(1));
                }
                else if (y == y_door_right[2] + 1 && (x == x_door_right[2]))
                {
                    attron(COLOR_PAIR(1));
                    mvaddch(starty[2] + y, startx[2] + x, '=');
                    attroff(COLOR_PAIR(1));
                }
                else if ((x == 0 || x == width[2] - 1) && y != 0)
                {
                    mvaddch(starty[2] + y, startx[2] + x, '|');
                }
                else if (y == 0 || y == height[2] - 1)
                {
                    mvaddch(starty[2] + y, startx[2] + x, '_');
                }

                else
                {
                    mvaddch(starty[2] + y, startx[2] + x, '.');
                }
            }
        }
        attroff(A_BOLD);
    }

    else if (n == 4)
    {
        attron(A_BOLD);
        for (int y = 0; y < height[3]; y++)
        {
            for (int x = 0; x < width[3]; x++)
            {
                if (map1[y + starty[3]][x + startx[3]] == '>')
                {
                    attron(COLOR_PAIR(5));
                    mvaddch(y + starty[3], x + startx[3], '>');
                    attroff(COLOR_PAIR(5));
                }
                else if (y == y_door_left[3] + 1 && (x == x_door_left[3]))
                {
                    attron(COLOR_PAIR(1));
                    mvaddch(starty[3] + y, startx[3] + x, '=');
                    attroff(COLOR_PAIR(1));
                }
                else if (y == y_door_right[3] + 1 && (x == x_door_right[3]))
                {
                    attron(COLOR_PAIR(1));
                    mvaddch(starty[3] + y, startx[3] + x, '=');
                    attroff(COLOR_PAIR(1));
                }

                else if ((x == 0 || x == width[3] - 1) && y != 0)
                {
                    mvaddch(starty[3] + y, startx[3] + x, '|');
                }
                else if (y == 0 || y == height[3] - 1)
                {
                    mvaddch(starty[3] + y, startx[3] + x, '_');
                }

                else
                {
                    mvaddch(starty[3] + y, startx[3] + x, '.');
                }
            }
        }
        attroff(A_BOLD);
    }

    else if (n == 5)
    {
        attron(A_BOLD);
        for (int y = 0; y < height[4]; y++)
        {
            for (int x = 0; x < width[4]; x++)
            {
                if (map1[y + starty[4]][x + startx[4]] == '>')
                {
                    attron(COLOR_PAIR(5));
                    mvaddch(y + starty[4], x + startx[4], '>');
                    attroff(COLOR_PAIR(5));
                }
                else if (y == y_door_up[4] && (x == x_door_up[4] + 1))
                {
                    attron(COLOR_PAIR(1));
                    mvaddch(starty[4] + y, startx[4] + x, '=');
                    attroff(COLOR_PAIR(1));
                }
                else if ((x == 0 || x == width[4] - 1) && y != 0)
                {
                    mvaddch(starty[4] + y, startx[4] + x, '|');
                }
                else if (y == 0 || y == height[4] - 1)
                {
                    mvaddch(starty[4] + y, startx[4] + x, '_');
                }

                else
                {
                    mvaddch(starty[4] + y, startx[4] + x, '.');
                }
            }
        }
        attroff(A_BOLD);
    }

    else if (n == 6)
    {
        attron(A_BOLD);
        for (int y = 0; y < height[5]; y++)
        {
            for (int x = 0; x < width[5]; x++)
            {
                if (map1[y + starty[5]][x + startx[5]] == '>')
                {
                    attron(COLOR_PAIR(5));
                    mvaddch(y + starty[5], x + startx[5], '>');
                    attroff(COLOR_PAIR(5));
                }
                else if (y == y_door_right[5] + 1 && (x == x_door_right[5]))
                {
                    attron(COLOR_PAIR(1));
                    mvaddch(starty[5] + y, startx[5] + x, '=');
                    attroff(COLOR_PAIR(1));
                }
                else if (y == y_door_up[5] && (x == x_door_up[5] + 1))
                {
                    attron(COLOR_PAIR(1));
                    mvaddch(starty[5] + y, startx[5] + x, '=');
                    attroff(COLOR_PAIR(1));
                }
                else if ((x == 0 || x == width[5] - 1) && y != 0)
                {
                    mvaddch(starty[5] + y, startx[5] + x, '|');
                }
                else if (y == 0 || y == height[5] - 1)
                {
                    mvaddch(starty[5] + y, startx[5] + x, '_');
                }

                else
                {
                    mvaddch(starty[5] + y, startx[5] + x, '.');
                }
            }
        }
        attroff(A_BOLD);
    }

    else if (n == 7)
    {
        attron(A_BOLD);
        for (int y = 0; y < height[6]; y++)
        {
            for (int x = 0; x < width[6]; x++)
            {
                if (map1[y + starty[6]][x + startx[6]] == '>')
                {
                    attron(COLOR_PAIR(5));
                    mvaddch(y + starty[6], x + startx[6], '>');
                    attroff(COLOR_PAIR(5));
                }
                else if (y == y_door_left[6] + 1 && (x == x_door_left[6]))
                {
                    attron(COLOR_PAIR(1));
                    mvaddch(starty[6] + y, startx[6] + x, '=');
                    attroff(COLOR_PAIR(1));
                }
                else if ((x == 0 || x == width[6] - 1) && y != 0)
                {
                    mvaddch(starty[6] + y, startx[6] + x, '|');
                }
                else if (y == 0 || y == height[6] - 1)
                {
                    mvaddch(starty[6] + y, startx[6] + x, '_');
                }

                else
                {
                    mvaddch(starty[6] + y, startx[6] + x, '.');
                }
            }
        }
        attroff(A_BOLD);
    }
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

void food()
{
    // for floor_1
    food_floor1[0] = rand() % 7 + 1;
    food_floor1[1] = rand() % 7 + 1;

    x_floor1_food[0] = startx[food_floor1[0] - 1] + rand() % (width[food_floor1[0] - 1] - 2) + 1;
    y_floor1_food[0] = starty[food_floor1[0] - 1] + rand() % (height[food_floor1[0] - 1] - 2) + 1;

    x_floor1_food[1] = startx[food_floor1[1] - 1] + rand() % (width[food_floor1[1] - 1] - 2) + 1;
    y_floor1_food[1] = starty[food_floor1[1] - 1] + rand() % (height[food_floor1[1] - 1] - 2) + 1;

    if (map1[y_floor1_food[1]][x_floor1_food[1]] == '.')
    {
        floor1_food[y_floor1_food[1]][x_floor1_food[1]] = '*';
    }
    if (map1[y_floor1_food[0]][x_floor1_food[0]] == '.')
    {
        floor1_food[y_floor1_food[0]][x_floor1_food[0]] = '*';
    }
}

void print_food(int i, int y, int x, int *n)
{
    attron(A_BOLD);
    for (int j = 0; j < 2; j++)
    {
        if (i == food_floor1[j])
        {
            mvaddch(y_floor1_food[j], x_floor1_food[j], floor1_food[y_floor1_food[j]][x_floor1_food[j]]);
            statuse_food_floor1[j] = 1;
        }
        if (y == y_floor1_food[j] && x == x_floor1_food[j] && floor1_food[y][x] == '*')
        {
            mvaddch(y_floor1_food[j], x_floor1_food[j], 'O');

            *n = 0;
            attron(COLOR_PAIR(4));
            mvprintw(1, 3, "You found food! Your hunger is satisfied.");
            attroff(COLOR_PAIR(4));
            while (getch() != 32)
            {
            }
            mvprintw(1, 3, "                                                            ");
            floor1_food[y][x] = '.';
            mvaddch(y_floor1_food[j], x_floor1_food[j], floor1_food[y_floor1_food[j]][x_floor1_food[j]]);
        }
        if (i == 0 && statuse_food_floor1[j] == 1)
        {
            mvaddch(y_floor1_food[j], x_floor1_food[j], '.');
        }
    }
    attroff(A_BOLD);
}
void elements()
{
    attron(A_BOLD);
    attron(COLOR_PAIR(3));
    mvprintw(43, 3, "Hunger:          |");
    mvprintw(43, 30, "Health:          |");
    attroff(COLOR_PAIR(3));
    attroff(A_BOLD);
}

void Health(int *n2, int *count_health)
{
    attron(A_BOLD);
    attron(COLOR_PAIR(3));
    mvprintw(43, 30, "Health:          |");
    attroff(COLOR_PAIR(3));

    if (*n2 > 0)
    {
        for (int i = 0; i < *n2; i++)
        {
            attron(COLOR_PAIR(4));
            mvaddch(43, 37 + i, ' ');
            attroff(COLOR_PAIR(4));
        }
    }
    if (*count_health > 70)
    {
        *n2 = *n2 + 1;
        *count_health = 0;
    }
    if (*n2 != 10)
    {
        *count_health = *count_health + 1;
    }
}
void Hunger(int n, int *count_message)
{
    attron(A_BOLD);
    attron(COLOR_PAIR(3));
    mvprintw(43, 3, "Hunger:          |");
    attroff(COLOR_PAIR(3));

    if (n >= 0)
    {
        for (int i = 0; i < n; i++)
        {
            attron(COLOR_PAIR(1));
            mvaddch(43, 10 + i, ' ');
            attroff(COLOR_PAIR(1));
        }
    }
    // message
    if (n != 10)
    {
        *count_message = 0;
    }
    else if (n == 10 && *count_message == 0)
    {
        attron(COLOR_PAIR(1));
        mvprintw(1, 3, "Find food as soon as possible, your health is decreasing!!!");
        attroff(COLOR_PAIR(1));
        while (getch() != 32)
        {
        }
        mvprintw(1, 3, "                                                            ");
        *count_message = 1;
    }
    attroff(A_BOLD);
}
void stairs()
{
    // for floor_1
    stair1 = rand() % 7;
    attron(COLOR_PAIR(5));
    map1[starty[stair1] + (height[stair1] / 2)][startx[stair1] + (width[stair1] / 2)] = '>';
    attroff(COLOR_PAIR(5));
}
void handle_motion_input()
{
    attron(A_BOLD);
    int select_room = rand() % 7 + 1;
    print_room(select_room);

    int x, y;
    x = startx[select_room - 1] + 2;
    y = starty[select_room - 1] + 2;

    int previous_x = x;
    int previous_y = y;
    chtype previous_char; // ذخیره کاراکتر قبلی
    previous_char = mvinch(y, x);
    mvaddch(y, x, 'O');
    refresh();

    int full_food = 10, full_health = 10;
    int n1 = 0;
    int n2 = full_health;
    print_food(select_room, y, x, &n1);
    int count_message = 0;
    int count_hunger = 0;
    int count_health = 0;
    Health(&n2, &count_health);
    int exit = 0;
    while (1)
    {
        margin();
        int previous_x = x;
        int previous_y = y;
        int A = getch();
        switch (A)
        {

        case '8':

            if (map1[y - 1][x] == '.' || map1[y - 1][x] == '=' || map1[y - 1][x] == '*' || map1[y - 1][x] == '>')
                y--;
            break;
        case '2':

            if (map1[y + 1][x] == '.' || map1[y + 1][x] == '=' || map1[y + 1][x] == '*' || map1[y + 1][x] == '>')
                y++;
            break;
        case '6':

            if (map1[y][x + 1] == '.' || map1[y][x + 1] == '=' || map1[y][x + 1] == '*' || map1[y][x + 1] == '>')
                x++;
            break;
        case '4':

            if (map1[y][x - 1] == '.' || map1[y][x - 1] == '=' || map1[y][x - 1] == '*' || map1[y][x - 1] == '>')
                x--;
            break;
        case '3':
            if (map1[y + 1][x + 1] == '.' || map1[y + 1][x + 1] == '=' || map1[y + 1][x + 1] == '*' || map1[y + 1][x + 1] == '>')
            {
                x++;
                y++;
            }
            break;
        case '7':
            if (map1[y - 1][x - 1] == '.' || map1[y - 1][x - 1] == '=' || map1[y - 1][x - 1] == '*' || map1[y - 1][x - 1] == '>')
            {
                x--;
                y--;
            }
            break;
        case '9':
            if (map1[y - 1][x + 1] == '.' || map1[y - 1][x + 1] == '=' || map1[y - 1][x + 1] == '*' || map1[y - 1][x + 1] == '>')
            {
                y--;
                x++;
            }
            break;
        case '1':
            if (map1[y + 1][x - 1] == '.' || map1[y + 1][x - 1] == '=' || map1[y + 1][x - 1] == '*' || map1[y + 1][x - 1] == '>')
            {
                y++;
                x--;
            }
            break;
        case 'q':
            exit = 1;
            break;
        default:
            break;
        }

        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                if (map1[y + i][x + j] == '*')
                {
                    attron(COLOR_PAIR(2));
                    mvaddch(y + i, x + j, '.');
                    attroff(COLOR_PAIR(2));
                }
                else if (map1[y + i][x + j] == '=')
                {
                    attron(COLOR_PAIR(1));
                    mvaddch(y + i, x + j, map1[y + i][x + j]);
                    attroff(COLOR_PAIR(1));
                }
            }
        }

        if (map1[y][x] == '=')
        {

            if ((y == starty[0] + y_door_down[0] && x == startx[0] + x_door_down[0] + 1))
                select_room = 1;
            else if ((y == starty[1] + y_door_down[1] && x == startx[1] + x_door_down[1] + 1) || (y == starty[1] + y_door_right[1] + 1 && x == startx[1] + x_door_right[1]))
                select_room = 2;
            else if ((y == starty[2] + y_door_down[2] && x == startx[2] + x_door_down[2] + 1) || (y == starty[2] + y_door_left[2] + 1 && x == startx[2] + x_door_left[2]) || (y == starty[2] + y_door_right[2] + 1 && x == startx[2] + x_door_right[2]))
                select_room = 3;
            else if ((y == starty[3] + y_door_left[3] + 1 && x == startx[3] + x_door_left[3]) || (y == starty[3] + y_door_right[3] + 1 && x == startx[3] + x_door_right[3]))
                select_room = 4;
            else if (y == starty[4] + y_door_up[4] && x == startx[4] + x_door_up[4] + 1)
                select_room = 5;
            else if ((y == starty[5] + y_door_up[5] && x == startx[5] + x_door_up[5] + 1) || (y == starty[5] + y_door_right[5] + 1 && x == startx[5] + x_door_right[5]))
                select_room = 6;
            else if (y == starty[6] + y_door_left[6] + 1 && x == startx[6] + x_door_left[6])
                select_room = 7;
        }
        if (map1[y][x] == '*')
        {
            select_room = 0;
        }
        print_room(select_room);
        print_food(select_room, y, x, &n1);
        if (exit != 0)
        {
            break;
        }

        mvaddch(previous_y, previous_x, previous_char);

        previous_char = mvinch(y, x);

        mvaddch(y, x, 'O');
        refresh();

        if (map1[y][x] == '>')
        {
            attron(A_BOLD);
            attron(COLOR_PAIR(4));
            mvprintw(1, 3, "You can press '>' key to go to the next floor!");
            attroff(COLOR_PAIR(4));
            while (getch() != 32)
            {
            }
            mvprintw(1, 3, "                                                            ");
            attroff(A_BOLD);
        }
        // hunger
        count_hunger++;
        if (count_hunger > 50)
        {
            count_hunger = 0;
            if (n1 < full_food)
                n1++;
            else
            {
                n1 = full_food;
                n2--;
            }
        }
        if (n2 == 0)
        {
            break;
        }
        Hunger(n1, &count_message);
        Health(&n2, &count_health);
        mvprintw(30, 40, "%d %d", n2, count_health);
    }

    attroff(A_BOLD);
}
void corridor_tool(int x, int y, int x2, int y2)
{

    map1[y][x] = '*';

    int i = 0;
    while ((x != x2 || y != y2) && (i < 100))
    {
        int direction = rand() % 2;
        if (direction == 0)
        {
            int j = 0;
            while (x != x2 && (j < 100))
            {
                x += (x2 > x) ? 1 : -1;

                if (map1[y][x] != '=' && map1[y][x] != '|' && map1[y][x] != '_')
                {

                    map1[y][x] = '*';
                }
                else if (map1[y][x] == '=' || map1[y][x] == '|' || map1[y][x] == '_')
                {
                    if (y == y2)
                    {
                        while (map1[y][x] == '=' || map1[y][x] == '|' || map1[y][x] == '_')
                        {
                            y--;

                            (x2 > x) ? (map1[y][x - 1] = '*') : (map1[y][x + 1] = '*');
                        }
                    }
                    x += (x2 > x) ? -1 : 1;
                    break;
                }
                j++;
            }
        }
        else if (direction == 1)
        {
            int j = 0;
            while (y != y2 && (j < 100))
            {
                y += (y2 > y) ? 1 : -1;
                if (map1[y][x] != '=' && map1[y][x] != '|' && map1[y][x] != '_')
                {

                    map1[y][x] = '*';
                }
                else if (map1[y][x] == '=' || map1[y][x] == '|' || map1[y][x] == '_')
                {

                    if (x == x2)
                    {
                        while (map1[y][x] == '=' || map1[y][x] == '|' || map1[y][x] == '_')
                        {
                            x--;

                            (y2 > y) ? (map1[y - 1][x] = '*') : (map1[y + 1][x] = '*');
                        }
                    }
                    y += (y2 > y) ? -1 : 1;
                    break;
                }
                j++;
            }
        }
        i++;
    }
}
void corridor()
{
    // coridor 1_down to 6_up
    int x1 = x_door_down[0] + startx[0] + 1, y1 = y_door_down[0] + starty[0] + 1;
    int x2 = x_door_down[1] + startx[1] + 1, y2 = y_door_down[1] + starty[1] + 1;

    int x = x1, y = y1;

    attron(A_BOLD); // برای شناسایی کارکتر
    mvaddch(0, 0, '|');
    mvaddch(1, 0, '_');
    attron(COLOR_PAIR(1));
    mvaddch(2, 0, '=');
    attroff(COLOR_PAIR(1));
    attroff(A_BOLD);

    chtype previous_char;
    chtype character1 = mvinch(0, 0);
    chtype character2 = mvinch(1, 0);
    chtype character3 = mvinch(2, 0);
    corridor_tool(x, y, x2, y2);

    //\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//
    ///////////////////////////////////////    2     //////////////////////////////////////
    x1 = x_door_down[2] + startx[2] + 1, y1 = y_door_down[2] + starty[2] + 1;
    x2 = x_door_up[5] + startx[5] + 1, y2 = y_door_up[5] + starty[5] - 1;
    x = x1, y = y1;

    corridor_tool(x, y, x2, y2);

    //\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//
    ////////////////////////////////////       3       ////////////////////////////////////

    x1 = x_door_right[2] + startx[2] + 1, y1 = y_door_right[2] + starty[2] + 1;
    x2 = x_door_left[3] + startx[3] - 1, y2 = y_door_left[3] + starty[3] + 1;

    x = x1, y = y1;

    corridor_tool(x, y, x2, y2);
    ///////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////    4     ///////////////////////////////////////////////

    x1 = x_door_right[1] + startx[1] + 1, y1 = y_door_right[1] + starty[1] + 1;
    x2 = x_door_left[2] + startx[2] - 1, y2 = y_door_left[2] + starty[2] + 1;

    x = x1, y = y1;

    corridor_tool(x, y, x2, y2);
    ///////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////      5    ///////////////////////////////////////////

    x1 = x_door_right[5] + startx[5] + 1, y1 = y_door_right[5] + starty[5] + 1;
    x2 = x_door_up[4] + startx[4] + 1, y2 = y_door_up[4] + starty[4] - 1;

    x = x1, y = y1;

    corridor_tool(x, y, x2, y2);
    ///////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////      6      ///////////////////////////////////////////////

    x1 = x_door_right[3] + startx[3] + 1, y1 = y_door_right[3] + starty[3] + 1;
    x2 = x_door_left[6] + startx[6] - 1, y2 = y_door_left[6] + starty[6] + 1;

    x = x1, y = y1;

    corridor_tool(x, y, x2, y2);
    ///////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////
}
int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "");

    initscr();
    // has_colors();
    color();
    noecho();
    keypad(stdscr, TRUE);
    cbreak();
    curs_set(0);
    room1();
    stairs();
    corridor();
    elements();
    food();
    handle_motion_input();

    endwin();
}