#include "raylib.h"
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

// Define board size, tile size and tile types
#define BOARD_SIZE 8
#define TILE_SIZE 42
#define TILE_TYPES 5

// Create an array of chars to represent the different tiles
const char tile_chars[TILE_TYPES]= {'#', '@', '$', '%', '&'};

// Create 2D array to hold the game board
char board[BOARD_SIZE][BOARD_SIZE];

// Funtion to randomly generate tiles on the board
char random_tile() {
    return tile_chars[rand() % TILE_TYPES];
}

// Loop through game board and fill it with random tiles
void init_board() {
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            board[y][x] = random_tile();
        }
    }
}

// Main function to initialize game
int main(void) {

    const int screen_width = 800;
    const int screen_height = 450;

    InitWindow(screen_width, screen_height, "Tile Matcher Game");

    SetTargetFPS(60);
    srand(time(NULL));

    init_board();

    while (!WindowShouldClose()) {

        // Game logic
        BeginDrawing();
        ClearBackground(BLACK);

        for (int y = 0; y < BOARD_SIZE; y++) {
            for (int x = 0; x < BOARD_SIZE; x++) {
                Rectangle rect = {
                    x * TILE_SIZE, 
                    y * TILE_SIZE,
                    TILE_SIZE,
                    TILE_SIZE
                };

                DrawRectangleLinesEx(rect, 1, DARKGRAY);

                // Draw the tile character in the center of the rectangle
                // Vector2 pos = {
                //     x * TILE_SIZE + 12,
                //     y * TILE_SIZE + 8
                // };

                DrawTextEx(
                    GetFontDefault(),
                    TextFormat("%c", board[y][x]),
                    (Vector2) { rect.x + 12, rect.y + 8 },
                    20, 1, WHITE
                );

                
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}