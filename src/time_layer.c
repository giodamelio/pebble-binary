#include "binary.h"
#include "time_layer.h"

// Get time
void time_tick(struct tm *tick_time, TimeUnits units_changed) {
    layer_mark_dirty(s_time_layer);
}

// Draw the time
void draw_time(Layer *my_layer, GContext* ctx) {
    int radius = (rand() % (30 - 5)) + 5;
    APP_LOG(APP_LOG_LEVEL_INFO, "Drawing circle of size %d", radius);
    graphics_context_set_stroke_color(ctx, GColorBlack);
    graphics_context_set_fill_color(ctx, GColorBlack);
    graphics_fill_circle(ctx, GPoint(72, 84), radius);
}

