# Avalanche

## Enable Debug Mode

Modify `rules.mk`:

```C
CONSOLE_ENABLE = yes
```

Use `keyboard_post_init_user` in `keymap.c`:

```C
void keyboard_post_init_user(void) {
#ifdef CONSOLE_ENABLE
    debug_enable=true;
#endif
}
```

## Log Key Info

Include `print.h` in `keymap.c`:

```C
#ifdef CONSOLE_ENABLE
#include "print.h"
#endif
```

Print key info:

```C
#ifdef CONSOLE_ENABLE
    uprintf("KC: 0x%04X, MOD: 0x%04X, COL: %2u, ROW: %2u, PRESSED: %u, TIME: %5u, INT: %u, COUNT: %u\n", keycode, get_mods() & MOD_MASK_SHIFT, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
```