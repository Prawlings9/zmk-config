#pragma once
#include <lvgl.h>

struct caps_status_widget {
    lv_obj_t *label;
};

int  caps_status_widget_init(struct caps_status_widget *widget, lv_obj_t *parent);
void caps_status_widget_update(struct caps_status_widget *widget, bool caps_on);