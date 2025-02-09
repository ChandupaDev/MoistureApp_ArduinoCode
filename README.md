# 📚 MoistureMonitorApp - Libraries & Arduino Code

![MoistureMonitorApp](https://img.shields.io/badge/Status-Active-brightgreen.svg)
![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)

## 📌 Overview
This repository contains the necessary libraries and Arduino code for the **MoistureMonitorApp**, an IoT-based system for monitoring soil moisture levels in real-time. The Arduino code reads data from moisture sensors and communicates with the React Native Expo app via Bluetooth.

## 🛠 Required Components
- ✅ **Arduino Board** (Uno, Mega, or ESP32)
- ✅ **Soil Moisture Sensor**
- ✅ **Bluetooth Module** (HC-05 / HC-06 / ESP32 Bluetooth)
- ✅ **Jumper Wires & Breadboard**

## 📂 Repository Structure
```
MoistureMonitor_Libraries_Arduino/
│── 📁 libraries/       # Required Arduino libraries
│── Soil_sensor_final_code.ino  # Moisture sensor Arduino sketches
│── README.md          # Documentation
```

## 📑 Required Libraries
Ensure you have the following libraries installed in the Arduino IDE:

| Library Name | Installation Command |
|-------------|--------------------|
| **SoftwareSerial** | Built-in (Arduino IDE) |
| **DHT Sensor Library** | Available in Arduino Library Manager |
| **Adafruit GFX Library** | Available in Arduino Library Manager |
| **Adafruit SSD1306** | Available in Arduino Library Manager |

To install manually, go to **Sketch → Include Library → Manage Libraries** in Arduino IDE and search for the required libraries.

## 🔌 Connecting the Hardware
| Component | Arduino Pin |
|-----------|------------|
| Soil Moisture Sensor | A0 |
| Bluetooth TX | D10 |
| Bluetooth RX | D11 |
| VCC (Power) | 5V |
| GND (Ground) | GND |

## 🚀 Uploading the Arduino Code
### 1️⃣ Clone the Repository
```sh
git clone git remote add origin git@github.com:ChandupaDev/MoistureApp_ArduinoCode.git
cd MoistureMonitor_Libraries_Arduino/arduino_code
```

### 2️⃣ Open the Sketch
- Open `MoistureMonitor.ino` in **Arduino IDE**.

### 3️⃣ Select Board & Port
- Go to **Tools → Board** and select your Arduino model.
- Go to **Tools → Port** and choose the correct COM port.

### 4️⃣ Upload the Code
Click on **Upload (▶️)** in Arduino IDE and wait for the process to complete.

## 🔗 Communication with React Native App
- The Arduino board transmits moisture sensor data over Bluetooth.
- The React Native app receives this data and displays it in a user-friendly UI.

## 🛠 Future Enhancements
- 📡 **Wi-Fi connectivity with ESP32**
- 🔔 **Alert system for low moisture levels**
- 📊 **More advanced sensor calibration**

## 🤝 Contributing
Contributions are welcome! Feel free to fork the repo and submit pull requests.

## 📜 License
This project is licensed under the **MIT License**.

## 📬 Contact
For questions or suggestions:
- 📧 Email: Chandupajayalath20@gmail.com


---
⭐ **Don't forget to star the repo if you find it useful!** ⭐
