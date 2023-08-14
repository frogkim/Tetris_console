#ifndef HEADER_H_
#define HEADER_H_
#include <windows.h>

#define FRAME_WIDTH     10
#define FRAME_HEIGHT    20
#define BLOCK_TYPE       7
#define BLOCK_DIRECTION  4
#define BLOCK_SIZE       4

#define KEY_LEFT    0
#define KEY_UP      0
#define KEY_RIGHT   0
#define KEY_DOWN    0

#define block_color_empty 0
#define block_color_empty1 1
#define block_color_empty2 2
#define block_color_empty3 3
#define block_color_empty4 4
#define block_color_empty5 5
#define block_color_empty6 6
#define block_color_empty7 7
#define block_color_edge  8

// typedef
typedef unsigned char key_t;

typedef struct _dot{
    int fill;
    int color;
} dot_t;

//gloval variables
int current_block;

dot_t g_map[FRAME_HEIGHT+1][FRAME_WIDTH + 2];
CHAR_INFO g_map_console[FRAME_HEIGHT + 1][(FRAME_WIDTH + 2) * 2];
dot_t g_block_arr[BLOCK_TYPE][BLOCK_DIRECTION][BLOCK_SIZE][BLOCK_SIZE];

#endif


