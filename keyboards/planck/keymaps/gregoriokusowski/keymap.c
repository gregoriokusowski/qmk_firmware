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
#include "muse.h"

enum planck_layers {
  _MIDI = _KEYMAP_LAYER,
  _SYNTH,
  _DRUMS
};

enum planck_keycodes {
  SY_OCTD = SAFE_RANGE,
  SY_OCTU,
  SY_MUSE,
  SY_SLOW,
  SY_FAST,
  DR_BEEP
};

#define MIDI    TO(_MIDI)
#define SYNTH   TO(_SYNTH)
#define DRUMS   TO(_DRUMS)
#define BASE    TO(_QWERTY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Typing layers: see users/gregoriokusowski/gregoriokusowski.h
[_QWERTY] = LAYOUT_planck_grid_wrapper(QWERTY_R1, QWERTY_R2, QWERTY_R3, QWERTY_R4),
[_LOWER]  = LAYOUT_planck_grid_wrapper(LOWER_R1, LOWER_R2, LOWER_R3, LOWER_R4),
[_RAISE]  = LAYOUT_planck_grid_wrapper(RAISE_R1, RAISE_R2, RAISE_R3, RAISE_R4),
[_MOUSE]  = LAYOUT_planck_grid_wrapper(MOUSE_R1, MOUSE_R2, MOUSE_R3, MOUSE_R4),
[_NUMBERS] = LAYOUT_planck_grid_wrapper(NUMBERS_R1, NUMBERS_R2, NUMBERS_R3, NUMBERS_R4),


/* MIDI (USB MIDI out, one octave per row, chromatic)
 * ,-----------------------------------------------------------------------------------.
 * |  C2  |  C#2 |  D2  |  D#2 |  E2  |  F2  |  F#2 |  G2  |  G#2 |  A2  |  A#2 |  B2  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  C1  |  C#1 |  D1  |  D#1 |  E1  |  F1  |  F#1 |  G1  |  G#1 |  A1  |  A#1 |  B1  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  C   |  C#  |  D   |  D#  |  E   |  F   |  F#  |  G   |  G#  |  A   |  A#  |  B   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Base | Oct- | Oct+ |Trns- |Trns+ |   Sustain   | Vel- | Vel+ | Chn- | Chn+ |AllOff|
 * `-----------------------------------------------------------------------------------'
 */
[_MIDI] = LAYOUT_planck_grid(
    MI_C2,   MI_Cs2,  MI_D2,   MI_Ds2,  MI_E2,   MI_F2,   MI_Fs2,  MI_G2,   MI_Gs2,  MI_A2,   MI_As2,  MI_B2,
    MI_C1,   MI_Cs1,  MI_D1,   MI_Ds1,  MI_E1,   MI_F1,   MI_Fs1,  MI_G1,   MI_Gs1,  MI_A1,   MI_As1,  MI_B1,
    MI_C,    MI_Cs,   MI_D,    MI_Ds,   MI_E,    MI_F,    MI_Fs,   MI_G,    MI_Gs,   MI_A,    MI_As,   MI_B,
    BASE,    MI_OCTD, MI_OCTU, MI_TRSD, MI_TRSU, MI_SUST, MI_SUST, MI_VELD, MI_VELU, MI_CHND, MI_CHNU, MI_AOFF
),

