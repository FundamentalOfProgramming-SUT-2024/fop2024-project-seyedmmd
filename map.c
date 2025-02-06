#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <wchar.h>
#include <unistd.h>

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

chtype save_map1[45][184];
chtype save_map2[45][184];

char floor1_food[45][184];
int x_floor1_food[10];
int y_floor1_food[10];
int statuse_food_floor1[10];
int food_floor1[10];

char snake_floor1[45][184];
char snake_floor2[45][184];
int snake_room_floor1;
int statuse_snake_floor1[45][184];
int statuse_snake_floor2[45][184];
int snake_room_floor2;

int tale_room_floor1;
int tale_room_floor2;

int Enchant_Room_floor1;
int Enchant_Room_floor2;

char floor1_gold[45][184];
int x_floor1_gold[100];
int y_floor1_gold[100];
int statuse_gold_floor1[100];
int gold_floor1[100];
int meghdar_gold[45][184];
int gold_room_floor1;

int score = 0;

int stair1;

void initialization()
{
    for (int i = 3; i < 42; i++)
    {
        for (int j = 3; j < 181; j++)
        {
            save_map1[i][j] = ' ';
            save_map2[i][j] = ' ';
        }
    }
    for (int i = 3; i < 42; i++)
    {
        for (int j = 3; j < 181; j++)
        {
            snake_floor1[i][j] = ' ';
            // snake_floor2[i][j] = ' ';
        }
    }
}
void color()
{
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_RED);
    init_pair(2, COLOR_RED, COLOR_CYAN);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_BLACK, COLOR_GREEN);
    init_pair(5, COLOR_BLACK, COLOR_GREEN);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_YELLOW, COLOR_BLACK);
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

///////////////////////////////////////////////////////////////////////////////////////7
void stairs()
{
    // for floor_1
    stair1 = rand() % 7;
    attron(COLOR_PAIR(5));
    map1[starty[stair1] + (height[stair1] / 2)][startx[stair1] + (width[stair1] / 2)] = '>';
    attroff(COLOR_PAIR(5));
}

