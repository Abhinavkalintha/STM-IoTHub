  # 🔌 STM-IoTHub - Real-Time IoT Home Automation System (STM32 + FreeRTOS)

STM-IoTHub is a real-time embedded home automation system built using the STM32F446RE microcontroller and FreeRTOS.  
The system integrates multiple features including environmental sensing (temperature, humidity, pressure, air quality), Wi-Fi communication (ESP-12E), energy monitoring (PZEM-004T), data logging to SD card (SPI), and OLED-based visual feedback (SSD1306 over I2C).

The architecture is modular and built using STM32 HAL drivers. Each peripheral and function is handled by an independent FreeRTOS task, enabling clean code separation, real-time performance, and future scalability.  
This project is ideal for use cases like smart energy monitoring, remote environmental sensing, and automated control systems.

 ## 🚀 Features

- **RTOS-Based Task Handling**: All functionalities run as independent FreeRTOS tasks for modular and real-time performance.
- **Environmental Monitoring**: Measures temperature, humidity, pressure, and air quality using the BME680 sensor (I2C).
- **Energy Metering**: Real-time voltage, current, power, and energy readings using the PZEM-004T module (UART).
- **Data Logging**: Periodic sensor and energy data is stored on a microSD card using SPI interface.
- **OLED Display**: Real-time data visualization using SSD1306 0.96" OLED (I2C).
- **Wi-Fi Communication**: Remote data transmission via ESP-12E (UART), ready for future MQTT or cloud integration.
- **Interrupt-Based Control**: User input (e.g., button press) triggers actions via external interrupt lines.
- **Modular Codebase**: Each peripheral managed through its own source files, improving scalability and code reuse.
- **Low Power Ready**: Designed with support for future power optimization (e.g., sleep modes).

## 🔧 Hardware Used

| Component            | Description                                                              |
|----------------------|--------------------------------------------------------------------------|
| **Nucleo-F446RE**     | STM32F446RE development board used as the main microcontroller (ARM Cortex-M4). |
| **BME680 Sensor**      | Environmental sensor for temperature, humidity, pressure, and air quality (I2C). |
| **PZEM-004T v3.0**     | Energy monitoring module to measure voltage, current, power, and energy (UART). |
| **SSD1306 OLED 0.96"** | Display module for real-time data display (I2C).                         |
| **ESP-12E (ESP8266)**  | Wi-Fi module for wireless communication and cloud readiness (UART).     |
| **SRD-05VDC Relay**    | Relay module with optocoupler for AC load control (fan/lights).         |
| **MicroSD Card Module**| For logging sensor and energy data locally via SPI interface.           |
| **Push Button**        | User input through external interrupt.                                  |
| **Jumper Wires + Breadboard** | Prototyping and testing connections.                                 |
| **Power Supply (5V)**  | For powering the microcontroller and peripherals.                       |

## 🧰 Software Used

| Tool / Framework         | Purpose                                                                 |
|--------------------------|-------------------------------------------------------------------------|
| **STM32CubeIDE**         | Integrated development environment for coding, compiling, and debugging STM32 projects. |
| **STM32CubeMX**          | GUI tool for peripheral configuration, pin mapping, and code generation. |
| **HAL (Hardware Abstraction Layer)** | STM32 abstraction library used to simplify hardware interfacing.         |
| **FreeRTOS**             | Real-Time Operating System for task management and concurrency handling. |
| **Blynk IoT Platform**   | Cloud and mobile app-based platform for remote control and real-time monitoring. |
| **GNU Arm Toolchain**    | Compiler and build tools for ARM Cortex-M development.                  |
| **VS Code (optional)**   | Used for markdown editing and documentation.                            |
| **Git**                  | Version control system for project tracking and collaboration.          |

## 🛠️ How It Works

This smart home automation system operates by coordinating multiple hardware modules through FreeRTOS tasks running on an STM32F446RE microcontroller. Here's how the entire system works step-by-step:

### 1️⃣ Sensor Data Acquisition
- **BME680 Task** reads environmental data such as temperature, humidity, pressure, and air quality over the I2C bus.
- **PZEM-004T Task** captures energy parameters like voltage, current, power, and total energy consumed via UART.

### 2️⃣ Real-Time Processing with FreeRTOS
- Each task runs independently under the FreeRTOS scheduler.
- Task synchronization and timing are managed using `vTaskDelay()` and other FreeRTOS APIs.
- All sensors are polled periodically (e.g., every 2–5 seconds) without blocking other tasks.

### 3️⃣ Display on OLED
- The **OLED Task** fetches the latest sensor values from global/shared variables or queues.
- Displays real-time environmental and power metrics on the 0.96 SSD1306 OLED screen via I2C.

