#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "config_common.h"

/* Planck PCB default pin-out */
#undef MATRIX_ROW_PINS
#define MATRIX_ROW_PINS { D1, D0, B2, B6 }
                       /*  2,  3,  16, 10 */
#undef MATRIX_COL_PINS
#define MATRIX_COL_PINS { D4, D3, D7, D2, B4, B5, F4, F5, F6, F7, B1, B3 }
                       /*  4,  5,  6,  7,  8,  9, A3, A2, A1, A0, 15, 14 */
#undef QMK_LED
#undef QMK_SPEAKER

#define USB_MAX_POWER_CONSUMPTION 50


#endif
