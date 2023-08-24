#ifndef HEADER_TYPES_H_
#define HEADER_TYPES_H_
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define FRAME_WIDTH     10
#define FRAME_HEIGHT    20
#define BLOCK_TYPE       7
#define BLOCK_DIRECTION  4
#define BLOCK_SIZE       4

enum color {
    BLOCK_COLOR_EMPTY = 0,
    BLOCK_COLOR_BLUE = 1,
    BLOCK_COLOR_GREEN = 2,
    BLOCK_COLOR_SKYBLUE = 3,
    BLOCK_COLOR_RED = 4,
    BLOCK_COLOR_PURPLE = 5,
    BLOCK_COLOR_YELLOW = 6,
    BLOCK_COLOR_EDGE = 7,
    BLOCK_COLOR_GRAY = 8
};

typedef enum {
    KEY_NOTHING = 0,
    KEY_ESCAPE  = 27,
    KEY_LEFT    = 37,
    KEY_UP      = 38,
    KEY_RIGHT   = 39,
    KEY_DOWN    = 40,
    KEY_SPACE   = 32,
    KEY_BUF_SIZE= 10
} enum_key;

typedef struct _dot {
    int fill;
    int color;
} dot_t;


#endif


