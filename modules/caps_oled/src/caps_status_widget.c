#include <zephyr/kernel.h>
#include <lvgl.h>

/* ZMK headers */
#include <zmk/event_manager.h>
#include <zmk/events/indicator_state_changed.h> /* event for caps/num/scroll indicators */
#include <zmk/indicator.h>                      /* query current indicator state */

#include "caps_status_widget.h"

static struct caps_status_widget *global_widget;

int caps_status_widget_init(struct caps_status_widget *widget, lv_obj_t *parent) {
    widget->label = lv_label_create(parent);
    lv_label_set_text(widget->label, "");      /* hidden by default */
    lv_obj_add_flag(widget->label, LV_OBJ_FLAG_HIDDEN);
    global_widget = widget;

    /* Initial state from indicators */
    bool caps = zmk_indicator_is_on(ZMK_INDICATOR_CAPSLOCK);
    if (caps) {
        lv_label_set_text(widget->label, "CAPS");
        lv_obj_clear_flag(widget->label, LV_OBJ_FLAG_HIDDEN);
    }
    return 0;
}

/* Handle indicator state changes (Caps/Num/Scroll). */
static int caps_status_listener(const struct zmk_event_header *eh) {
    const struct zmk_indicator_state_changed *ev = cast_zmk_indicator_state_changed(eh);
    if (!global_widget) { return 0; }

    if (ev->indicator == ZMK_INDICATOR_CAPSLOCK) {
        if (ev->state) {
            lv_label_set_text(global_widget->label, "CAPS");
            lv_obj_clear_flag(global_widget->label, LV_OBJ_FLAG_HIDDEN);
        } else {
            lv_obj_add_flag(global_widget->label, LV_OBJ_FLAG_HIDDEN);
        }
    }
    return 0;
}

ZMK_LISTENER(caps_status, caps_status_listener)
ZMK_SUBSCRIPTION(caps_status, zmk_indicator_state_changed);

/* Allow screen code to call this directly if desired */
void caps_status_widget_update(struct caps_status_widget *widget, bool caps_on) {
    if (!widget || !widget->label) { return; }
    if (caps_on) {
        lv_label_set_text(widget->label, "CAPS");
        lv_obj_clear_flag(widget->label, LV_OBJ_FLAG_HIDDEN);
    } else {
        lv_obj_add_flag(widget->label, LV_OBJ_FLAG_HIDDEN);
    }
}