/////////////////////////////////////////////////////////////////////////////////////////
void room2()
{
    attron(A_BOLD);

    starty[7] = rand() % 3 + 4;
    startx[7] = rand() % 10 + 3;
    height[7] = rand() % 10 + 6;
    width[7] = rand() % 15 + 6;

    x_door_down[7] = rand() % (width[7] - 2);
    y_door_down[7] = height[7] - 1;

    x_door_right[7] = width[7] - 1;
    y_door_right[7] = rand() % (height[7] - 2);

    attron(A_BOLD);
    for (int y = 0; y < height[7]; y++)
    {
        for (int x = 0; x < width[7]; x++)
        {
            if (y == y_door_down[7] && (x == x_door_down[7] + 1))
            {

                map2[starty[7] + y][startx[7] + x] = '=';
            }
            else if ((y == y_door_right[7] + 1) && (x == x_door_right[7]))
            {
                map2[starty[7] + y][startx[7] + x] = '=';
            }
            else if ((x == 0 || x == width[7] - 1) && y != 0)
            {

                map2[starty[7] + y][startx[7] + x] = '|';
            }
            else if (y == 0 || y == height[7] - 1)
            {
                map2[starty[7] + y][startx[7] + x] = '_';
            }

            else
            {
                map2[starty[7] + y][startx[7] + x] = '.';
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

    starty[9] = rand() % 10 + 4;
    startx[9] = rand() % 10 + 48;
    height[9] = rand() % 4 + 6;
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

    starty[11] = rand() % 4 + 15;
    startx[11] = rand() % 10 + 137;
    height[11] = rand() % 4 + 6;
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

    starty[12] = rand() % 3 + 24;
    startx[12] = rand() % 10 + 3;
    height[12] = rand() % 8 + 6;
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
///////////////////////////////////////////////////////////////////
    */
    starty[13] = rand() % 4 + 25;
    startx[13] = rand() % 20 + 40;

    x_door_up[13] = rand() % (width[stair1] - 2);
    y_door_up[13] = 0;

    x_door_right[13] = width[stair1] - 1;
    y_door_right[13] = rand() % (height[stair1] - 2);

    map2[starty[13] + y_door_up[13]][startx[13] + x_door_up[13] + 1] = '=';
    map2[starty[13] + y_door_right[13] + 1][startx[13] + x_door_right[13]] = '=';

    for (int y = 0; y < height[stair1]; y++)
    {
        for (int x = 0; x < width[stair1]; x++)
        {
            if (map1[starty[stair1] + y][startx[stair1] + x] == '=')
            {
                if (y == 0 || (y == height[stair1] - 1 && x != 0 && x != width[stair1] - 1))
                {
                    if (map2[starty[13] + y][startx[13] + x] != '=')
                        map2[starty[13] + y][startx[13] + x] = '_';
                }

                else if (y != 0 && (x == 0 || x == width[stair1] - 1))
                {
                    if (map2[starty[13] + y][startx[13] + x] != '=')
                        map2[starty[13] + y][startx[13] + x] = '|';
                }
            }
            else if (map1[starty[stair1] + y][startx[stair1] + x] == '>')
            {

                map2[starty[13] + y][startx[13] + x] = '<';
            }

            else
            {
                if (map2[starty[13] + y][startx[13] + x] != '=')
                    map2[starty[13] + y][startx[13] + x] = map1[starty[stair1] + y][startx[stair1] + x];
            }
        }
    }

    /*
\\\\\\\\///////////////////////////////////////////////////////
    */

    starty[14] = rand() % 4 + 30;
    startx[14] = rand() % 10 + 130;
    height[14] = rand() % 2 + 6;
    width[14] = rand() % 20 + 15;

    x_door_left[14] = 0;
    y_door_left[14] = rand() % (height[14] - 2);

    x_door_up[14] = rand() % (width[14] - 2);
    y_door_up[14] = 0;

    attron(A_BOLD);
    for (int y = 0; y < height[14]; y++)
    {
        for (int x = 0; x < width[14]; x++)
        {
            if (y == y_door_left[14] + 1 && (x == x_door_left[14]))
            {

                map2[starty[14] + y][startx[14] + x] = '=';
            }
            else if (y == y_door_up[14] && (x == x_door_up[14] + 1))
            {

                map2[starty[14] + y][startx[14] + x] = '=';
            }
            else if ((x == 0 || x == width[14] - 1) && y != 0)
            {
                map2[starty[14] + y][startx[14] + x] = '|';
            }
            else if (y == 0 || y == height[14] - 1)
            {
                map2[starty[14] + y][startx[14] + x] = '_';
            }

            else
            {
                map2[starty[14] + y][startx[14] + x] = '.';
            }
        }
    }
    attroff(A_BOLD);
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
                    if (Enchant_Room_floor1 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[0] + y, startx[0] + x, '|');
                    if (Enchant_Room_floor1 == n - 1)
                        attron(COLOR_PAIR(6));
                }
                else if (y == 0 || y == height[0] - 1)
                {
                    if (Enchant_Room_floor1 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[0] + y, startx[0] + x, '_');
                    if (Enchant_Room_floor1 == n - 1)
                        attroff(COLOR_PAIR(6));
                }
                else
                {
                    if (Enchant_Room_floor1 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[0] + y, startx[0] + x, '.');
                    if (Enchant_Room_floor1 == n - 1)
                        attroff(COLOR_PAIR(6));
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
                    if (Enchant_Room_floor1 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[1] + y, startx[1] + x, '|');
                    if (Enchant_Room_floor1 == n - 1)
                        attroff(COLOR_PAIR(6));
                }
                else if (y == 0 || y == height[1] - 1)
                {
                    if (Enchant_Room_floor1 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[1] + y, startx[1] + x, '_');
                    if (Enchant_Room_floor1 == n - 1)
                        attroff(COLOR_PAIR(6));
                }

                else
                {
                    if (Enchant_Room_floor1 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[1] + y, startx[1] + x, '.');
                    if (Enchant_Room_floor1 == n - 1)
                        attroff(COLOR_PAIR(6));
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
                    if (Enchant_Room_floor1 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[2] + y, startx[2] + x, '|');
                    if (Enchant_Room_floor1 == n - 1)
                        attroff(COLOR_PAIR(6));
                }
                else if (y == 0 || y == height[2] - 1)
                {
                    if (Enchant_Room_floor1 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[2] + y, startx[2] + x, '_');
                    if (Enchant_Room_floor1 == n - 1)
                        attroff(COLOR_PAIR(6));
                }

                else
                {
                    if (Enchant_Room_floor1 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[2] + y, startx[2] + x, '.');
                    if (Enchant_Room_floor1 == n - 1)
                        attroff(COLOR_PAIR(6));
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
                    if (Enchant_Room_floor1 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[3] + y, startx[3] + x, '|');
                    if (Enchant_Room_floor1 == n - 1)
                        attroff(COLOR_PAIR(6));
                }
                else if (y == 0 || y == height[3] - 1)
                {
                    if (Enchant_Room_floor1 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[3] + y, startx[3] + x, '_');
                    if (Enchant_Room_floor1 == n - 1)
                        attroff(COLOR_PAIR(6));
                }

                else
                {
                    if (Enchant_Room_floor1 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[3] + y, startx[3] + x, '.');
                    if (Enchant_Room_floor1 == n - 1)
                        attroff(COLOR_PAIR(6));
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
                    if (Enchant_Room_floor1 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[4] + y, startx[4] + x, '|');
                    if (Enchant_Room_floor1 == n - 1)
                        attroff(COLOR_PAIR(6));
                }
                else if (y == 0 || y == height[4] - 1)
                {
                    if (Enchant_Room_floor1 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[4] + y, startx[4] + x, '_');
                    if (Enchant_Room_floor1 == n - 1)
                        attroff(COLOR_PAIR(6));
                }

                else
                {
                    if (Enchant_Room_floor1 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[4] + y, startx[4] + x, '.');
                    if (Enchant_Room_floor1 == n - 1)
                        attroff(COLOR_PAIR(6));
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
                    if (Enchant_Room_floor1 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[5] + y, startx[5] + x, '|');
                    if (Enchant_Room_floor1 == n - 1)
                        attroff(COLOR_PAIR(6));
                }
                else if (y == 0 || y == height[5] - 1)
                {
                    if (Enchant_Room_floor1 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[5] + y, startx[5] + x, '_');
                    if (Enchant_Room_floor1 == n - 1)
                        attroff(COLOR_PAIR(6));
                }

                else
                {
                    if (Enchant_Room_floor1 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[5] + y, startx[5] + x, '.');
                    if (Enchant_Room_floor1 == n - 1)
                        attroff(COLOR_PAIR(6));
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
                    if (Enchant_Room_floor1 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[6] + y, startx[6] + x, '|');
                    if (Enchant_Room_floor1 == n - 1)
                        attroff(COLOR_PAIR(6));
                }
                else if (y == 0 || y == height[6] - 1)
                {
                    if (Enchant_Room_floor1 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[6] + y, startx[6] + x, '_');
                    if (Enchant_Room_floor1 == n - 1)
                        attroff(COLOR_PAIR(6));
                }

                else
                {
                    if (Enchant_Room_floor1 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[6] + y, startx[6] + x, '.');
                    if (Enchant_Room_floor1 == n - 1)
                        attroff(COLOR_PAIR(6));
                }
            }
        }
        attroff(A_BOLD);
    }
    else if (n == 8)
    {
        attron(A_BOLD);
        for (int y = 0; y < height[7]; y++)
        {
            for (int x = 0; x < width[7]; x++)
            {
                if (y == y_door_down[7] && (x == x_door_down[7] + 1))
                {

                    attron(COLOR_PAIR(1));
                    mvaddch(starty[7] + y, startx[7] + x, '=');
                    attroff(COLOR_PAIR(1));
                }
                else if ((y == y_door_right[7] + 1) && (x == x_door_right[7]))
                {
                    attron(COLOR_PAIR(1));
                    mvaddch(starty[7] + y, startx[7] + x, '=');
                    attroff(COLOR_PAIR(1));
                }
                else if ((x == 0 || x == width[7] - 1) && y != 0)
                {
                    if (Enchant_Room_floor2 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[7] + y, startx[7] + x, '|');
                    if (Enchant_Room_floor2 == n - 1)
                        attroff(COLOR_PAIR(6));
                }
                else if (y == 0 || y == height[7] - 1)
                {
                    if (Enchant_Room_floor2 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[7] + y, startx[7] + x, '_');
                    if (Enchant_Room_floor2 == n - 1)
                        attroff(COLOR_PAIR(6));
                }

                else
                {
                    if (Enchant_Room_floor2 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[7] + y, startx[7] + x, '.');
                    if (Enchant_Room_floor2 == n - 1)
                        attroff(COLOR_PAIR(6));
                }
            }
        }
        attroff(A_BOLD);
    }
    else if (n == 9)
    {
        attron(A_BOLD);
        for (int y = 0; y < height[8]; y++)
        {
            for (int x = 0; x < width[8]; x++)
            {
                if (y == y_door_left[8] + 1 && (x == x_door_left[8]))
                {
                    attron(COLOR_PAIR(1));
                    mvaddch(starty[8] + y, startx[8] + x, '=');
                    attroff(COLOR_PAIR(1));
                }
                else if (y == y_door_down[8] && (x == x_door_down[8] + 1))
                {
                    attron(COLOR_PAIR(1));
                    mvaddch(starty[8] + y, startx[8] + x, '=');
                    attroff(COLOR_PAIR(1));
                }

                else if ((x == 0 || x == width[8] - 1) && y != 0)
                {
                    if (Enchant_Room_floor2 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[8] + y, startx[8] + x, '|');
                    if (Enchant_Room_floor2 == n - 1)
                        attroff(COLOR_PAIR(6));
                }
                else if (y == 0 || y == height[8] - 1)
                {
                    if (Enchant_Room_floor2 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[8] + y, startx[8] + x, '_');
                    if (Enchant_Room_floor2 == n - 1)
                        attroff(COLOR_PAIR(6));
                }

                else
                {
                    if (Enchant_Room_floor2 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[8] + y, startx[8] + x, '.');
                    if (Enchant_Room_floor2 == n - 1)
                        attroff(COLOR_PAIR(6));
                }
            }
        }
        attroff(A_BOLD);
    }
    else if (n == 10)
    {

        attron(A_BOLD);
        for (int y = 0; y < height[9]; y++)
        {
            for (int x = 0; x < width[9]; x++)
            {
                if (y == y_door_down[9] && (x == x_door_down[9] + 1))
                {

                    attron(COLOR_PAIR(1));
                    mvaddch(starty[9] + y, startx[9] + x, '=');
                    attroff(COLOR_PAIR(1));
                }
                else if (y == y_door_right[9] + 1 && (x == x_door_right[9]))
                {
                    attron(COLOR_PAIR(1));
                    mvaddch(starty[9] + y, startx[9] + x, '=');
                    attroff(COLOR_PAIR(1));
                }
                else if ((x == 0 || x == width[9] - 1) && y != 0)
                {
                    if (Enchant_Room_floor2 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[9] + y, startx[9] + x, '|');
                    if (Enchant_Room_floor2 == n - 1)
                        attroff(COLOR_PAIR(6));
                }
                else if (y == 0 || y == height[9] - 1)
                {
                    if (Enchant_Room_floor2 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[9] + y, startx[9] + x, '_');
                    if (Enchant_Room_floor2 == n - 1)
                        attroff(COLOR_PAIR(6));
                }

                else
                {
                    if (Enchant_Room_floor2 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[9] + y, startx[9] + x, '.');
                    if (Enchant_Room_floor2 == n - 1)
                        attroff(COLOR_PAIR(6));
                }
            }
        }
        attroff(A_BOLD);
    }

    else if (n == 11)
    {
        attron(A_BOLD);
        for (int y = 0; y < height[10]; y++)
        {
            for (int x = 0; x < width[10]; x++)
            {
                if (y == y_door_down[10] && (x == x_door_down[10] + 1))
                {

                    attron(COLOR_PAIR(1));
                    mvaddch(starty[10] + y, startx[10] + x, '=');
                    attroff(COLOR_PAIR(1));
                }
                else if (y == y_door_left[10] + 1 && (x == x_door_left[10]))
                {

                    attron(COLOR_PAIR(1));
                    mvaddch(starty[10] + y, startx[10] + x, '=');
                    attroff(COLOR_PAIR(1));
                }
                else if (y == y_door_up[10] && (x == x_door_up[10] + 1))
                {

                    attron(COLOR_PAIR(1));
                    mvaddch(starty[10] + y, startx[10] + x, '=');
                    attroff(COLOR_PAIR(1));
                }
                else if ((x == 0 || x == width[10] - 1) && y != 0)
                {
                    if (Enchant_Room_floor2 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[10] + y, startx[10] + x, '|');
                    if (Enchant_Room_floor2 == n - 1)
                        attroff(COLOR_PAIR(6));
                }
                else if (y == 0 || y == height[10] - 1)
                {
                    if (Enchant_Room_floor2 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[10] + y, startx[10] + x, '_');
                    if (Enchant_Room_floor2 == n - 1)
                        attroff(COLOR_PAIR(6));
                }

                else
                {
                    if (Enchant_Room_floor2 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[10] + y, startx[10] + x, '.');
                    if (Enchant_Room_floor2 == n - 1)
                        attroff(COLOR_PAIR(6));
                }
            }
        }
        attroff(A_BOLD);
    }
    else if (n == 12)
    {
        attron(A_BOLD);
        for (int y = 0; y < height[11]; y++)
        {
            for (int x = 0; x < width[11]; x++)
            {
                if (y == y_door_up[11] && (x == x_door_up[11] + 1))
                {

                    attron(COLOR_PAIR(1));
                    mvaddch(starty[11] + y, startx[11] + x, '=');
                    attroff(COLOR_PAIR(1));
                }
                else if ((x == 0 || x == width[11] - 1) && y != 0)
                {
                    if (Enchant_Room_floor2 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[11] + y, startx[11] + x, '|');
                    if (Enchant_Room_floor2 == n - 1)
                        attroff(COLOR_PAIR(6));
                }
                else if (y == 0 || y == height[11] - 1)
                {
                    if (Enchant_Room_floor2 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[11] + y, startx[11] + x, '_');
                    if (Enchant_Room_floor2 == n - 1)
                        attroff(COLOR_PAIR(6));
                }

                else
                {
                    if (Enchant_Room_floor2 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[11] + y, startx[11] + x, '.');
                    if (Enchant_Room_floor2 == n - 1)
                        attroff(COLOR_PAIR(6));
                }
            }
        }
        attroff(A_BOLD);
    }
    else if (n == 13)
    {
        attron(A_BOLD);
        for (int y = 0; y < height[12]; y++)
        {
            for (int x = 0; x < width[12]; x++)
            {
                if (y == y_door_up[12] && (x == x_door_up[12] + 1))
                {
                    attron(COLOR_PAIR(1));
                    mvaddch(starty[12] + y, startx[12] + x, '=');
                    attroff(COLOR_PAIR(1));
                }
                else if ((y == y_door_right[12] + 1) && (x == x_door_right[12]))
                {
                    attron(COLOR_PAIR(1));
                    mvaddch(starty[12] + y, startx[12] + x, '=');
                    attroff(COLOR_PAIR(1));
                }

                else if ((x == 0 || x == width[12] - 1) && y != 0)
                {
                    if (Enchant_Room_floor2 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[12] + y, startx[12] + x, '|');
                    if (Enchant_Room_floor2 == n - 1)
                        attroff(COLOR_PAIR(6));
                }
                else if (y == 0 || y == height[12] - 1)
                {
                    if (Enchant_Room_floor2 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[12] + y, startx[12] + x, '_');
                    if (Enchant_Room_floor2 == n - 1)
                        attroff(COLOR_PAIR(6));
                }

                else
                {
                    if (Enchant_Room_floor2 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[12] + y, startx[12] + x, '.');
                    if (Enchant_Room_floor2 == n - 1)
                        attroff(COLOR_PAIR(6));
                }
            }
        }
        attroff(A_BOLD);
    }

    else if (n == 14)
    {
        attron(A_BOLD);
        for (int y = 0; y < height[stair1]; y++)
        {
            for (int x = 0; x < width[stair1]; x++)
            {
                if (map1[starty[stair1] + y][startx[stair1] + x] == '?' || map1[starty[stair1] + y][startx[stair1] + x] == '!')
                {
                    mvaddch(starty[13] + y, startx[13] + x, '.');
                }
                if (map1[starty[stair1] + y][startx[stair1] + x] == '=')
                {
                    if (y == 0 || (y == height[stair1] - 1 && x != 0 && x != width[stair1] - 1))
                    {
                        mvaddch(starty[13] + y, startx[13] + x, '_');
                    }

                    else if (y != 0 && (x == 0 || x == width[stair1] - 1))
                    {
                        mvaddch(starty[13] + y, startx[13] + x, '|');
                    }
                }
                else if (map1[starty[stair1] + y][startx[stair1] + x] == '>')
                {
                    attron(COLOR_PAIR(5));
                    mvaddch(starty[13] + y, startx[13] + x, '<');
                    attroff(COLOR_PAIR(5));
                }

                else
                {
                    mvaddch(starty[13] + y, startx[13] + x, map1[starty[stair1] + y][startx[stair1] + x]);
                }

                if (map2[starty[13] + y][startx[13] + x] == '=')
                {
                    attron(COLOR_PAIR(1));
                    mvaddch(starty[13] + y, startx[13] + x, '=');
                    attroff(COLOR_PAIR(1));
                }
            }
        }

        attroff(A_BOLD);
    }
    else if (n == 15)
    {
        attron(A_BOLD);
        for (int y = 0; y < height[14]; y++)
        {
            for (int x = 0; x < width[14]; x++)
            {
                if (y == y_door_left[14] + 1 && (x == x_door_left[14]))
                {

                    attron(COLOR_PAIR(1));
                    mvaddch(starty[14] + y, startx[14] + x, '=');
                    attroff(COLOR_PAIR(1));
                }
                else if (y == y_door_up[14] && (x == x_door_up[14] + 1))
                {

                    attron(COLOR_PAIR(1));
                    mvaddch(starty[14] + y, startx[14] + x, '=');
                    attroff(COLOR_PAIR(1));
                }
                else if ((x == 0 || x == width[14] - 1) && y != 0)
                {
                    if (Enchant_Room_floor2 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[14] + y, startx[14] + x, '|');
                    if (Enchant_Room_floor2 == n - 1)
                        attroff(COLOR_PAIR(6));
                }
                else if (y == 0 || y == height[14] - 1)
                {
                    if (Enchant_Room_floor2 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[14] + y, startx[14] + x, '_');
                    if (Enchant_Room_floor2 == n - 1)
                        attroff(COLOR_PAIR(6));
                }

                else
                {
                    if (Enchant_Room_floor2 == n - 1)
                        attron(COLOR_PAIR(6));
                    mvaddch(starty[14] + y, startx[14] + x, '.');
                    if (Enchant_Room_floor2 == n - 1)
                        attroff(COLOR_PAIR(6));
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

    // for floor_2
    food_floor1[2] = rand() % 8 + 8;
    food_floor1[3] = rand() % 8 + 8;

    x_floor1_food[2] = startx[food_floor1[2] - 1] + rand() % (width[food_floor1[2] - 1] - 2) + 1;
    y_floor1_food[2] = starty[food_floor1[2] - 1] + rand() % (height[food_floor1[2] - 1] - 2) + 1;

    x_floor1_food[3] = startx[food_floor1[3] - 1] + rand() % (width[food_floor1[3] - 1] - 2) + 1;
    y_floor1_food[3] = starty[food_floor1[3] - 1] + rand() % (height[food_floor1[3] - 1] - 2) + 1;

    if (map2[y_floor1_food[3]][x_floor1_food[3]] == '.')
    {
        floor1_food[y_floor1_food[3]][x_floor1_food[3]] = '*';
    }
    if (map2[y_floor1_food[2]][x_floor1_food[2]] == '.')
    {
        floor1_food[y_floor1_food[2]][x_floor1_food[2]] = '*';
    }
}
void print_food(int floor, int i, int y, int x, int *n)
{
    attron(A_BOLD);
    if (floor == 1)
    {
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
    }
    else if (floor == 2)
    {
        for (int j = 2; j < 4; j++)
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
    }
    attroff(A_BOLD);
}
void elements()
{
    attron(A_BOLD);
    attron(COLOR_PAIR(3));
    mvprintw(43, 3, "Hunger:          |");
    mvprintw(43, 30, "Health:          |");
    mvprintw(43, 60, "Gold:               |");
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
void Enchant_Room_select()
{
    Enchant_Room_floor1 = rand() % 7;
    Enchant_Room_floor2 = rand() % 8 + 7;
}
void Enchant_Room(int floor, int y, int x, int *n2, int *counter_enchanted_room)
{
    if (floor == 1)
    {
        for (int i = starty[Enchant_Room_floor1]; i < starty[Enchant_Room_floor1] + height[Enchant_Room_floor1]; i++)
        {
            for (int j = startx[Enchant_Room_floor1]; j < startx[Enchant_Room_floor1] + width[Enchant_Room_floor1]; j++)
            {
                if (y == i && x == j)
                {
                    *counter_enchanted_room = *counter_enchanted_room + 1;
                }
            }
        }
        if (*counter_enchanted_room > 5)
        {
            *n2 = *n2 - 1;
            *counter_enchanted_room = 0;
        }
    }
    else if (floor == 2)
    {
        for (int i = starty[Enchant_Room_floor2]; i < starty[Enchant_Room_floor2] + height[Enchant_Room_floor2]; i++)
        {
            for (int j = startx[Enchant_Room_floor2]; j < startx[Enchant_Room_floor2] + width[Enchant_Room_floor2]; j++)
            {
                if (y == i && x == j)
                {
                    *counter_enchanted_room = *counter_enchanted_room + 1;
                }
            }
        }
        if (*counter_enchanted_room > 5)
        {
            *n2 = *n2 - 1;
            *counter_enchanted_room = 0;
        }
    }
}
void tale()
{
    int num_of_tale_floor1 = rand() % 10 + 20;
    for (int i = 0; i < num_of_tale_floor1; i++)
    {
        tale_room_floor1 = rand() % 7;
        int y = rand() % (height[tale_room_floor1] - 2) + 1;
        int x = rand() % (width[tale_room_floor1] - 2) + 1;
        int sheddat_tale = rand() % 4;

        if (sheddat_tale == 3)
            map1[y + starty[tale_room_floor1]][x + startx[tale_room_floor1]] = '?';
        else
            map1[y + starty[tale_room_floor1]][x + startx[tale_room_floor1]] = '!';
    }

    ///////////////////////////////////////////////////////////////////////////////

    int num_of_tale_floor2 = rand() % 10 + 20;
    for (int i = 0; i < num_of_tale_floor2; i++)
    {
        tale_room_floor2 = rand() % 8 + 7;
        int y = rand() % (height[tale_room_floor2] - 2) + 1;
        int x = rand() % (width[tale_room_floor2] - 2) + 1;
        int sheddat_tale = rand() % 4;

        if (sheddat_tale == 3)
            map2[y + starty[tale_room_floor2]][x + startx[tale_room_floor2]] = '?';
        else
            map2[y + starty[tale_room_floor2]][x + startx[tale_room_floor2]] = '!';
    }
}
void snake_room()
{
    int num_of_snake_floor1 = rand() % 4 + 6;
    for (int i = 0; i < num_of_snake_floor1; i++)
    {
        snake_room_floor1 = rand() % 7;
        int y = rand() % (height[snake_room_floor1] - 2) + 1;
        int x = rand() % (width[snake_room_floor1] - 2) + 1;
        if (snake_floor1[y + starty[snake_room_floor1]][x + startx[snake_room_floor1]] != 'S')
            snake_floor1[y + starty[snake_room_floor1]][x + startx[snake_room_floor1]] = 'S';
    }

    int num_of_snake_floor2 = rand() % 4 + 6;
    for (int i = 0; i < num_of_snake_floor2; i++)
    {
        snake_room_floor2 = rand() % 8 + 7;
        int y = rand() % (height[snake_room_floor2] - 2) + 1;
        int x = rand() % (width[snake_room_floor2] - 2) + 1;
        if (snake_floor2[y + starty[snake_room_floor2]][x + startx[snake_room_floor2]] != 'S')
            snake_floor2[y + starty[snake_room_floor2]][x + startx[snake_room_floor2]] = 'S';
    }
}
char previous(int y, int x)
{
    int previous_char = mvinch(y, x);
    return previous_char;
}
void snake(int floor, int select_room, int y, int x, int *n2)
{
    chtype previous_char;

    if (floor == 1)
    {
        if (select_room != 0)
        {
            for (int i = starty[select_room - 1]; i < starty[select_room - 1] + height[select_room - 1] - 1; i++)
            {
                for (int j = startx[select_room - 1]; j < startx[select_room - 1] + width[select_room - 1] - 1; j++)
                {
                    if (snake_floor1[i][j] == 'S' || snake_floor1[i][j] == 's')
                    {
                        int y1 = i, x1 = j;
                        previous_char = mvinch(i, j);
                        attron(A_BOLD);
                        attron(COLOR_PAIR(7));
                        mvaddch(i, j, snake_floor1[i][j]);
                        attroff(COLOR_PAIR(7));
                        attroff(A_BOLD);

                        statuse_snake_floor1[i][j] = 1;

                        if (abs(y - y1) >= abs(x - x1))
                        {
                            if ((y > i) && (previous(i + 1, j) != 'O') && (previous(i + 1, j) != '_') && (previous(i + 1, j) != '|') && (previous(i + 1, j) != '=') && (snake_floor1[i + 1][j] != 'S') && (snake_floor1[i + 1][j] != 's'))
                                i++;
                            else if ((y < i) && (previous(i - 1, j) != 'O') && (previous(i - 1, j) != '_') && (previous(i - 1, j) != '|') && (previous(i - 1, j) != '=') && (snake_floor1[i - 1][j] != 'S') && (snake_floor1[i - 1][j] != 's'))
                                i--;
                            else if ((x > j) && (previous(i, j + 1) != 'O') && (previous(i, j + 1) != '_') && (previous(i, j + 1) != '|') && (previous(i, j + 1) != '=') && (snake_floor1[i][j + 1] != 'S') && (snake_floor1[i][j + 1] != 's'))
                                j++;
                            else if ((x < j) && (previous(i, j - 1) != 'O') && (previous(i, j - 1) != '_') && (previous(i, j - 1) != '|') && (previous(i, j - 1) != '=') && (snake_floor1[i][j - 1] != 'S') && (snake_floor1[i][j - 1] != 's'))
                                j--;
                        }
                        else
                        {
                            if ((x > j) && (previous(i, j + 1) != 'O') && (previous(i, j + 1) != '_') && (previous(i, j + 1) != '|') && (previous(i, j + 1) != '=') && (snake_floor1[i][j + 1] != 'S') && (snake_floor1[i][j + 1] != 's'))
                                j++;
                            else if ((x < j) && (previous(i, j - 1) != 'O') && (previous(i, j - 1) != '_') && (previous(i, j - 1) != '|') && (previous(i, j - 1) != '=') && (snake_floor1[i][j - 1] != 'S') && (snake_floor1[i][j - 1] != 's'))
                                j--;
                            else if ((y > i) && (previous(i + 1, j) != 'O') && (previous(i + 1, j) != '_') && (previous(i + 1, j) != '|') && (previous(i + 1, j) != '=') && (snake_floor1[i + 1][j] != 'S') && (snake_floor1[i + 1][j] != 's'))
                                i++;
                            else if ((y < i) && (previous(i - 1, j) != 'O') && (previous(i - 1, j) != '_') && (previous(i - 1, j) != '|') && (previous(i - 1, j) != '=') && (snake_floor1[i - 1][j] != 'S') && (snake_floor1[i - 1][j] != 's'))
                                i--;
                        }

                        if (snake_floor1[y1][x1] == 'S')
                        {
                            snake_floor1[i][j] = 'S';
                        }
                        else if (snake_floor1[y1][x1] = 's')
                        {
                            snake_floor1[i][j] = 's';
                        }
                        snake_floor1[y1][x1] = ' ';
                        mvaddch(y1, x1, previous_char);
                        attron(A_BOLD);
                        attron(COLOR_PAIR(7));
                        mvaddch(i, j, snake_floor1[i][j]);
                        attroff(COLOR_PAIR(7));
                        attroff(A_BOLD);

                        statuse_snake_floor1[i][j] = 1;

                        if ((abs(y - i) == 1 && abs(x - j) == 0) || (abs(x - j) == 1 && abs(y - i) == 0))
                        {
                            *n2 = *n2 - 1;
                        }
                    }
                }
            }
        }

        else if (select_room == 0)
        {
            for (int i = 3; i < 42; i++)
            {
                for (int j = 3; j < 181; j++)
                {
                    if ((snake_floor1[i][j] == 'S' || snake_floor1[i][j] == 's') && statuse_snake_floor1[i][j] == 1)
                    {
                        attron(A_BOLD);
                        mvaddch(i, j, map1[i][j]);
                        attroff(A_BOLD);
                    }
                }
            }
        }
    }

    else if (floor == 2)
    {
        if (select_room != 0)
        {
            for (int i = starty[select_room - 1]; i < starty[select_room - 1] + height[select_room - 1] - 1; i++)
            {
                for (int j = startx[select_room - 1]; j < startx[select_room - 1] + width[select_room - 1] - 1; j++)
                {
                    if (snake_floor2[i][j] == 'S' || snake_floor2[i][j] == 's')
                    {
                        int y1 = i, x1 = j;
                        previous_char = mvinch(i, j);
                        attron(A_BOLD);
                        attron(COLOR_PAIR(7));
                        mvaddch(i, j, snake_floor2[i][j]);
                        attroff(COLOR_PAIR(7));
                        attroff(A_BOLD);

                        statuse_snake_floor2[i][j] = 1;

                        if (abs(y - y1) >= abs(x - x1))
                        {
                            if ((y > i) && (previous(i + 1, j) != 'O') && (previous(i + 1, j) != '_') && (previous(i + 1, j) != '|') && (previous(i + 1, j) != '=') && (snake_floor2[i + 1][j] != 'S') && (snake_floor2[i + 1][j] != 's'))
                                i++;
                            else if ((y < i) && (previous(i - 1, j) != 'O') && (previous(i - 1, j) != '_') && (previous(i - 1, j) != '|') && (previous(i - 1, j) != '=') && (snake_floor2[i - 1][j] != 'S') && (snake_floor2[i - 1][j] != 's'))
                                i--;
                            else if ((x > j) && (previous(i, j + 1) != 'O') && (previous(i, j + 1) != '_') && (previous(i, j + 1) != '|') && (previous(i, j + 1) != '=') && (snake_floor2[i][j + 1] != 'S') && (snake_floor2[i][j + 1] != 's'))
                                j++;
                            else if ((x < j) && (previous(i, j - 1) != 'O') && (previous(i, j - 1) != '_') && (previous(i, j - 1) != '|') && (previous(i, j - 1) != '=') && (snake_floor2[i][j - 1] != 'S') && (snake_floor2[i][j - 1] != 's'))
                                j--;
                        }
                        else
                        {
                            if ((x > j) && (previous(i, j + 1) != 'O') && (previous(i, j + 1) != '_') && (previous(i, j + 1) != '|') && (previous(i, j + 1) != '=') && (snake_floor2[i][j + 1] != 'S') && (snake_floor2[i][j + 1] != 's'))
                                j++;
                            else if ((x < j) && (previous(i, j - 1) != 'O') && (previous(i, j - 1) != '_') && (previous(i, j - 1) != '|') && (previous(i, j - 1) != '=') && (snake_floor2[i][j - 1] != 'S') && (snake_floor2[i][j - 1] != 's'))
                                j--;
                            else if ((y > i) && (previous(i + 1, j) != 'O') && (previous(i + 1, j) != '_') && (previous(i + 1, j) != '|') && (previous(i + 1, j) != '=') && (snake_floor2[i + 1][j] != 'S') && (snake_floor2[i + 1][j] != 's'))
                                i++;
                            else if ((y < i) && (previous(i - 1, j) != 'O') && (previous(i - 1, j) != '_') && (previous(i - 1, j) != '|') && (previous(i - 1, j) != '=') && (snake_floor2[i - 1][j] != 'S') && (snake_floor2[i - 1][j] != 's'))
                                i--;
                        }
                        if (snake_floor2[y1][x1] == 'S')
                        {
                            snake_floor2[i][j] = 'S';
                        }
                        else if (snake_floor2[y1][x1] = 's')
                        {
                            snake_floor2[i][j] = 's';
                        }
                        mvaddch(y1, x1, previous_char);
                        attron(A_BOLD);
                        attron(COLOR_PAIR(7));
                        mvaddch(i, j, snake_floor2[i][j]);
                        attroff(COLOR_PAIR(7));
                        attroff(A_BOLD);

                        statuse_snake_floor2[i][j] = 1;

                        if ((abs(y - i) == 1 && abs(x - j) == 0) || (abs(x - j) == 1 && abs(y - i) == 0))
                        {
                            *n2 = *n2 - 1;
                        }
                    }
                }
            }
        }

        else if (select_room == 0)
        {
            for (int i = 3; i < 42; i++)
            {
                for (int j = 3; j < 181; j++)
                {
                    if ((snake_floor2[i][j] == 'S' || snake_floor2[i][j] == 's') && statuse_snake_floor2[i][j] == 1)
                    {
                        attron(A_BOLD);
                        mvaddch(i, j, map2[i][j]);
                        attroff(A_BOLD);
                    }
                }
            }
        }
    }
}
void Gold()
{
    int num_of_gold_floor1 = rand() % 5 + 5;
    for (int i = 0; i < num_of_gold_floor1; i++)
    {
        gold_floor1[i] = rand() % 7 + 1;

        x_floor1_gold[i] = startx[gold_floor1[i] - 1] + rand() % (width[gold_floor1[i] - 1] - 2) + 1;
        y_floor1_gold[i] = starty[gold_floor1[i] - 1] + rand() % (height[gold_floor1[i] - 1] - 2) + 1;

        if (map1[y_floor1_gold[i]][x_floor1_gold[i]] == '.')
        {
            floor1_food[y_floor1_gold[i]][x_floor1_gold[i]] = '$';
        }
    }
}
void gold_counter(int i, int y, int x, int meghdar)
{
    for (int j = 0; j < 2; j++)
    {
        if (i == gold_floor1[j])
        {
            mvaddch(y_floor1_gold[j], x_floor1_gold[j], floor1_gold[y_floor1_gold[j]][x_floor1_gold[j]]);
            statuse_gold_floor1[j] = 1;
        }
        if (y == y_floor1_gold[j] && x == x_floor1_gold[j] && floor1_gold[y][x] == '$')
        {
            mvaddch(y_floor1_gold[j], x_floor1_gold[j], 'O');

            score = score + meghdar;
            attron(COLOR_PAIR(4));
            mvprintw(1, 3, "You found gold!");
            attroff(COLOR_PAIR(4));
            while (getch() != 32)
            {
            }
            mvprintw(1, 3, "                                                            ");
            floor1_gold[y][x] = '.';
            mvaddch(y_floor1_gold[j], x_floor1_gold[j], floor1_gold[y_floor1_gold[j]][x_floor1_gold[j]]);
        }
        if (i == 0 && statuse_gold_floor1[j] == 1)
        {
            mvaddch(y_floor1_gold[j], x_floor1_gold[j], '.');
        }
        mvprintw(43, 65, "%d", score);
    }
}

void handle_motion_input()
{

    attron(A_BOLD);
    int floor = 1;
    int transfer = 0;

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
    print_food(floor, select_room, y, x, &n1);
    gold_counter(select_room, y, x, meghdar_gold[y][x]);
    int count_message = 0;
    int count_hunger = 0;
    int count_health = 0;
    int count_enchanted_room = 0;
    Health(&n2, &count_health);
    int exit = 0;
    while (1)
    {
        margin();

        int previous_x = x;
        int previous_y = y;

        if (floor == 1)
        {
            int A = getch();
            switch (A)
            {

            case '8':

                if (map1[y - 1][x] == '.' || map1[y - 1][x] == '=' || map1[y - 1][x] == '*' || map1[y - 1][x] == '>' || map1[y - 1][x] == '?' || map1[y - 1][x] == '!')
                {
                    y--;
                    if (snake_floor1[y][x] == 'S')
                    {
                        snake_floor1[y][x] = 's';
                        y++;
                    }
                    else if (snake_floor1[y][x] == 's')
                    {
                        snake_floor1[y][x] = ' ';
                        y++;
                    }
                }
                break;
            case '2':

                if (map1[y + 1][x] == '.' || map1[y + 1][x] == '=' || map1[y + 1][x] == '*' || map1[y + 1][x] == '>' || map1[y + 1][x] == '?' || map1[y + 1][x] == '!')
                {
                    y++;
                    if (snake_floor1[y][x] == 'S')
                    {
                        snake_floor1[y][x] = 's';
                        y--;
                    }
                    else if (snake_floor1[y][x] == 's')
                    {
                        snake_floor1[y][x] = ' ';
                        y--;
                    }
                }
                break;
            case '6':

                if (map1[y][x + 1] == '.' || map1[y][x + 1] == '=' || map1[y][x + 1] == '*' || map1[y][x + 1] == '>' || map1[y][x + 1] == '?' || map1[y][x + 1] == '!')
                {
                    x++;
                    if (snake_floor1[y][x] == 'S')
                    {
                        snake_floor1[y][x] = 's';
                        x--;
                    }
                    else if (snake_floor1[y][x] == 's')
                    {
                        snake_floor1[y][x] = ' ';
                        x--;
                    }
                }
                break;
            case '4':

                if (map1[y][x - 1] == '.' || map1[y][x - 1] == '=' || map1[y][x - 1] == '*' || map1[y][x - 1] == '>' || map1[y][x - 1] == '?' || map1[y][x - 1] == '!')
                {
                    x--;
                    if (snake_floor1[y][x] == 'S')
                    {
                        snake_floor1[y][x] = 's';
                        x++;
                    }
                    else if (snake_floor1[y][x] == 's')
                    {
                        snake_floor1[y][x] = ' ';
                        x++;
                    }
                }
                break;
            case '3':
                if (map1[y + 1][x + 1] == '.' || map1[y + 1][x + 1] == '=' || map1[y + 1][x + 1] == '*' || map1[y + 1][x + 1] == '>' || map1[y + 1][x + 1] == '?' || map1[y + 1][x + 1] == '!')
                {
                    x++;
                    y++;
                    if (snake_floor1[y][x] == 'S')
                    {
                        snake_floor1[y][x] = 's';
                        y++;
                        x++;
                    }
                    else if (snake_floor1[y][x] == 's')
                    {
                        snake_floor1[y][x] = ' ';
                        y++;
                        x++;
                    }
                }
                break;
            case '7':
                if (map1[y - 1][x - 1] == '.' || map1[y - 1][x - 1] == '=' || map1[y - 1][x - 1] == '*' || map1[y - 1][x - 1] == '>' || map1[y - 1][x - 1] == '?' || map1[y - 1][x - 1] == '!')
                {
                    x--;
                    y--;
                    if (snake_floor1[y][x] == 'S')
                    {
                        snake_floor1[y][x] = 's';
                        y--;
                        x--;
                    }
                    else if (snake_floor1[y][x] == 's')
                    {
                        snake_floor1[y][x] = ' ';
                        y--;
                        x--;
                    }
                }
                break;
            case '9':
                if (map1[y - 1][x + 1] == '.' || map1[y - 1][x + 1] == '=' || map1[y - 1][x + 1] == '*' || map1[y - 1][x + 1] == '>' || map1[y - 1][x + 1] == '?' || map1[y - 1][x + 1] == '!')
                {
                    y--;
                    x++;
                    if (snake_floor1[y][x] == 'S')
                    {
                        snake_floor1[y][x] = 's';
                        y--;
                        x++;
                    }
                    else if (snake_floor1[y][x] == 's')
                    {
                        snake_floor1[y][x] = ' ';
                        y--;
                        x++;
                    }
                }
                break;
            case '1':
                if (map1[y + 1][x - 1] == '.' || map1[y + 1][x - 1] == '=' || map1[y + 1][x - 1] == '*' || map1[y + 1][x - 1] == '>' || map1[y + 1][x - 1] == '?' || map1[y + 1][x - 1] == '!')
                {
                    y++;
                    x--;
                    if (snake_floor1[y][x] == 'S')
                    {
                        snake_floor1[y][x] = 's';
                        y++;
                        x--;
                    }
                    else if (snake_floor1[y][x] == 's')
                    {
                        snake_floor1[y][x] = ' ';
                        y++;
                        x--;
                    }
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

                if (Enchant_Room_floor1 == select_room - 1)
                {
                    attron(COLOR_PAIR(1));
                    mvprintw(1, 3, "You have entered the enchanted room! Staying in this room will reduce your health!");
                    attroff(COLOR_PAIR(1));
                    while (getch() != 32)
                    {
                    }
                    mvprintw(1, 3, "                                                                                       ");
                }
            }
            if (map1[y][x] == '*')
            {
                select_room = 0;
            }
            if (select_room < 8)
            {
                print_room(select_room);
                print_food(floor, select_room, y, x, &n1);
                gold_counter(select_room, y, x, meghdar_gold[y][x]);
            }
            if (exit != 0)
            {
                break;
            }

            mvaddch(previous_y, previous_x, previous_char);

            previous_char = mvinch(y, x);

            mvaddch(y, x, 'O');
            refresh();

            Enchant_Room(floor, y, x, &n2, &count_enchanted_room);
            snake(floor, select_room, y, x, &n2);

            if (map1[y][x] == '!')
            {
                attron(COLOR_PAIR(1));
                mvprintw(1, 3, "You fell into a trap! One of your health points has been lost.");
                attroff(COLOR_PAIR(1));
                while (getch() != 32)
                {
                }
                mvprintw(1, 3, "                                                                            ");

                n2--;
            }
            if (map1[y][x] == '?')
            {
                attron(COLOR_PAIR(1));
                mvprintw(1, 3, "You fell into a trap! Two health points were lost.");
                attroff(COLOR_PAIR(1));
                while (getch() != 32)
                {
                }
                mvprintw(1, 3, "                                                                            ");
                n2 = n2 - 2;
            }

            if (map1[y][x] == '>')
            {
                attron(A_BOLD);
                attron(COLOR_PAIR(4));
                mvprintw(1, 3, "You can press '>' key to go to the next floor!(first press 'space' key)");
                attroff(COLOR_PAIR(4));
                while (getch() != 32)
                {
                }
                mvprintw(1, 3, "                                                                          ");
                if (getch() == '>')
                {
                    for (int i = 3; i < 42; i++)
                    {
                        for (int j = 3; j < 181; j++)
                        {
                            save_map1[i][j] = mvinch(i, j);
                        }
                    }
                    // clear
                    for (int i = 3; i < 42; i++)
                    {
                        for (int j = 3; j < 181; j++)
                        {
                            mvaddch(i, j, ' ');
                        }
                    }

                    floor = 2;

                    for (int i = 3; i < 42; i++)
                    {
                        for (int j = 3; j < 181; j++)
                        {
                            mvaddch(i, j, save_map2[i][j]);
                        }
                    }
                    print_room(14);
                    y = starty[13] + (height[stair1] / 2);
                    x = startx[13] + (width[stair1] / 2);
                    previous_char = mvinch(y, x);
                    mvaddch(y, x, 'O');
                }
                attroff(A_BOLD);
            }
        }

        else if (floor == 2)
        {
            int A = getch();
            switch (A)
            {

            case '8':

                if (map2[y - 1][x] == '.' || map2[y - 1][x] == '=' || map2[y - 1][x] == '*' || map2[y - 1][x] == '<' || map2[y - 1][x] == '?' || map2[y - 1][x] == '!')
                {
                    y--;
                    if (snake_floor2[y][x] == 'S')
                    {
                        snake_floor2[y][x] = 's';
                        y++;
                    }
                    else if (snake_floor2[y][x] == 's')
                    {
                        snake_floor2[y][x] = ' ';
                        y++;
                    }
                }
                break;
            case '2':

                if (map2[y + 1][x] == '.' || map2[y + 1][x] == '=' || map2[y + 1][x] == '*' || map2[y + 1][x] == '<' || map2[y + 1][x] == '?' || map2[y + 1][x] == '!')
                {
                    y++;
                    if (snake_floor2[y][x] == 'S')
                    {
                        snake_floor2[y][x] = 's';
                        y--;
                    }
                    else if (snake_floor2[y][x] == 's')
                    {
                        snake_floor2[y][x] = ' ';
                        y--;
                    }
                }
                break;
            case '6':

                if (map2[y][x + 1] == '.' || map2[y][x + 1] == '=' || map2[y][x + 1] == '*' || map2[y][x + 1] == '<' || map2[y][x + 1] == '?' || map2[y][x + 1] == '!')
                {
                    x++;
                    if (snake_floor2[y][x] == 'S')
                    {
                        snake_floor2[y][x] = 's';
                        x--;
                    }
                    else if (snake_floor2[y][x] == 's')
                    {
                        snake_floor2[y][x] = ' ';
                        x--;
                    }
                }
                break;
            case '4':

                if (map2[y][x - 1] == '.' || map2[y][x - 1] == '=' || map2[y][x - 1] == '*' || map2[y][x - 1] == '<' || map2[y][x - 1] == '?' || map2[y][x - 1] == '!')
                {
                    x--;
                    if (snake_floor2[y][x] == 'S')
                    {
                        snake_floor2[y][x] = 's';
                        x++;
                    }
                    else if (snake_floor2[y][x] == 's')
                    {
                        snake_floor2[y][x] = ' ';
                        x++;
                    }
                }
                break;
            case '3':
                if (map2[y + 1][x + 1] == '.' || map2[y + 1][x + 1] == '=' || map2[y + 1][x + 1] == '*' || map2[y + 1][x + 1] == '<' || map2[y + 1][x + 1] == '?' || map2[y + 1][x + 1] == '!')
                {
                    x++;
                    y++;
                    if (snake_floor2[y][x] == 'S')
                    {
                        snake_floor2[y][x] = 's';
                        y--;
                        x--;
                    }
                    else if (snake_floor2[y][x] == 's')
                    {
                        snake_floor2[y][x] = ' ';
                        y--;
                        x--;
                    }
                }
                break;
            case '7':
                if (map2[y - 1][x - 1] == '.' || map2[y - 1][x - 1] == '=' || map2[y - 1][x - 1] == '*' || map2[y - 1][x - 1] == '<' || map2[y - 1][x - 1] == '?' || map2[y - 1][x - 1] == '!')
                {
                    x--;
                    y--;
                    if (snake_floor2[y][x] == 'S')
                    {
                        snake_floor2[y][x] = 's';
                        y++;
                        x++;
                    }
                    else if (snake_floor2[y][x] == 's')
                    {
                        snake_floor2[y][x] = ' ';
                        y++;
                        x++;
                    }
                }
                break;
            case '9':
                if (map2[y - 1][x + 1] == '.' || map2[y - 1][x + 1] == '=' || map2[y - 1][x + 1] == '*' || map2[y - 1][x + 1] == '<' || map2[y - 1][x + 1] == '?' || map2[y - 1][x + 1] == '!')
                {
                    y--;
                    x++;
                    if (snake_floor2[y][x] == 'S')
                    {
                        snake_floor2[y][x] = 's';
                        y++;
                        x--;
                    }
                    else if (snake_floor2[y][x] == 's')
                    {
                        snake_floor2[y][x] = ' ';
                        y++;
                        x--;
                    }
                }
                break;
            case '1':
                if (map2[y + 1][x - 1] == '.' || map2[y + 1][x - 1] == '=' || map2[y + 1][x - 1] == '*' || map2[y + 1][x - 1] == '<' || map2[y + 1][x - 1] == '?' || map2[y + 1][x - 1] == '!')
                {
                    y++;
                    x--;
                    if (snake_floor2[y][x] == 'S')
                    {
                        snake_floor2[y][x] = 's';
                        y--;
                        x++;
                    }
                    else if (snake_floor2[y][x] == 's')
                    {
                        snake_floor2[y][x] = ' ';
                        y--;
                        x++;
                    }
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
                    if (map2[y + i][x + j] == '*')
                    {
                        attron(COLOR_PAIR(2));
                        mvaddch(y + i, x + j, '.');
                        attroff(COLOR_PAIR(2));
                    }
                    else if (map2[y + i][x + j] == '=')
                    {
                        attron(COLOR_PAIR(1));
                        mvaddch(y + i, x + j, map2[y + i][x + j]);
                        attroff(COLOR_PAIR(1));
                    }
                }
            }

            if (map2[y][x] == '=')
            {

                if ((y == starty[7] + y_door_down[7] && x == startx[7] + x_door_down[7] + 1) || (y == starty[7] + y_door_right[7] + 1 && x == startx[7] + x_door_right[7]))
                    select_room = 8;
                else if ((y == starty[8] + y_door_down[8] && x == startx[8] + x_door_down[8] + 1) || (y == starty[8] + y_door_left[8] + 1 && x == startx[8] + x_door_right[8]))
                    select_room = 9;
                else if ((y == starty[9] + y_door_down[9] && x == startx[9] + x_door_down[9] + 1) || (y == starty[9] + y_door_right[9] + 1 && x == startx[9] + x_door_right[9]))
                    select_room = 10;
                else if ((y == starty[10] + y_door_left[10] + 1 && x == startx[10] + x_door_left[10]) || (y == starty[10] + y_door_down[10] && x == startx[10] + x_door_down[10] + 1) || (y == starty[10] + y_door_up[10] && x == startx[10] + x_door_up[10] + 1))
                    select_room = 11;
                else if (y == starty[11] + y_door_up[11] && x == startx[11] + x_door_up[11] + 1)
                    select_room = 12;
                else if ((y == starty[12] + y_door_up[12] && x == startx[12] + x_door_up[12] + 1) || (y == starty[12] + y_door_right[12] + 1 && x == startx[12] + x_door_right[12]))
                    select_room = 13;
                else if ((y == starty[13] + y_door_right[13] + 1 && x == startx[13] + x_door_right[13]) || (y == starty[13] + y_door_up[13] && x == startx[13] + x_door_up[13] + 1))
                    select_room = 14;
                else if ((y == starty[14] + y_door_left[14] + 1 && x == startx[14] + x_door_left[14]) || (y == starty[14] + y_door_up[14] && x == startx[14] + x_door_up[14] + 1))
                    select_room = 15;
            }
            if (map2[y][x] == '*')
            {
                select_room = 0;
            }
            if (select_room > 7 || select_room < 1)
            {
                print_room(select_room);
                print_food(floor, select_room, y, x, &n1);
            }
            if (exit != 0)
            {
                break;
            }

            mvaddch(previous_y, previous_x, previous_char);

            previous_char = mvinch(y, x);

            mvaddch(y, x, 'O');
            refresh();
            Enchant_Room(floor, y, x, &n2, &count_enchanted_room);
            // snake(floor, select_room, y, x, &n2);
            if (map2[y][x] == '!')
            {
                attron(COLOR_PAIR(1));
                mvprintw(1, 3, "You fell into a trap! One of your health points has been lost.");
                attroff(COLOR_PAIR(1));
                while (getch() != 32)
                {
                }
                mvprintw(1, 3, "                                                                            ");

                n2--;
            }
            if (map2[y][x] == '?')
            {
                attron(COLOR_PAIR(1));
                mvprintw(1, 3, "You fell into a trap! Two health points were lost.");
                attroff(COLOR_PAIR(1));
                while (getch() != 32)
                {
                }
                mvprintw(1, 3, "                                                                            ");
                n2 = n2 - 2;
            }
            if (map2[y][x] == '<')
            {
                attron(A_BOLD);
                attron(COLOR_PAIR(4));
                mvprintw(1, 3, "You can press '<' key to go to the previous floor!(first press 'space' key)");
                attroff(COLOR_PAIR(4));
                while (getch() != 32)
                {
                }
                mvprintw(1, 3, "                                                                                    ");
                if (getch() == '<')
                {
                    for (int i = 3; i < 42; i++)
                    {
                        for (int j = 3; j < 181; j++)
                        {
                            save_map2[i][j] = mvinch(i, j);
                        }
                    }
                    // clear
                    for (int i = 3; i < 42; i++)
                    {
                        for (int j = 3; j < 181; j++)
                        {
                            mvaddch(i, j, ' ');
                        }
                    }
                    floor = 1;

                    for (int i = 3; i < 42; i++)
                    {
                        for (int j = 3; j < 181; j++)
                        {
                            // if (save_map1[i][j] == '_' || save_map1[i][j] == '|' || save_map1[i][j] == '=')
                            mvaddch(i, j, save_map1[i][j]);
                        }
                    }
                    print_room(stair1 + 1);
                    y = starty[stair1] + (height[stair1] / 2);
                    x = startx[stair1] + (width[stair1] / 2);
                    previous_char = mvinch(y, x);
                    mvaddch(y, x, 'O');
                }
                attroff(A_BOLD);
            }
        }
        //////////////////////////////////////////////
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
    }

    attroff(A_BOLD);
}
void corridor_tool(int floor, int x, int y, int x2, int y2)
{
    if (floor == 1)
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
    else if (floor == 2)
    {
        map2[y][x] = '*';

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

                    if (map2[y][x] != '=' && map2[y][x] != '|' && map2[y][x] != '_')
                    {

                        map2[y][x] = '*';
                    }
                    else if (map2[y][x] == '=' || map2[y][x] == '|' || map2[y][x] == '_')
                    {
                        if (y == y2)
                        {
                            while (map2[y][x] == '=' || map2[y][x] == '|' || map2[y][x] == '_')
                            {
                                y--;

                                (x2 > x) ? (map2[y][x - 1] = '*') : (map2[y][x + 1] = '*');
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
                    if (map2[y][x] != '=' && map2[y][x] != '|' && map2[y][x] != '_')
                    {

                        map2[y][x] = '*';
                    }
                    else if (map2[y][x] == '=' || map2[y][x] == '|' || map2[y][x] == '_')
                    {

                        if (x == x2)
                        {
                            while (map2[y][x] == '=' || map2[y][x] == '|' || map2[y][x] == '_')
                            {
                                x--;

                                (y2 > y) ? (map2[y - 1][x] = '*') : (map2[y + 1][x] = '*');
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
}
void corridor()
{
    int floor = 1;
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
    corridor_tool(floor, x, y, x2, y2);

    //\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//
    ///////////////////////////////////////    2     //////////////////////////////////////
    x1 = x_door_down[2] + startx[2] + 1, y1 = y_door_down[2] + starty[2] + 1;
    x2 = x_door_up[5] + startx[5] + 1, y2 = y_door_up[5] + starty[5] - 1;
    x = x1, y = y1;

    corridor_tool(floor, x, y, x2, y2);

    //\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//
    ////////////////////////////////////       3       ////////////////////////////////////

    x1 = x_door_right[2] + startx[2] + 1, y1 = y_door_right[2] + starty[2] + 1;
    x2 = x_door_left[3] + startx[3] - 1, y2 = y_door_left[3] + starty[3] + 1;

    x = x1, y = y1;

    corridor_tool(floor, x, y, x2, y2);
    ///////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////    4     ///////////////////////////////////////////////

    x1 = x_door_right[1] + startx[1] + 1, y1 = y_door_right[1] + starty[1] + 1;
    x2 = x_door_left[2] + startx[2] - 1, y2 = y_door_left[2] + starty[2] + 1;

    x = x1, y = y1;

    corridor_tool(floor, x, y, x2, y2);
    ///////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////      5    ///////////////////////////////////////////

    x1 = x_door_right[5] + startx[5] + 1, y1 = y_door_right[5] + starty[5] + 1;
    x2 = x_door_up[4] + startx[4] + 1, y2 = y_door_up[4] + starty[4] - 1;

    x = x1, y = y1;

    corridor_tool(floor, x, y, x2, y2);
    ///////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////      6      ///////////////////////////////////////////////

    x1 = x_door_right[3] + startx[3] + 1, y1 = y_door_right[3] + starty[3] + 1;
    x2 = x_door_left[6] + startx[6] - 1, y2 = y_door_left[6] + starty[6] + 1;

    x = x1, y = y1;

    corridor_tool(floor, x, y, x2, y2);
    ///////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////

    floor = 2;

    //////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////

    x1 = startx[7] + x_door_down[7] + 1, y1 = starty[7] + y_door_down[7] + 1;
    x2 = startx[12] + x_door_up[12] + 1, y2 = starty[12] + y_door_up[12] - 1;

    x = x1, y = y1;

    corridor_tool(floor, x, y, x2, y2);
    ///////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////
    x1 = startx[7] + x_door_right[7] + 1, y1 = starty[7] + y_door_right[7] + 1;
    x2 = startx[10] + x_door_up[10] + 1, y2 = starty[10] + y_door_up[10] - 1;

    x = x1, y = y1;

    corridor_tool(floor, x, y, x2, y2);
    ///////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////
    x1 = startx[8] + x_door_left[8] - 1, y1 = starty[8] + y_door_left[8] + 1;
    x2 = startx[8] + x_door_up[11] + 1, y2 = starty[11] + y_door_up[11] - 1;

    x = x1, y = y1;

    corridor_tool(floor, x, y, x2, y2);
    ///////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////
    x1 = startx[8] + x_door_down[8] + 1, y1 = starty[8] + y_door_down[8] + 1;
    x2 = startx[14] + x_door_up[14] + 1, y2 = starty[14] + y_door_up[14] - 1;

    x = x1, y = y1;

    corridor_tool(floor, x, y, x2, y2);
    ///////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////
    x1 = startx[9] + x_door_right[9] + 1, y1 = starty[9] + y_door_right[9] + 1;
    x2 = startx[10] + x_door_left[10] - 1, y2 = starty[10] + y_door_left[10] + 1;

    x = x1, y = y1;

    corridor_tool(floor, x, y, x2, y2);
    ///////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////
    x1 = startx[10] + x_door_down[10] + 1, y1 = starty[10] + y_door_down[10] + 1;
    x2 = startx[13] + x_door_up[13] + 1, y2 = starty[13] + y_door_up[13] - 1;

    x = x1, y = y1;

    corridor_tool(floor, x, y, x2, y2);
    ///////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////
    x1 = startx[12] + x_door_right[12] + 1, y1 = starty[12] + y_door_right[12] + 1;
    x2 = startx[9] + x_door_down[9] + 1, y2 = starty[9] + y_door_down[9] + 1;

    x = x1, y = y1;

    corridor_tool(floor, x, y, x2, y2);
    ///////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////
    x1 = startx[13] + x_door_right[13] + 1, y1 = starty[13] + y_door_right[13] + 1;
    x2 = startx[14] + x_door_left[14] - 1, y2 = starty[14] + y_door_left[14] + 1;

    x = x1, y = y1;

    corridor_tool(floor, x, y, x2, y2);
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
    initialization();
    room1();
    stairs();
    room2();
    tale();
    Enchant_Room_select();
    corridor();
    elements();
    food();
    snake_room();
    Gold();
    handle_motion_input();
    endwin();
}

void map()
{
    initialization();
    room1();
    stairs();
    room2();
    tale();
    Enchant_Room_select();
    corridor();
    elements();
    food();
    snake_room();
    Gold();
    handle_motion_input();
}