### 4️⃣ Wireless Monitoring via Blynk
- The **ESP-12E (ESP8266)** connects to Wi-Fi and communicates with the Blynk Cloud.
- The **Blynk Task** sends updated sensor and energy data to the Blynk mobile app via UART (AT commands).
- Users can view the live sensor readings and control relays remotely.

### 5️⃣ Relay Control
- The **Relay Task** manages turning ON/OFF loads (e.g., lights/fans) through GPIO.
- Relays can be triggered either:
  - Automatically based on sensor thresholds (e.g., turn fan ON if temperature > 30°C), or
  - Manually through the Blynk app interface.

### 6️⃣ Continuous Feedback Loop
- The system constantly cycles through acquiring data, processing it, displaying it locally, and sending it to the cloud.
- Thanks to FreeRTOS, all tasks run concurrently with efficient CPU utilization.

##  📁 Project Structure
STM-IoTHub/
├── .settings/
├── Core/
│   ├── Inc/
│   │   ├── BME680/
│   │   │   ├── bme68x.h
│   │   │   ├── bme68x_defs.h
│   │   │   ├── bme680_app.h
│   │   │   └── bme680_user.h
│   │   ├── PZEM004T/
│   │   │   ├── pzem004t.h
│   │   │   └── pzem004t_app.h
│   │   ├── RELAY/
│   │   │   └── relay_control.h
│   │   ├── SD/
│   │   │   ├── fatfs_sd.h
│   │   │   └── user_diskio.h
│   │   ├── SSD1306/
│   │   │   ├── font6x8.h
│   │   │   ├── ssd1306.h
│   │   │   └── ssd1306_fonts.h
│   │   ├── TASKS/
│   │   │   ├── bme680_task.h
│   │   │   ├── fan_task.h
│   │   │   ├── light_task.h
│   │   │   ├── oled_task.h
│   │   │   ├── pzem_task.h
│   │   │   ├── pzem004t_task.h
│   │   │   ├── relay_automation_task.h
│   │   │   ├── relay_task.h
│   │   │   ├── sensor_data.h
│   │   │   ├── sensor_task.h
│   │   │   ├── shared_data.h
│   │   │   ├── tasks.h
│   │   │   └── uart_ring.h
│   │   ├── WIFI/
│   │   │   └── esp8266.h
│   │   ├── BLYNK/
│   │   │   ├── BlynkApi.h
│   │   │   ├── BlynkConfig.h
│   │   │   ├── BlynkProtocolDefs.h
│   │   │   └── BlynkUtility.h
│   │   ├── FreeRTOSConfig.h
│   │   ├── main.h
│   │   ├── sdcard.h
│   │   ├── spi.h
│   │   ├── status_led.h
│   │   ├── stm32f4xx_hal_conf.h
│   │   └── stm32f4xx_it.h
│
│   ├── Src/
│   │   ├── BME680/
│   │   │   ├── bme68x.c
│   │   │   ├── bme680_app.c
│   │   │   └── bme680_user.c
│   │   ├── PZEM004T/
│   │   │   ├── pzem004t.c
│   │   │   └── pzem004t_app.c
│   │   ├── RELAY/
│   │   │   └── relay_control.c
│   │   ├── SD/
│   │   │   ├── fatfs_sd.c
│   │   │   └── user_diskio.c
│   │   ├── SSD1306/
│   │   │   ├── ssd1306.c
│   │   │   └── ssd1306_fonts.c
│   │   ├── TASKS/
│   │   │   ├── alert_task.c
│   │   │   ├── energy_task.c
│   │   │   ├── fan_task.c
│   │   │   ├── light_task.c
│   │   │   ├── oled_task.c
│   │   │   ├── pzem_task.c
│   │   │   ├── relay_automation_task.c
│   │   │   ├── relay_task.c
│   │   │   ├── sensor_data.c
│   │   │   ├── sensor_task.c
│   │   │   ├── shared_data.c
│   │   │   ├── uart_ring.c
│   │   │   └── wifi_task.c
│   │   ├── WIFI/
│   │   │   └── esp8266.c
│   │   ├── freertos.c
│   │   ├── main.c
│   │   ├── sdcard.c
│   │   ├── spi.c
│   │   ├── status_led.c
│   │   ├── stm32f4xx_hal_msp.c
│   │   ├── stm32f4xx_it.c
│   │   ├── syscalls.c
│   │   ├── sysmem.c
│   │   └── system_stm32f4xx.c
│
│   ├── Startup/
│   │   └── startup_stm32f446xx.s
│
├── Debug/
├── Drivers/
├── FATFS/
├── Middlewares/
├── .cproject
├── .mproject
├── .project
├── README.md
├── STM32F446RETX_FLASH.ld
├── STM32F446RETX_RAM.ld
└── STM-IoTHub.ioc



