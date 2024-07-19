#include <iostream>
#include "raylib.h"

using namespace std;

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800

#define WINDOW_TITLE "Maya version 0.0.1"

int main(void)
{
#ifdef NDEBUG
    SetTraceLogLevel(LOG_ERROR);
#endif
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(120);


    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);


        const char* text = "Maya was here!";
        const Vector2 text_size = MeasureTextEx(GetFontDefault(), text, 20, 1);
        DrawText(text, SCREEN_WIDTH / 2 - text_size.x / 2, SCREEN_HEIGHT / 2 - text_size.y / 2, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}