cmake_minimum_required(VERSION 3.13.1)

if (CONFIG_ZMK_WIDGET_CAPS_STATUS)
  zephyr_library()
  zephyr_include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
  zephyr_library_sources(src/caps_status_widget.c src/status_hook.c)
endif()
