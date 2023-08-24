#include "header.h"

// constant
const int c_start_x = 4;
const int c_start_y = 0;

static int color_arr[7] = {
    BLOCK_COLOR_BLUE,
    BLOCK_COLOR_GREEN,
    BLOCK_COLOR_SKYBLUE,
    BLOCK_COLOR_RED,
    BLOCK_COLOR_PURPLE,
    BLOCK_COLOR_YELLOW,
    BLOCK_COLOR_GRAY
};

// helper functions
static void set_block(dot_t dst[BLOCK_TYPE][BLOCK_SIZE], int src[BLOCK_SIZE][BLOCK_SIZE], int color);
static void set_rotate_block(int block[][BLOCK_SIZE]);
static void decide_block(void);
static void remove_lines(void);
static BOOL is_end(void);
// define functions
void Init_block(void)
{

    int block_arr[BLOCK_TYPE][BLOCK_SIZE][BLOCK_SIZE] = {
       {{0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}}, // I block
       {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}}, // square block
       {{0, 0, 0, 0}, {0, 1, 1, 1}, {0, 0, 1, 0}, {0, 0, 0, 0}}, // T block
       {{0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}}, // L block
       {{0, 0, 1, 0}, {0, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}}, // reverse L block
       {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 1}, {0, 0, 0, 0}}, // 2 block
       {{0, 0, 0, 0}, {0, 0, 1, 1}, {0, 1, 1, 0}, {0, 0, 0, 0}}  // reverse 2 block
    };

    for (int i = 0; i < BLOCK_TYPE; ++i) {
        //dot_t g_block_arr[BLOCK_TYPE][BLOCK_DIRECTION][BLOCK_SIZE][BLOCK_SIZE];
        set_block(g_block[i][0], block_arr[i], color_arr[i]);
        
        set_rotate_block(block_arr[i]);
        set_block(g_block[i][1], block_arr[i], color_arr[i]);
        
        set_rotate_block(block_arr[i]);
        set_block(g_block[i][2], block_arr[i], color_arr[i]);
        
        set_rotate_block(block_arr[i]);
        set_block(g_block[i][3], block_arr[i], color_arr[i]);
    }
} // end set block

void set_block(dot_t dst[BLOCK_TYPE][BLOCK_SIZE], int src[BLOCK_SIZE][BLOCK_SIZE], int color)
{
    for (int i = 0; i < BLOCK_SIZE; ++i) {
        for (int j = 0; j < BLOCK_SIZE; ++j) {
            dst[i][j].fill = src[i][j];
            if (dst[i][j].fill > 0) {
                dst[i][j].color = color;
            } else {
                dst[i][j].color = 0;
            }
        } 
    }
}

void set_rotate_block(int block[][BLOCK_SIZE])
{
    int tmp = block[0][0];
    block[0][0] = block[3][0];
    block[3][0] = block[3][3];
    block[3][3] = block[0][3];
    block[0][3] = tmp;

    tmp = block[1][0];
    block[1][0] = block[3][1];
    block[3][1] = block[2][3];
    block[2][3] = block[0][2];
    block[0][2] = tmp;

    tmp = block[2][0];
    block[2][0] = block[3][2];
    block[3][2] = block[1][3];
    block[1][3] = block[0][1];
    block[0][1] = tmp;

    // inside
    tmp = block[1][1];
    block[1][1] = block[2][1];
    block[2][1] = block[2][2];
    block[2][2] = block[1][2];
    block[1][2] = tmp;
}

void Appear_block(void)
{
    srand((unsigned int)generate_rand());
    g_cur_block.x = c_start_x;
    g_cur_block.y = c_start_y;
    g_cur_block.type = rand() % BLOCK_TYPE;
    g_cur_block.direction = rand() % BLOCK_DIRECTION;

    int move_up = 0;
    int type = g_cur_block.type;
    int direction = g_cur_block.direction;
    for (int i = 0; i < BLOCK_SIZE; ++i) {
        for (int j = 0; j < BLOCK_SIZE; ++j) {
            if (g_block[type][direction][i][j].fill > 0) {
                goto out_of_loop;
            } 
        }
        ++move_up;
    }
out_of_loop:
    g_cur_block.y += move_up;
}

