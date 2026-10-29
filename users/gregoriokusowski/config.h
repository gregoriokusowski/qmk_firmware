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

#pragma once

// Tap-hold: hold wins when another key is tapped inside the hold (fast Ctrl+C, Shift+A)
#define PERMISSIVE_HOLD
// Esc/Ctrl is Ctrl as soon as another key goes down, also in fast rolls (tmux Ctrl+A). See get_hold_on_other_key_press
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
// Same-hand rolls settle as tap (only for Z/Num, see get_chordal_hold)
#define CHORDAL_HOLD
// Z typed right after a letter is always a tap
#define FLOW_TAP_TERM 150

// Mouse: slow start for precision, then quick speed-up. Acc0 = slow, Acc2 = fast
#define MK_KINETIC_SPEED
