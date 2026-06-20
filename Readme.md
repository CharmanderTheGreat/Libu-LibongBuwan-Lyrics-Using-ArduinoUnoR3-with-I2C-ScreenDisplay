# Libu-LibongBuwan-Lyrics-Using-ArduinoUnoR3-with-I2C-ScreenDisplay

A timestamp-synced lyric display for the song "Libu-Libong Buwan", built on an Arduino Uno R3 and a 16x2 I2C LCD screen. Words appear on the screen in sync with playback time, scrolling across two rows as the song plays.

## How It Works

Each word in the lyrics is stored with its own timestamp (in milliseconds) and a flag marking whether it starts a new line. As time progresses, the matching word is pushed onto the LCD — filling the first row, then the second — creating a karaoke-style scrolling lyric effect.

## Hardware Used
<img width="964" height="857" alt="image" src="https://github.com/user-attachments/assets/797ccc91-04b1-4724-ae7a-8decbfe99e32" />

- **Arduino Uno R3** (economy/clone variant — requires the **CH340 driver** to be installed on your PC before it gets detected)
- **16x2 LCD screen with I2C backpack** (the I2C module had to be soldered onto the LCD manually)
- **4x female-to-male jumper wires** (female end connects to the LCD's I2C pins, male end connects to the Arduino's pin headers)

## Wiring

I2C only needs 4 connections:

| LCD (I2C) Pin | Arduino Uno Pin |
|----------------|------------------|
| GND            | GND              |
| VCC            | 5V               |
| SDA            | A4               |
| SCL            | A5               |

> Default I2C address used in code: `0x27`. If your screen doesn't light up or show text, run an I2C scanner sketch first to confirm the actual address (some modules use `0x3F` instead).

## Setup

1. Install the CH340 driver — only needed if you bought the economy/clone Uno R3, since it's cheaper but requires this extra step.
2. Solder the I2C backpack onto the LCD screen, if not pre-assembled. (Tip: buying a pre-soldered LCD module saves you this step.)
3. Wire the LCD to the Arduino following the table above.
4. Open `[sketch-filename].ino` in Arduino IDE.
5. Install the `LiquidCrystal_I2C` library via `Sketch > Include Library > Manage Libraries` → search "LiquidCrystal I2C" → install.
6. Select **Board: Arduino Uno** and the correct **COM Port**.
7. Upload the sketch.

## Usage

This is a **visual-only** display — there's no actual audio playback, just the lyrics scrolling in sync with timestamps. To start or replay the sequence from the beginning, reset the board using any of the following:

- **Reset button** — the red button on the Arduino board itself.
- **Re-upload the sketch** — re-uploading via Arduino IDE also restarts the board.
- **Plug and play** — unplug and replug the USB/power.

There's no separate "play" command in software — resetting the board is what triggers the sequence to play again.

## Limitations / Out of Scope

This project is intentionally simple — the following are **not** included:

- **No on/off switch** — the board only runs/resets via power plug or the reset button.
- **No sound/audio output** — visual-only; does not play or sync with actual audio.
- **No external "play" button** — playback restarts only by resetting the board.

## Software & Credits

| What | Link | Author / Source |
|------|------|------------------|
| Arduino IDE | [arduino.cc/en/software](https://www.arduino.cc/en/software) | Arduino |
| CH340 Driver | [wch-ic.com/downloads/CH341SER_EXE.html](https://www.wch-ic.com/downloads/CH341SER_EXE.html) | Nanjing Qinheng Microelectronics (WCH) — official manufacturer of the CH340/CH341 chip |
| LiquidCrystal_I2C Library | [github.com/johnrickman/LiquidCrystal_I2C](https://github.com/johnrickman/LiquidCrystal_I2C) | Author: Frank de Brabander · Maintainer: Marco Schwartz |

> Install LiquidCrystal_I2C directly through Arduino IDE's Library Manager instead of downloading it manually — search "LiquidCrystal I2C" and install the one by Frank de Brabander.