BOOL Move_block(enum_key key)
{
    int t = g_cur_block.type;
    int d = g_cur_block.direction;
    
    // temporary variables
    int x;  // co-ordinate x, row
    int y;  // co-ordinate y, col
    int tmp;
    switch (key)
    {
    case KEY_NOTHING:
        break;

    case KEY_LEFT:
        // move block left
        for (int i = 0; i < BLOCK_SIZE; ++i) {
            x = g_cur_block.x + i - 1;
            for (int j = 0; j < BLOCK_SIZE; ++j) {
                y = g_cur_block.y + j;
                if (g_block[t][d][j][i].fill > 0) {
                    if (g_map[y][x].fill > 0) {
                        return FALSE;
                    }
                }
            }
        }
        --g_cur_block.x;
        break;
    
    case KEY_UP:
        // rotate block
        tmp = d + 1;
        tmp = tmp % 4;
        for (int i = 0; i < BLOCK_SIZE; ++i) {
            x = g_cur_block.x + i;
            for (int j = 0; j < BLOCK_SIZE; ++j) {
                y = g_cur_block.y + j;
                if (g_block[t][tmp][j][i].fill > 0) {
                    if (g_map[y][x].fill > 0) {
                        return FALSE;
                    }
                }
            }
        }
        g_cur_block.direction = tmp;
        break;
    
    case KEY_RIGHT:
        // move block right
        for (int i = 0; i < BLOCK_SIZE; ++i) {
            x = g_cur_block.x + i + 1;
            for (int j = 0; j < BLOCK_SIZE; ++j) {
                y = g_cur_block.y + j;
                if (g_block[t][d][j][i].fill > 0) {
                    if (g_map[y][x].fill > 0) {
                        return FALSE;
                    }
                }
            }
        }
        ++g_cur_block.x;
        break;
    
    case KEY_DOWN:
        for (int i = 0; i < BLOCK_SIZE; ++i) {
            x = g_cur_block.x + i;
            for (int j = 0; j < BLOCK_SIZE; ++j) {
                y = g_cur_block.y + j + 1;
                if (g_block[t][d][j][i].fill > 0) {
                    if (g_map[y][x].fill > 0) {
                        decide_block();
                        remove_lines();
                        Appear_block();
                        if (is_end()) {
                            g_game_over = TRUE;
                        }
                        return FALSE;
                    }
                }
            }
        }
        ++g_cur_block.y;
        break;
    case KEY_SPACE:
        while(Move_block(KEY_DOWN));
        break;
    default:
        return FALSE;
    }
    return TRUE;
}


void decide_block(void)
{
    int x = g_cur_block.x;
    int y = g_cur_block.y;
    int t = g_cur_block.type;
    int d = g_cur_block.direction;

    for (int i = 0; i < BLOCK_SIZE; ++i) {
        x = g_cur_block.x + i;
        for (int j = 0; j < BLOCK_SIZE; ++j) {
            y = g_cur_block.y + j;
            if (g_block[t][d][j][i].fill) {
                g_map[y][x].fill = g_block[t][d][j][i].fill;
                g_map[y][x].color = g_block[t][d][j][i].color;
            }
        }
    }
}

BOOL is_end(void)
{
    int x = g_cur_block.x;
    int y = g_cur_block.y;
    int t = g_cur_block.type;
    int d = g_cur_block.direction;

    for (int i = 0; i < BLOCK_SIZE; ++i) {
        x = g_cur_block.x + i;
        for (int j = 0; j < BLOCK_SIZE; ++j) {
            y = g_cur_block.y + j;
            if (g_map[y][x].fill) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

void remove_lines(void)
{
    int lines = 0;
    BOOL check;
    for (int i = FRAME_HEIGHT - 1; i > 0; --i) {
        check = TRUE;
        for (int j = 1; j < FRAME_WIDTH+2; ++j) {
            if (!g_map[i][j].fill) {
                check = FALSE;
                break;
            }
        }

        if (check) {
            for (int j = 1; j < FRAME_WIDTH + 1; ++j) {
                g_map[i][j].fill = 0;
                g_map[i][j].color = BLOCK_COLOR_EMPTY;
            }
            ++lines;
        } else {
            if (lines > 0) {
                for (int j = 1; j < FRAME_WIDTH + 1; ++j) {
                    g_map[i + lines][j].fill = g_map[i][j].fill;
                    g_map[i + lines][j].color = g_map[i][j].color;
                    g_map[i][j].fill = 0;
                    g_map[i][j].color = BLOCK_COLOR_EMPTY;
                }
            }
        }

    }
}
