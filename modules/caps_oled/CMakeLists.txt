# Build a Zephyr library from this module
zephyr_library()

# Headers for this module live in src/ (where caps_status_widget.h is)
zephyr_library_include_directories(src)

# Source files to compile
zephyr_library_sources(
  src/caps_status_widget.c
  src/status_hook.c
)

