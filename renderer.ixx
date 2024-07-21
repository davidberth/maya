module;
#include "raylib.h"
import window;

export module renderer;

export void frame()
{
	BeginDrawing();
	ClearBackground(BLACK);
	int font_size = window_width / 50;
	const char* message = "Congrats! You created your first window!";
	int text_width = MeasureText(message, font_size);
	DrawText(message, window_center_x - text_width / 2, window_center_y - font_size / 2, font_size, LIGHTGRAY);
	EndDrawing();
}


