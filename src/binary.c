#include <pebble.h>

// Create main window
static Window *s_main_window;

// Create time layer
static Layer *s_time_layer;

// Draw the time in binary
static void update_time() {
    // Get a tm structure
    time_t temp = time(NULL); 
    struct tm *tick_time = localtime(&temp);


}

// Get time
static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
    update_time();
}

// Draw the time
void draw_time_layer(Layer *my_layer, GContext* ctx) {
    graphics_context_set_stroke_color(ctx, GColorBlack);
    graphics_context_set_fill_color(ctx, GColorBlack);
    graphics_fill_circle(ctx, GPoint(10, 10), 10);
}

// Main window load
static void main_window_load(Window *window) {
    // Create time layer
    s_time_layer = layer_create(GRect(0, 0, 144, 168));

    // Set our update proc
    layer_set_update_proc(s_time_layer, draw_time_layer);

    // Add it as a child layer to the Window's root layer
    layer_add_child(window_get_root_layer(window), s_time_layer);
}

// Main window unload
static void main_window_unload(Window *window) {
    // Destroy our time_layer
    layer_destroy(s_time_layer);
}

static void init() {
    // Create main Window element and assign to pointer
    s_main_window = window_create();

    // Set handlers to manage the elements inside the Window
    window_set_window_handlers(s_main_window, (WindowHandlers) {
        .load = main_window_load,
        .unload = main_window_unload
    });

    // Show the Window on the watch, with animated=true
    window_stack_push(s_main_window, true);

    // Show the time
    update_time();

    // Register with TickTimerService
    tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
}

static void deinit() {
    // Destroy Window
    window_destroy(s_main_window);
}

int main(void) {
    init();
    app_event_loop();
    deinit();
}

