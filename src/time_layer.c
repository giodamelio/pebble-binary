#include "binary.h"
#include "time_layer.h"

// Get the n'th bit from an int
int get_bit(int decimal, int N){

    // Shifting the 1 for N-1 bits
    int constant = 1 << (N-1);

    // if the bit is set, return 1
    if( decimal & constant ){
        return 1;
    }

    // If the bit is not set, return 0
    return 0;
}

// Column width
#define col_width 18
#define base_height 104
#define radius 7
#define padding 2
#define height_o ((radius * 2) + (padding * 2))

// Organize dots in columns. Left to right, bottom to top
#define col0_wo 1 * col_width + (col_width / 2)
int col0[2][2] = {
    {col0_wo, base_height - (0 * height_o)},
    {col0_wo, base_height - (1 * height_o)}
};

#define col1_wo 2 * col_width + (col_width / 2)
int col1[4][2] = {
    {col1_wo, base_height - (0 * height_o)},
    {col1_wo, base_height - (1 * height_o)},
    {col1_wo, base_height - (2 * height_o)},
    {col1_wo, base_height - (3 * height_o)}
};

#define col2_wo 3 * col_width + (col_width / 2)
int col2[3][2] = {
    {col2_wo, base_height - (0 * height_o)},
    {col2_wo, base_height - (1 * height_o)},
    {col2_wo, base_height - (2 * height_o)}
};

#define col3_wo 4 * col_width + (col_width / 2)
int col3[4][2] = {
    {col3_wo, base_height - (0 * height_o)},
    {col3_wo, base_height - (1 * height_o)},
    {col3_wo, base_height - (2 * height_o)},
    {col3_wo, base_height - (3 * height_o)}
};

#define col4_wo 5 * col_width + (col_width / 2)
int col4[3][2] = {
    {col4_wo, base_height - (0 * height_o)},
    {col4_wo, base_height - (1 * height_o)},
    {col4_wo, base_height - (2 * height_o)}
};

#define col5_wo 6 * col_width + (col_width / 2)
int col5[4][2] = {
    {col5_wo, base_height - (0 * height_o)},
    {col5_wo, base_height - (1 * height_o)},
    {col5_wo, base_height - (2 * height_o)},
    {col5_wo, base_height - (3 * height_o)}
};

// Draw the time
void draw_time(Layer *my_layer, GContext* ctx) {
    // Get the time
    time_t temp = time(NULL); 
    struct tm *tick_time = localtime(&temp);

    // Put the time into an array of chars
    char buffer[7];
    strftime(buffer, 7, "%I%M%S", tick_time);

    // Set the colors
    graphics_context_set_stroke_color(ctx, GColorBlack);
    graphics_context_set_fill_color(ctx, GColorBlack);

    // Draw column 0
    int i;
    for (i = 0; i < 2; i++) {
        int filled = get_bit(buffer[0] - '0', i + 1);
        if (filled) {
            graphics_fill_circle(ctx, GPoint(col0[i][0], col0[i][1]), radius);
        } else {
            graphics_draw_circle(ctx, GPoint(col0[i][0], col0[i][1]), radius);
        }
    }

    // Draw column 1
    for (i = 0; i < 4; i++) {
        int filled = get_bit(buffer[1] - '0', i + 1);
        if (filled) {
            graphics_fill_circle(ctx, GPoint(col1[i][0], col1[i][1]), radius);
        } else {
            graphics_draw_circle(ctx, GPoint(col1[i][0], col1[i][1]), radius);
        }
    }

    // Draw column 2
    for (i = 0; i < 3; i++) {
        int filled = get_bit(buffer[2] - '0', i + 1);
        if (filled) {
            graphics_fill_circle(ctx, GPoint(col2[i][0], col2[i][1]), radius);
        } else {
            graphics_draw_circle(ctx, GPoint(col2[i][0], col2[i][1]), radius);
        }
    }

    // Draw column 3
    for (i = 0; i < 4; i++) {
        int filled = get_bit(buffer[3] - '0', i + 1);
        if (filled) {
            graphics_fill_circle(ctx, GPoint(col3[i][0], col3[i][1]), radius);
        } else {
            graphics_draw_circle(ctx, GPoint(col3[i][0], col3[i][1]), radius);
        }
    }

    // Draw column 4
    for (i = 0; i < 3; i++) {
        int filled = get_bit(buffer[4] - '0', i + 1);
        if (filled) {
            graphics_fill_circle(ctx, GPoint(col4[i][0], col4[i][1]), radius);
        } else {
            graphics_draw_circle(ctx, GPoint(col4[i][0], col4[i][1]), radius);
        }
    }

    // Draw column 5
    for (i = 0; i < 4; i++) {
        int filled = get_bit(buffer[5] - '0', i + 1);
        if (filled) {
            graphics_fill_circle(ctx, GPoint(col5[i][0], col5[i][1]), radius);
        } else {
            graphics_draw_circle(ctx, GPoint(col5[i][0], col5[i][1]), radius);
        }
    }
}

// Get time
void time_tick(struct tm *tick_time, TimeUnits units_changed) {
    layer_mark_dirty(s_time_layer);
}

