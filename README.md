# Pico 7-Segment 12hr Clock

12-hour clock using Raspberry Pi Pico and TM1637 4-digit display.
Displays time in HH:MM format with blinking colon every second.

## Hardware Required
- Raspberry Pi Pico
- TM1637 4-digit 7-segment display
- 3x AA battery holder or USB power bank
- Jumper wires

## Wiring

| TM1637 | Pico Pin | GPIO |
|--------|----------|------|
| CLK    | Pin 1    | GP0  |
| DIO    | Pin 2    | GP1  |
| VCC    | Pin 36   | 3V3  |
| GND    | Pin 38   | GND  |

## Prerequisites

- Raspberry Pi Pico SDK v2.2.0
- MinGW64 (for Windows)
- CMake
- Ninja build system

## Build Instructions (Windows)

### Step 1 - Clone repo
```
git clone https://github.com/sudhirvacharya/pico_7seg_clock_v2.git
cd pico_7seg_clock_v2
```

### Step 2 - Clone TM1637 library
```
git clone https://github.com/wahlencraft/TM1637-pico.git
```

### Step 3 - Open Pico Developer Command Prompt
```
Start Menu → Pico Developer Command Prompt
```

### Step 4 - Set PATH
```
set PATH=C:\mingw64\bin;C:\Program Files\Raspberry Pi\Pico SDK v1.5.1\gcc-arm-none-eabi\bin;%PATH%
```

### Step 5 - Build
```
mkdir build
cd build
cmake .. -G "Ninja" -DPICO_SDK_PATH=C:/Users/<your_name>/.pico-sdk/sdk/2.2.0
ninja
```

### Step 6 - Flash to Pico
```
1. Hold BOOTSEL button on Pico
2. Plug USB cable
3. Pico appears as RPI-RP2 drive
4. Copy build/pico_7seg_clock_v2.uf2 to that drive
```

## Simulation (Wokwi)

Open project in VS Code with Wokwi extension installed.
Press `Ctrl+Shift+P` → `Wokwi: Start Simulator`

## Power Options

| Option | Details |
|--------|---------|
| USB | Connect micro USB to PC or power bank |
| Battery | 3x AA (4.5V) → VSYS Pin 39 |
| LiPo | 3.7V → VSYS Pin 39 |

## License
MIT
