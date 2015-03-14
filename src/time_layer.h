#ifndef TIME_LAYER_H_
#define TIME_LAYER_H_

#include <pebble.h>

void time_tick(struct tm *tick_time, TimeUnits units_changed);
void draw_time(Layer *layer, GContext* ctx);

#endif

