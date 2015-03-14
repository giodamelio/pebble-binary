#include <pebble.h>

#include "binary.h"
#include "time_layer.h"

// Create main window
Window *s_main_window;

// Create time layer
Layer *s_time_layer;

void main_window_load(Window *window) {
    // Create time layer
    s_time_layer = layer_create(GRect(0, 0, 144, 168));

    // Set our update proc
    layer_set_update_proc(s_time_layer, draw_time);

    // Add it as a child layer to the Window's root layer
    layer_add_child(window_get_root_layer(window), s_time_layer);
}

void main_window_unload(Window *window) {
    // Destroy our time_layer
    layer_destroy(s_time_layer);
}

void init() {
    // Create main Window element and assign to pointer
    s_main_window = window_create();

    // Set handlers to manage the elements inside the Window
    window_set_window_handlers(s_main_window, (WindowHandlers) {
        .load = main_window_load,
        .unload = main_window_unload
    });

    // Show the Window on the watch, with animated=true
    window_stack_push(s_main_window, true);

    // Update our watchface when the time changes
    tick_timer_service_subscribe(SECOND_UNIT, time_tick);
}

void deinit() {
    window_destroy(s_main_window);
}

int main(void) {
    init();
    app_event_loop();
    deinit();
}

