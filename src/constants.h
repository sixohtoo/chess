// Contains all the constants used
#ifndef GAME_CONSTANTS
#define GAME_CONSTANTS

#define SCREEN_HEIGHT 800
#define SCREEN_WIDTH 1200

#define CHESS_BOARD_HEIGHT 600
#define CHESS_BOARD_WIDTH 600
#define CHESS_BOARD_BORDER 100
#define CHESS_SQUARE_SIZE CHESS_BOARD_WIDTH / 8

#define TOTAL_SQUARES NUM_SQUARES_ROW *NUM_SQUARES_ROW
#define NUM_SQUARES_ROW 8

#define SAVE_GAME 0
#define MAX_SAVE_LENGTH 1024
#define DEFAULT_SAVE "default"
#define MAX_FILE_NAME 100
#define LOAD_NAME "pawn"

#define PIECE_SIZE 60
#define PIECE_OFFSET (CHESS_SQUARE_SIZE / 8)

#define TICK_DELAY 100

#define INVALID_COORD -1

#define SPRITE "imgs/pieces_sprite.png"

#endif