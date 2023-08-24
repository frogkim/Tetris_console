#include "header.h"

static const WCHAR c_block = 0x2588;


static HANDLE h_out;

static COORD l_block;
static COORD l_map_console_coord = {(FRAME_WIDTH + 2) * 2, (FRAME_HEIGHT + 1)};
static COORD l_map_default = {0, 0};
static SMALL_RECT l_screen = {20, 5, 60, 35}; // left  top  right  bottom

// static variables
static dot_t map[FRAME_HEIGHT + 1][FRAME_WIDTH + 2];
static dot_t block[BLOCK_SIZE][BLOCK_SIZE];

// helper functions
void Draw_edge(void);
void Draw(void);

// define functions
void Init_Draw(void)
{
    SetConsoleTitle(TEXT("Tetris"));
    SetConsoleWindowInfo(h_out, TRUE, &(SMALL_RECT){ 0, 0, 200, 50 });
    h_out = GetStdHandle(STD_OUTPUT_HANDLE);
    Draw_edge();
    Draw();
}

void Draw_edge(void)
{
    memset(g_map, 0, sizeof(dot_t) * (FRAME_HEIGHT + 1) * (FRAME_WIDTH + 2));
    
    for (int i = 0; i < FRAME_HEIGHT; ++i) {
        g_map[i][0].fill = 1;
        g_map[i][0].color = BLOCK_COLOR_EDGE;
        g_map[i][FRAME_WIDTH + 1].fill = 1;
        g_map[i][FRAME_WIDTH + 1].color = BLOCK_COLOR_EDGE;
    }

    for (int i = 0; i < FRAME_WIDTH + 2; ++i) {
        g_map[FRAME_HEIGHT][i].fill = 1;
        g_map[FRAME_HEIGHT][i].color = BLOCK_COLOR_EDGE;
    }
}

void Draw_menu(void)
{
    // store current screen
    // show menu
}

void Draw_Clear_menu(void)
{
    // close menu and restore last screen
}

void Draw(void)
{
    memcpy(map, g_map, sizeof(dot_t) * (FRAME_HEIGHT + 1) * (FRAME_WIDTH + 2));
    memcpy(block, g_block[g_cur_block.type][g_cur_block.direction], sizeof(dot_t) * BLOCK_SIZE * BLOCK_SIZE);

    // A new block overrides old blocks
    for (int i = 0; i < BLOCK_SIZE; ++i) {
        int y = g_cur_block.y + i; 
        for (int j = 0; j < BLOCK_SIZE; ++j) {
            int x = g_cur_block.x + j;
            if (block[i][j].fill == 1) {
                if (x > 0 || x <= FRAME_WIDTH || y <= FRAME_HEIGHT) {
                    map[y][x].fill = block[i][j].fill;
                    map[y][x].color = block[i][j].color;
                }
            }
        }
    }

    for (int i = 0; i < FRAME_HEIGHT + 1; ++i) {
        for (int j = 0; j < FRAME_WIDTH + 2; ++j) {
            if (map[i][j].fill == 1) {
                g_map_console[i][2 * j].Char.UnicodeChar = c_block;
                g_map_console[i][2 * j].Attributes = map[i][j].color;
                g_map_console[i][2 * j + 1].Char.UnicodeChar = c_block;
                g_map_console[i][2 * j + 1].Attributes = map[i][j].color;
            } else {
                g_map_console[i][2 * j].Char.UnicodeChar = c_block;
                g_map_console[i][2 * j].Attributes = BLOCK_COLOR_EMPTY;
                g_map_console[i][2 * j + 1].Char.UnicodeChar = c_block;
                g_map_console[i][2 * j + 1].Attributes = BLOCK_COLOR_EMPTY;
            }
        }
    }
    WriteConsoleOutput(h_out, (CHAR_INFO*)g_map_console, l_map_console_coord, l_map_default, &l_screen);
}

void Draw_gameover(void)
{

}