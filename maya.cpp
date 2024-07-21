#include <iostream>
#include "raylib.h"

import window;
import renderer;

int main(void)
{

    init_window();


    while (!window_should_close())    // Detect window close button or ESC key
    {
        window_event();
        frame();

    }

    
    close_window();        
    
    return 0;
}
