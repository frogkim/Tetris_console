#ifndef HEADER_H_
#define HEADER_H_

#define NULL 0

#define FRAME_WIDTH     10
#define FRAME_HEIGHT    20
#define BLOCK_TYPE       7
#define BLOCK_DIRECTION  4
#define BLOCK_SIZE       4

#define KEY_LEFT    0
#define KEY_UP      0
#define KEY_RIGHT   0
#define KEY_DOWN    0

typedef unsigned char key_t;

typedef struct _dot{
    int fill;
    int color;
} dot_t;

dot_t g_frame[FRAME_WIDTH][FRAME_HEIGHT];
dot_t g_frame_old[FRAME_WIDTH][FRAME_HEIGHT];
dot_t g_diff[FRAME_WIDTH][FRAME_HEIGHT];

dot_t g_block[BLOCK_TYPE][BLOCK_DIRECTION][BLOCK_SIZE][BLOCK_SIZE];

/* key functions */
void set_key(void);
key_t get_key(void);

/* block functions */
void Init_block(void);
void DeInit_block(void);
void decide_frame(void);
void calculate_diff(void);
#endif


