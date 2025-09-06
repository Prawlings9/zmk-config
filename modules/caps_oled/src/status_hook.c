#include <zephyr/kernel.h>
#include <lvgl.h>
#include <zmk/display/status_screen.h>  /* returns the built-in status root */

#include "caps_status_widget.h"

static struct caps_status_widget caps_widget;

static int caps_status_screen_decorator(const struct device *unused)
{
    ARG_UNUSED(unused);

    lv_obj_t *root = zmk_display_status_screen();
    if (!root) { return 0; }

    caps_status_widget_init(&caps_widget, root);
    lv_obj_align(caps_widget.label, LV_ALIGN_TOP_RIGHT, -2, 0);
    return 0;
}

SYS_INIT(caps_status_screen_decorator, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);
