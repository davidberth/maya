module;

#include "raylib.h"
#include <string>

export module window;

export int refresh_rate;
export int monitor_width;
export int monitor_height;

export int window_height;
export int window_width;

export int window_center_x;
export int window_center_y;

export int num_monitors;
export int current_monitor;

const int option_count = 4;
KeyboardKey option_keys[] = {KEY_F1, KEY_F2, KEY_F3, KEY_F4};
const int option_widths[] = { 800, 1024, 1600, 2400};
const int option_heights[] = { 600, 768, 1000, 1200};

export int current_size_option = 0;

export const char* window_title = "Maya version 0.1.0";


export std::string get_window_title()
{
	int width = option_widths[current_size_option];
	int height = option_heights[current_size_option];

	std::string title = std::string(window_title) + " Size: [" + std::to_string(current_size_option);
	title += std::string("] : (") + std::to_string(width) + "x" + std::to_string(height) + ")";
	return title;
}


export void init_window()
{

#ifdef NDEBUG
	SetTraceLogLevel(LOG_ERROR);
#endif
	window_width = option_widths[current_size_option];
	window_height = option_heights[current_size_option];

	InitWindow(window_width, window_height, get_window_title().c_str());
	window_center_x = window_width / 2;
	window_center_y = window_height / 2;

	monitor_width = GetMonitorWidth(0);
	monitor_height = GetMonitorHeight(0);

	refresh_rate = GetMonitorRefreshRate(0);
	SetTargetFPS(refresh_rate);

	current_monitor = 0;
	num_monitors = GetMonitorCount();
}

export void set_window_size(bool full_screen)
{
	if (full_screen)
	{
		window_width = monitor_width;
		window_height = monitor_height;
	}
	else
	{
		window_width = option_widths[current_size_option];
		window_height = option_heights[current_size_option];
	}

	window_center_x = window_width / 2;
	window_center_y = window_height / 2;

	SetWindowSize(window_width, window_height);
	SetWindowPosition((monitor_width - window_width) / 2, (monitor_height - window_height) / 2);
	SetWindowTitle(get_window_title().c_str());
}


export void toggle_monitor()
{
	current_monitor = (current_monitor + 1) % num_monitors;
	refresh_rate = GetMonitorRefreshRate(current_monitor);
	SetWindowMonitor(current_monitor);
	SetTargetFPS(refresh_rate);
	set_window_size(IsWindowFullscreen());
}

export void window_event()
{
	if (!IsWindowFullscreen())
	{
		for (int i = 0; i < option_count; i++)
		{
			if (IsKeyPressed(option_keys[i]))
			{
				current_size_option = i;
				set_window_size(false);
			}
		}
	}

	if (IsKeyPressed(KEY_F8))
	{
		ToggleFullscreen();
		if (IsWindowFullscreen())
		{
			set_window_size(true);
		}
		else
		{
			set_window_size(false);
		}
	}
	if (IsKeyPressed(KEY_F9))
	{
		if (IsWindowFullscreen())
		{
			toggle_monitor(); 
		}
	}
}


export bool inline window_should_close()
{
	return WindowShouldClose();
}

export void close_window()
{	
	CloseWindow();
}