/* Synth (piezo speaker; same note grid as MIDI, nothing is sent to the host)
 * ,-----------------------------------------------------------------------------------.
 * |  C6  |  C#6 |  D6  |  D#6 |  E6  |  F6  |  F#6 |  G6  |  G#6 |  A6  |  A#6 |  B6  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  C5  |  C#5 |  D5  |  D#5 |  E5  |  F5  |  F#5 |  G5  |  G#5 |  A5  |  A#5 |  B5  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  C4  |  C#4 |  D4  |  D#4 |  E4  |  F4  |  F#4 |  G4  |  G#4 |  A4  |  A#4 |  B4  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Base | Oct- | Oct+ |Voice-|Voice+|    Muse     | Slow | Fast | Mute |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYNTH] = LAYOUT_planck_grid(
    MI_C2,   MI_Cs2,  MI_D2,   MI_Ds2,  MI_E2,   MI_F2,   MI_Fs2,  MI_G2,   MI_Gs2,  MI_A2,   MI_As2,  MI_B2,
    MI_C1,   MI_Cs1,  MI_D1,   MI_Ds1,  MI_E1,   MI_F1,   MI_Fs1,  MI_G1,   MI_Gs1,  MI_A1,   MI_As1,  MI_B1,
    MI_C,    MI_Cs,   MI_D,    MI_Ds,   MI_E,    MI_F,    MI_Fs,   MI_G,    MI_Gs,   MI_A,    MI_As,   MI_B,
    BASE,    SY_OCTD, SY_OCTU, AU_PREV, AU_NEXT, SY_MUSE, SY_MUSE, SY_SLOW, SY_FAST, AU_TOGG, XXXXXXX, XXXXXXX
),

/* Drums (step sequencer; sends General MIDI drum notes, Beep also plays steps on the speaker)
 * Pick a track on the right, then toggle its steps on the left. Steps go left to right, top row first.
 * ,-----------------------------------------------------------------------------------.
 * |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   | Kick |Snare |ClHat |OpHat |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  9   |  10  |  11  |  12  |  13  |  14  |  15  |  16  | Clap | Rim  | Tom  |Crash |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |AllOn |Clear |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Base |Tempo-|Tempo+| Res- | Res+ |  Play/Stop  | Beep |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_DRUMS] = LAYOUT_planck_grid(
    SQ_S(0), SQ_S(1), SQ_S(2),  SQ_S(3),  SQ_S(4),  SQ_S(5),  SQ_S(6),  SQ_S(7),  SQ_T(0), SQ_T(1), SQ_T(2), SQ_T(3),
    SQ_S(8), SQ_S(9), SQ_S(10), SQ_S(11), SQ_S(12), SQ_S(13), SQ_S(14), SQ_S(15), SQ_T(4), SQ_T(5), SQ_T(6), SQ_T(7),
    SQ_SALL, SQ_SCLR, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    BASE,    SQ_TMPD, SQ_TMPU,  SQ_RESD,  SQ_RESU,  SQ_TOGG,  SQ_TOGG,  DR_BEEP,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Boot |Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |SYNTH |Aud on|Audoff|AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|      |      |DRUMS |      | MIDI |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, QK_BOOT, DB_TOGG, UG_TOGG, UG_NEXT, UG_HUEU, UG_HUED, UG_SATU, UG_SATD, UG_VALU, UG_VALD, KC_DEL ,
    _______, _______, SYNTH,   AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______, _______, _______, _______,
    _______, AU_PREV, AU_NEXT, _______, _______, DRUMS,   _______, MIDI,    _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

float midi_song[][2]  = SONG(CHROMATIC_SOUND);
float synth_song[][2] = SONG(MAJOR_SOUND);
float drums_song[][2] = SONG(GUITAR_SOUND);
float base_song[][2]  = SONG(MUSIC_OFF_SOUND);

// Synth: MI_C on the bottom note row plays this MIDI note number (60 = C4)
uint8_t synth_base_note = 60;

bool     muse_mode      = false;
uint8_t  last_muse_note = 0;
uint16_t muse_counter   = 0;
uint16_t muse_tempo     = 50;

// Drums: track order matches SQ_T(0..7); notes are General MIDI drums at the default MIDI octave
const uint16_t drum_notes[SEQUENCER_TRACKS] = {
  MI_C1,  // 36 Kick
  MI_D1,  // 38 Snare
  MI_Fs1, // 42 Closed hat
  MI_As1, // 46 Open hat
  MI_Ds1, // 39 Clap
  MI_Cs1, // 37 Rim
  MI_F1,  // 41 Low tom
  MI_Cs2  // 49 Crash
};
// Piezo pitch per track, used when Beep is on
const float drum_beeps[SEQUENCER_TRACKS] = { 130.8f, 880.0f, 3520.0f, 2637.0f, 1174.7f, 1568.0f, 329.6f, 4186.0f };

bool     drum_beep      = false;
uint8_t  last_drum_step = UINT8_MAX;
float    drum_beep_freq = 0;
uint16_t drum_beep_timer;

void keyboard_post_init_user(void) {
  sequencer_set_track_notes(drum_notes);
  sequencer_set_tempo(120);
  sequencer_set_resolution(SQ_RES_16);
  sequencer_activate_track(0);
}

layer_state_t layer_state_set_keymap(layer_state_t state) {
  if (layer_state_cmp(state, _MIDI) && !layer_state_is(_MIDI)) {
    PLAY_SONG(midi_song);
  }
  if (layer_state_cmp(state, _SYNTH) && !layer_state_is(_SYNTH)) {
    PLAY_SONG(synth_song);
  }
  if (layer_state_cmp(state, _DRUMS) && !layer_state_is(_DRUMS)) {
    PLAY_SONG(drums_song);
  }
  if (!layer_state_cmp(state, _SYNTH) && layer_state_is(_SYNTH)) {
    muse_mode = false;
    stop_all_notes();
  }
  if ((layer_state_is(_MIDI) || layer_state_is(_SYNTH) || layer_state_is(_DRUMS)) && !layer_state_cmp(state, _MIDI) && !layer_state_cmp(state, _SYNTH) && !layer_state_cmp(state, _DRUMS)) {
    PLAY_SONG(base_song);
  }
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (keycode == DR_BEEP) {
    if (record->event.pressed) drum_beep = !drum_beep;
    return false;
  }

  if (!layer_state_is(_SYNTH)) {
    return true;
  }

  // Synth notes reuse the MIDI note keycodes, but play on the speaker instead of USB MIDI
  if (keycode >= QK_MIDI_NOTE_C_0 && keycode <= QK_MIDI_NOTE_B_5) {
    float freq = compute_freq_for_midi_note(synth_base_note + (keycode - QK_MIDI_NOTE_C_0));
    if (record->event.pressed) {
      play_note(freq, 0xF);
    } else {
      stop_note(freq);
    }
    return false;
  }

  if (!record->event.pressed) {
    return true;
  }
  switch (keycode) {
    case SY_OCTD:
      if (synth_base_note >= 24) synth_base_note -= 12;
      stop_all_notes();
      return false;
    case SY_OCTU:
      if (synth_base_note <= 84) synth_base_note += 12;
      stop_all_notes();
      return false;
    case SY_MUSE:
      muse_mode = !muse_mode;
      return false;
    case SY_SLOW:
      muse_tempo += 5;
      return false;
    case SY_FAST:
      if (muse_tempo > 5) muse_tempo -= 5;
      return false;
  }
  return true;
}

// Muse: generative melody on the speaker, built on the current synth octave
void matrix_scan_user(void) {
  if (muse_mode) {
    if (muse_counter == 0) {
      uint8_t muse_note = synth_base_note + SCALE[muse_clock_pulse()];
      if (muse_note != last_muse_note) {
        stop_note(compute_freq_for_midi_note(last_muse_note));
        play_note(compute_freq_for_midi_note(muse_note), 0xF);
        last_muse_note = muse_note;
      }
    }
    muse_counter = (muse_counter + 1) % muse_tempo;
  } else if (muse_counter) {
    stop_all_notes();
    muse_counter = 0;
  }

  // Drums beep: on each new step, play the first enabled track's pitch for a short click
  if (drum_beep_freq && timer_elapsed(drum_beep_timer) > 30) {
    stop_note(drum_beep_freq);
    drum_beep_freq = 0;
  }
  uint8_t step = sequencer_get_current_step();
  if (drum_beep && is_sequencer_on() && step != last_drum_step) {
    for (uint8_t track = 0; track < SEQUENCER_TRACKS; track++) {
      if (is_sequencer_step_on_for_track(step, track)) {
        if (drum_beep_freq) stop_note(drum_beep_freq);
        drum_beep_freq  = drum_beeps[track];
        drum_beep_timer = timer_read();
        play_note(drum_beep_freq, 0xF);
        break;
      }
    }
  }
  // Forget the step while stopped, so the first step after Play also beeps
  last_drum_step = is_sequencer_on() ? step : UINT8_MAX;
}
