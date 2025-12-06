MULTI-LEVEL SECURITY ACCESS SYSTEM
📌 AIM

The primary objective of this project is to ensure high-level security for valuable devices by implementing a three-tier security system.
This system authenticates users through multiple verification methods, restricting unauthorized access and providing enhanced protection against security breaches.

The authentication stages are:

RFID Verification

Password Verification (Keypad)

Fingerprint Verification (R305)

Only authorized users who pass all three levels can access the protected device or system.

📦 BLOCK DIAGRAM

(Attach image here: block_diagram.png)

[RFID] → [Controller] → [LCD]  
[Keypad] → [Controller]  
[Fingerprint Module] → [Controller]  
[EEPROM] ↔ [Controller]  
[Motor Driver (L293D)] → [DC Motor / Door]

🧰 REQUIREMENTS
🔌 Hardware Requirements

LPC2148 Microcontroller

RFID Reader

RFID Cards

R305 Fingerprint Module

16x2 LCD

EEPROM (AT24C256)

4x4 Keypad

L293D Motor Driver

DC Motor

Switch

USB-to-UART Converter

💻 Software Requirements

Embedded C

KEIL µVision IDE

Flash Magic (Hex uploader)

🧪 PROJECT DEVELOPMENT STEPS
✅ 1. Create Project Structure

Create a new folder with your project name.

Copy all driver files into the folder:

lcd.c, lcd.h

delay.c, delay.h

uart.c, uart.h

keypad.c, keypad.h

i2c.c, i2c.h

🧩 2. Test Individual Modules
🔹 LCD Test

Display character, string, and integer constants.

🔹 Keypad Test

Display pressed keys on LCD.

🔹 EEPROM Test

Write N bytes to EEPROM.
Read the N bytes back and display on LCD.
Use BYTE WRITE / BYTE READ or PAGE WRITE / PAGE READ.

🔹 UART Test

Transmit/Receive strings via HyperTerminal.
UART interrupts must be used.

🆔 3. RFID MODULE TEST

Connect RFID reader D0 pin → USB-to-UART converter.
Test card number output in PC terminal.

📥 Example RFID Output

If card number is 12345678, RFID sends 10 bytes:

02 31 32 33 34 35 36 37 38 03

🧬 4. Fingerprint Module (R305) Test

Use software tools under LMS → REFERENCE DATA.
Connect R305 to USB-UART converter and test.
Download fingerprint code from LMS and test.

Refer to R305 datasheet for:

Command format

Acknowledge packets

🖥️ 5. Main Application Development

Create projectmain.c and include all driver files.

🛎️ External Interrupt 0 ISR Tasks

Display Menu on LCD:

1) Edit Password
2) Edit Fingerprint


Take input from Keypad.

🔑 A. Edit Password Function

Workflow:

Ask for User RFID card

If valid → ask for current password

If correct → enter new password

Confirm new password

If matched → save to EEPROM

Else → keep old password

🌀 B. Edit Fingerprint Function

Allows ENROLL and DELETE operations.

🔹 ENROLL Process

Detect finger → store image in ImageBuffer

Convert to character file → store in CharBuffer

Save template to flash library

🔹 SEARCH Process

Detect finger → store image

Generate character file

Search in fingerprint database

🔐 THREE-LEVEL SECURITY PROCESS
1️⃣ Level 1 — RFID Authentication

Wait for RFID card.

If card is valid → proceed to password.

Else → access denied.

2️⃣ Level 2 — Password Authentication

User enters password via keypad

Read saved password from EEPROM

Compare both strings

If correct → proceed to fingerprint

Else → deny access

3️⃣ Level 3 — Fingerprint Authentication

Call Fingerprint Search Process

If matched → user authenticated

Else → deny access

🚪 Final Action — Door Control

If all 3 levels pass:

Rotate DC motor clockwise → open door

Wait

Rotate anti-clockwise → close door

Else:

Display Failure message

Restart system

⚠️ IMPORTANT REAL-TIME CONDITIONS

If password is not entered within timeout → restart from Level 1

All test cases must be included

Handle invalid fingerprint / wrong key entries

🗂️ Folder Structure (Updated With Your Files)
/
├── drivers/
│   ├── Edit_pass.c
│   ├── Edit_pass.h
│   ├── I2C.c
│   ├── I2C.h
│   ├── I2C_eeprom.c
│   ├── I2C_eeprom.h
│   ├── I2C_eeprom_test.c
│   ├── Lcd.c
│   ├── Lcd.h
│   ├── Lcd_defines.h
│   ├── Motor_driver.c
│   ├── Motor_driver.h
│   ├── PinConnect_block.c
│   ├── Pinconnect_block.h
│   ├── R305.c
│   ├── R305.h
│   ├── UART_defines.h
│   ├── UART_int.c
│   ├── UART_int.h
│   ├── Uart_Rfid.c
│   ├── Uart_Rfid.h
│   ├── Uart_r305.c
│   ├── Uart_r305.h
│   ├── defines.h
│   ├── delay.c
│   ├── delay.h
│   ├── i2c_defines.h
│   ├── interupt_defines.h
│   ├── interupt_main.c
│   ├── interupt_main.h
│   ├── kpm.c
│   ├── kpm.h
│   ├── kpm_defines.h
│   ├── passwordLevel.c
│   ├── passwordLevel.h
│   ├── passwordLevelTest.c
│   ├── passwordTest.c
│   ├── rfidLevel.c
│   ├── rfidLevel.h
│   └── types.h
│
├── src/
│   └── ProjectMain.c
│
├── docs/
│   ├── block_diagram.png
│   ├── flowchart.png
│   └── project_report.pdf
│
└── README.md

🧾 OUTPUT EXPECTATION

When all processes work correctly:

Valid RFID →
Valid Password →
Valid Fingerprint →
Door Opens and Closes Automatically

✍️ AUTHOR

Surya Prakash Vadaparthi
