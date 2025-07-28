# 🔌 STM-IoTHub – RTOS-Based Smart Home Automation Hub

STM-IoTHub is a FreeRTOS-based smart home automation system developed using the **STM32F446RE Nucleo** board. It integrates environmental sensing, cloud connectivity, and local display + energy monitoring using STM32 HAL and FreeRTOS.

> ✅ This project is resume-ready and GitHub-optimized.  
> 🛠️ Developed by: Abhinav Kalintha  
> 📅 Year: 2025

---

## 📌 Features

- 🌡️ **BME680 Sensor (I2C1 - PB6, PB7)**  
  Measures Temperature, Humidity, Pressure & Air Quality.

- 📺 **OLED Display 0.96" (I2C2 - PB10, PB3)**  
  Displays local environment and status information.

- 📶 **Wi-Fi Connectivity (ESP-12E via USART6 - PC6, PC7)**  
  Sends real-time data to the Blynk IoT cloud platform.

- ⚡ **Energy Monitoring (PZEM-004T via USART2 - PA2, PA3)**  
  Tracks energy usage of connected appliances.

- 💾 **SD Card Logging (SPI - PB13, PB14, PB15, PA5)**  
  Logs sensor data locally for later review.

- 🔁 **FreeRTOS-Based Multitasking**  
  Tasks include: Sensor Read, OLED Update, Wi-Fi Sync, SD Logging, Error Handling, etc.

- 🔄 **Modular STM32CubeIDE + HAL Structure**

---

## 📂 Project Structure

STM-IoTHub/
├── Core/
│ ├── Inc/
│ │ ├── main.h
│ │ └── TASKS/ # Custom FreeRTOS Task Headers
│ ├── Src/
│ │ ├── main.c
│ │ └── TASKS/ # FreeRTOS Task Implementations
├── Drivers/ # HAL Drivers
├── Middlewares/ # OLED, Blynk, PZEM, etc.
├── README.md # 📄 You're reading it!
└── .ioc # STM32CubeMX configuration

markdown
Copy
Edit

---

## ⚙️ Hardware Connections

| Peripheral     | Interface | Pins               |
|----------------|-----------|--------------------|
| BME680         | I2C1      | PB6 (SCL), PB7 (SDA)|
| OLED 0.96"     | I2C2      | PB10 (SCL), PB3 (SDA)|
| SD Card Module | SPI       | PB13 (SCK), PB14 (MISO), PB15 (MOSI), PA5 (CS)|
| ESP-12E Wi-Fi  | USART6    | PC6 (TX), PC7 (RX)  |
| PZEM-004T      | USART2    | PA2 (TX), PA3 (RX)  |
| Status LEDs    | GPIO      | [TBD: WIFI_STATUS, ERROR, TASK_ALIVE] |

---

## 🧠 Technologies Used

- **STM32CubeIDE**
- **STM32 HAL Drivers**
- **FreeRTOS**
- **Blynk IoT Cloud**
- **SPI, I2C, UART**
- **OLED SSD1306 (6x8 Font)**
- **PZEM-004T Energy Monitor**
- **BME680 Sensor**
- **SD Card File System**

---

## 🛠️ Build Instructions

1. Clone this repo:  
   ```bash
   git clone https://github.com/YourUsername/STM-IoTHub.git
