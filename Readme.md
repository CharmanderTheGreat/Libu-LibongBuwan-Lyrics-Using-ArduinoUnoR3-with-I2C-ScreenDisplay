# Libu-LibongBuwan-Lyrics-Using-ArduinoUnoR3-with-I2C-ScreenDisplay

A timestamp-synced lyric display for the song **"Libu-Libong Buwan"**, built on an Arduino Uno R3 and a 16x2 I2C LCD screen. Words appear on the screen in sync with playback time, scrolling across two rows as the song plays.

## How It Works

Each word in the lyrics is stored with its own timestamp (in milliseconds) and a flag marking whether it starts a new line. As time progresses, the matching word is pushed onto the LCD — filling the first row, then the second — creating a karaoke-style scrolling lyric effect.

## Hardware Used

- **Arduino Uno R3** (economy/clone variant — requires the **CH340 USB driver** to be installed on your PC before it gets detected)
- **16x2 LCD screen with I2C backpack** (the I2C module had to be soldered onto the LCD manually)
- **4x jumper wires** (for I2C connection)
- Breadboard *(optional, depende sa setup mo — [edit kung meron])*

## Wiring

I2C only needs 4 connections:

| LCD (I2C) Pin | Arduino Uno Pin |
|----------------|------------------|
| GND            | GND              |
| VCC            | 5V               |
| SDA            | A4               |
| SCL            | A5               |

> Default I2C address used in code: `0x27`. If your screen doesn't light up or show text, run an I2C scanner sketch first to confirm the actual address (some modules use `0x3F` instead).

## Software Requirements

- [Arduino IDE](https://www.arduino.cc/en/software) (2.x) — used for compiling and uploading
- **CH340 driver** — needed for the economy/clone Uno R3 to be recognized via USB
- **LiquidCrystal_I2C** library — install via Arduino IDE: `Sketch > Include Library > Manage Libraries` → search "LiquidCrystal I2C" → install

## Setup

1. Install the CH340 driver (if your PC doesn't already detect the board).
2. Solder the I2C backpack onto the LCD screen (if not pre-assembled).
3. Wire the LCD to the Arduino following the table above.
4. Open `[sketch-filename].ino` in Arduino IDE.
5. Install the `LiquidCrystal_I2C` library via Library Manager.
6. Select **Board: Arduino Uno** and the correct **COM Port**.
7. Upload the sketch.

## Usage

[Idagdag mo dito kung paano i-trigger/i-start yung playback — hal. paano siya naka-sync sa actual audio, may button ba, o auto-start pag naka-plug?]

## Notes

- Built using an **economy/clone Uno R3**, so driver installation (CH340) is required — official Uno boards don't need this extra step.
- I2C backpack was soldered manually onto the LCD.

## License

[Optional — MIT, or wala kung personal project lang]