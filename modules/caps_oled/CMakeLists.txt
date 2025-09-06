cmake_minimum_required(VERSION 3.13.1)

zephyr_library()

# If your headers live in src/, this is fine. If you add an include/ later, switch to that.
zephyr_include_directories(src)

zephyr_library_sources_ifdef(CONFIG_ZMK_WIDGET_CAPS_STATUS
  src/caps_status_widget.c
  src/status_hook.c
)


