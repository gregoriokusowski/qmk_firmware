#ifndef USERSPACE_CONFIG_H
#define USERSPACE_CONFIG_H

// #include QMK_KEYBOARD_H

#ifdef KEYBOARD_planck_rev5
  #undef MATRIX_ROW_PINS
  #define MATRIX_ROW_PINS { D1, D0, B2, B6 }
                         /*  2,  3, 16, 10 */
  #undef MATRIX_COL_PINS
  #define MATRIX_COL_PINS { D4, D3, D7, D2, B4, B5, F4, F5, F6, F7, B1, B3 }
                         /*  4,  5,  6,  7,  8,  9, A3, A2, A1, A0, 15, 14 */
  #undef QMK_LED
  #undef QMK_SPEAKER
#endif

#ifdef KEYBOARD_contra

#endif

#ifdef KEYBOARD_ut47

#endif

#endif // !USERSPACE_CONFIG_HH
