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

__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) {
  return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return layer_state_set_keymap(update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST));
}

// Esc/Ctrl and Enter/Shift are used for one-hand shortcuts (Ctrl+C, Shift+?), so they skip the opposite-hand rule
bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
  switch (tap_hold_keycode) {
    case CTL_ESC:
    case SFT_ENT:
      return true;
  }
  return get_chordal_hold_default(tap_hold_record, other_record);
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  return keycode == CTL_ESC;
}
