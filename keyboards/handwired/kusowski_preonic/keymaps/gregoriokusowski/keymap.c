/* Copyright 2018-2026 Gregorio Kusowski @gregoriokusowski
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "gregoriokusowski.h"

// Typing layers: see users/gregoriokusowski/gregoriokusowski.h. 5x12 adds a number row on top.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY]  = LAYOUT_ortho_5x12_wrapper(NUMBER_ROW,      QWERTY_R1,       QWERTY_R2,       QWERTY_R3,       QWERTY_R4),
[_LOWER]   = LAYOUT_ortho_5x12_wrapper(TRANSPARENT_ROW, LOWER_R1,        LOWER_R2,        LOWER_R3,        LOWER_R4),
[_RAISE]   = LAYOUT_ortho_5x12_wrapper(TRANSPARENT_ROW, RAISE_R1,        RAISE_R2,        RAISE_R3,        RAISE_R4),
[_ADJUST]  = LAYOUT_ortho_5x12_wrapper(TRANSPARENT_ROW, ADJUST_BASIC_R1, ADJUST_BASIC_R2, ADJUST_BASIC_R3, ADJUST_BASIC_R4),
[_MOUSE]   = LAYOUT_ortho_5x12_wrapper(TRANSPARENT_ROW, MOUSE_R1,        MOUSE_R2,        MOUSE_R3,        MOUSE_R4),
[_NUMBERS] = LAYOUT_ortho_5x12_wrapper(TRANSPARENT_ROW, NUMBERS_R1,      NUMBERS_R2,      NUMBERS_R3,      NUMBERS_R4)

};
