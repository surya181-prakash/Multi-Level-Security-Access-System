
---

## 🧰 REQUIREMENTS

### 🔌 Hardware Requirements
- LPC2148 Microcontroller  
- RFID Reader + RFID Cards  
- R305 Fingerprint Module  
- 16x2 LCD  
- AT24C256 EEPROM  
- 4x4 Keypad  
- L293D Motor Driver  
- DC Motor  
- Switch  
- USB-to-UART Converter  

### 💻 Software Requirements
- Embedded C  
- KEIL µVision IDE  
- Flash Magic  

---

## 🧪 PROJECT DEVELOPMENT STEPS

### ✅ 1. Project Structure Creation
Include all required drivers:
- lcd.c / lcd.h  
- uart.c / uart.h  
- delay.c / delay.h  
- keypad.c / keypad.h  
- i2c.c / i2c.h  

---

### 🧩 2. Test Individual Modules

#### LCD Test
Display characters, strings, integers.

#### Keypad Test
Show pressed key on LCD.

#### EEPROM Test
- Write N bytes  
- Read back and display  

#### UART Test
- TX/RX using interrupts  
- Verify using HyperTerminal  

---

### 🆔 3. RFID MODULE TEST

Connect RFID → USB UART → PC Terminal.

**Example Output**  
For card number 12345678:

