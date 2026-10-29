# gregoriokusowski — Planck rev6

Four modes on one board:

| Mode   | How to enter          | How to leave | What it does                          |
|--------|-----------------------|--------------|---------------------------------------|
| Typing | default               | —            | QWERTY + Lower/Raise/Adjust/Mouse/Num |
| MIDI   | Lower + Raise + `M`   | bottom-left  | USB MIDI notes, 3 chromatic octaves   |
| Synth  | Lower + Raise + `S`   | bottom-left  | Plays notes on the piezo speaker      |
| Drums  | Lower + Raise + `B`   | bottom-left  | 8-track, 16-step drum sequencer       |

Typing layers and tap-hold settings are shared with the Lumberjack: see `users/gregoriokusowski/readme.md`.

MIDI and Synth use the same note grid: one octave per row, column = pitch class.

Drums:

* Sends General MIDI drum notes (kick 36, snare 38, hats 42/46, ...) on channel 1
* Tap a track key (right side) to edit it, then tap steps 1–16 (left side). Tap the track again to deselect it
* Play/Stop on the spacebar. The pattern keeps playing when you switch to another mode
* `Beep` also plays each step on the piezo, so it works with no computer
* MIDI mode Oct± / Trns± also shift the drum notes; reset them to hit the right drum sounds

Build: `qmk compile -kb planck/rev6 -km gregoriokusowski`
