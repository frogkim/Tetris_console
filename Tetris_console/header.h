#ifndef HEADER_H_
#define HEADER_H_
#include "header_types.h"

// gloval variables
BOOL g_escape;
BOOL g_game_over;
int g_level;

struct {
    int x;
    int y;
    int type;
    int direction;
} g_cur_block;

struct {
    char max;
    unsigned int up;
    unsigned int left;
    unsigned int right;
    unsigned int down;
    unsigned int space;
} g_key;

dot_t g_map[FRAME_HEIGHT + 1][FRAME_WIDTH + 2];
CHAR_INFO g_map_console[FRAME_HEIGHT + 1][(FRAME_WIDTH + 2) * 2];
dot_t g_block[BLOCK_TYPE][BLOCK_DIRECTION][BLOCK_SIZE][BLOCK_SIZE];

// thread functions
LPTHREAD_START_ROUTINE   key_collect_func(void);
LPTHREAD_START_ROUTINE   run_func(void);
LPTHREAD_START_ROUTINE   clock_func(void);

// mutex handle
HANDLE h_mutex_key;


// draw functions
void Init_Draw(void);
void Draw_menu(void);
void Draw_Clear_menu(void);
void Draw_gameover(void);
void Draw(void);

// block functions
void Init_block(void);
void Appear_block(void);
BOOL Move_block(enum_key);
BOOL Rotate_block(void);

// clock functions
unsigned long get_count(void);
time_t generate_rand(void);

// frame functions
void Init_frame(void);

// etc
void assert();

#endif
