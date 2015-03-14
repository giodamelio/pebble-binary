#ifndef BINARY_H_
#define BINARY_H_

#include <pebble.h>

int main(void);
void dinit();
void init();
void main_window_unload(Window *window);
void main_window_load(Window *window);

Layer *s_time_layer;

#endif

