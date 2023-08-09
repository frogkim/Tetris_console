#include "drawing.h"

static const WCHAR c_block = 0x2588;

static const int c_left_margin = 20;
static const int c_top_margin = 5;

static HANDLE h_in;
static HANDLE h_out;

// set window
void Windows_Init(void)
{
    SetConsoleTitle(TEXT("Tetris"));
    SetConsoleWindowInfo(h_out, TRUE, &(SMALL_RECT){ 0, 0, 200, 50 });
    h_in = GetStdHandle(STD_INPUT_HANDLE);
    h_out = GetStdHandle(STD_OUTPUT_HANDLE);
    Draw_main_frame();
}

void Draw_main_frame(void)
{
    DWORD n_Written;
    COORD ch_pos;
    
    // draw left and right side
    for (int i = c_top_margin; i < FRAME_HEIGHT + c_top_margin; ++i)
    {
        ch_pos.X = c_left_margin * 2;
        ch_pos.Y = i;
        WriteConsoleOutputCharacterW(h_out, &c_block, 1, ch_pos, &n_Written);
        ++ch_pos.X;
        WriteConsoleOutputCharacterW(h_out, &c_block, 1, ch_pos, &n_Written);
        ++ch_pos.X;
        ch_pos.X += FRAME_WIDTH * 2;
        WriteConsoleOutputCharacterW(h_out, &c_block, 1, ch_pos, &n_Written);
        ++ch_pos.X;
        WriteConsoleOutputCharacterW(h_out, &c_block, 1, ch_pos, &n_Written);
    }

    // draw bottom
    ch_pos.X = (c_left_margin + 1) * 2;
    while (ch_pos.X < (c_left_margin + 1 + FRAME_WIDTH) * 2)
    {
        WriteConsoleOutputCharacterW(h_out, &c_block, 1, ch_pos, &n_Written);
        ++ch_pos.X;
    }
}

void Draw_menu(void)
{
    // store current screen
    // show menu
}

void Clear_menu(void)
{
    // close menu and restore last screen
}

void Draw(void) 
{
    //typedef dot_t frame_block_t[FRAME_WIDTH][FRAME_HEIGHT];
    //frame_block_t* frame_block = mem_play_ground;
}