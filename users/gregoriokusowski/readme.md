# gregoriokusowski userspace

Shared typing layers for:

* `planck/rev6:gregoriokusowski` (adds MIDI, Synth and Drums modes)
* `peej/lumberjack:gregoriokusowski` (adds a number row on top)

Layers: Qwerty, Lower, Raise, Mouse, Numbers as row macros in `gregoriokusowski.h`.
Each keymap defines its own Adjust layer (Lower + Raise), because it holds board-specific keys.

Typing customizations:

* `Esc` on tap / `Ctrl` on hold (home row, left)
* `Enter` on tap / `Shift` on hold (right)
* Hold `Z` for a numpad on the right hand (`4` under the index finger)
* Hold bottom-left for mouse keys (`hjkl` moves the cursor, row above scrolls)

Tap-hold tuning:

* Permissive Hold: tapping a key inside a hold uses the hold (fast `Ctrl+C`, `Shift+A`)
* Esc/Ctrl only: Ctrl as soon as another key goes down, also in fast rolls (tmux `Ctrl+A`)
* Chordal Hold, only on `Z/Num`: a same-hand roll like `zx` is always typed
* Flow Tap (150 ms): `Z` right after a letter is always typed
* Mouse uses kinetic speed: slow start for precision, then quick speed-up
