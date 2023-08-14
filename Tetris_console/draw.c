#include "draw.h"

static const WCHAR c_block = 0x2588;

static const int c_left_margin = 20;
static const int c_top_margin = 5;

static HANDLE h_in;
static HANDLE h_out;

static COORD l_block;
static COORD l_map_console_coord;
static COORD l_map_console_margin_coord;

// set window
void Init_Draw(void)
{
    SetConsoleTitle(TEXT("Tetris"));
    SetConsoleWindowInfo(h_out, TRUE, &(SMALL_RECT){ 0, 0, 200, 50 });
    h_in = GetStdHandle(STD_INPUT_HANDLE);
    h_out = GetStdHandle(STD_OUTPUT_HANDLE);
    Draw_edge();
}

void Draw_edge(void)
{
    memset(&g_map, 0, sizeof(dot_t) * (FRAME_HEIGHT + 1) * (FRAME_WIDTH + 2));
    //dot_t g_map[FRAME_HEIGHT + 1][FRAME_WIDTH + 2];
    
    for (int i = 0; i < FRAME_HEIGHT; ++i) {
        g_map[i][0].fill = 1;
        g_map[i][FRAME_WIDTH+1].color = block_color_edge;
    }

    for (int i = 0; i < FRAME_WIDTH + 2; ++i) {
        g_map[FRAME_HEIGHT][i].fill = 1;
        g_map[FRAME_HEIGHT][i].color = block_color_edge;
    }

    for (int i = 0; i < FRAME_HEIGHT + 1; ++i) {
        for (int j = 0; j < FRAME_WIDTH + 2; ++j) {
            if (g_map[i][j].fill = 1) {
                g_map_console[i][2 * j].Char.UnicodeChar = c_block;
                g_map_console[i][2 * j].Attributes = FOREGROUND_BLUE | BACKGROUND_GREEN;
                g_map_console[i][2 * j + 1].Char.UnicodeChar = c_block;
                g_map_console[i][2 * j + 1].Attributes = FOREGROUND_BLUE | BACKGROUND_GREEN;
            } else {
                g_map_console[i][2 * j].Char.UnicodeChar = 0;
                g_map_console[i][2 * j].Attributes = BACKGROUND_GREEN;;
                g_map_console[i][2 * j + 1].Char.UnicodeChar = 0;
                g_map_console[i][2 * j + 1].Attributes = BACKGROUND_GREEN;
            }
        }
    }

    l_map_console_coord.X = (FRAME_WIDTH + 2) * 2;
    l_map_console_coord.Y = (FRAME_HEIGHT + 1) * 2;

    l_map_console_margin_coord.X = 0;
    l_map_console_margin_coord.Y = 0;

    WriteConsoleOutput(h_out, &g_map_console, l_map_console_coord, l_map_console_margin_coord, &(SMALL_RECT){ 0, 0, 200, 50 });

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

void Draw_frame(void)
{
    //typedef dot_t frame_block_t[FRAME_WIDTH][FRAME_HEIGHT];
    //frame_block_t* frame_block = mem_play_ground;
}

void Draw_gameover(void)
{

}