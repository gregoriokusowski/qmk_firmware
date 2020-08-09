#pragma once


// https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold
//#define TAPPING_FORCE_HOLD
//#define PERMISSIVE_HOLD
//#define IGNORE_MOD_TAP_INTERRUPT
//#define RETRO_TAPPING
//#define TAPPING_TERM 200

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
