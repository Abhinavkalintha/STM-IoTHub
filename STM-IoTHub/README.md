🔌 STM-IoTHub – RTOS-Based Smart Home Automation Hub
STM-IoTHub is an advanced FreeRTOS-based home automation hub developed using the STM32F446RE (Nucleo) microcontroller. This system integrates multiple smart sensors, a relay system, energy monitoring, real-time cloud connectivity via Blynk, and a local OLED display for smart monitoring and control.

<br>
🚀 Key Features
🔄 FreeRTOS-based Task Scheduling

🌡️ BME680 Sensor for Temperature, Humidity, Pressure, and Air Quality

🔌 PZEM-004T for Energy Monitoring (Voltage, Current, Power, Energy)

💾 SD Card Logging using SPI

📶 ESP-12E WiFi Module for Blynk IoT Cloud Integration (USART6)

📟 0.96" SSD1306 OLED Display over I2C2

🔋 Relay Control Unit (Fan/Light)

🛡️ Task Alive, Error, and WiFi Status Indication via LEDs

📂 Fully Modular Code: HAL-based Drivers + RTOS Task Separation

<br>
🧠 Architecture
less
Copy
Edit
                   +-----------------------------+
                   |         STM32F446RE         |
                   |       (Nucleo Board)        |
                   +-----------------------------+
                      |     |     |     |     |
                      |     |     |     |     |
               [I2C1] |     |     |     |     | [I2C2]
                   BME680   |     |     |     OLED Display
                         [USART2]         [USART6]
                         PZEM-004T         ESP-12E (WiFi)
                                [SPI1]
                               SD Card
                         [GPIO Outputs]
                  LED_WIFI | LED_ERROR | LED_ALIVE
<br>
🧰 Hardware Configuration (CubeMX)
Peripheral	Interface	Pins Used
BME680	I2C1	PB6 (SCL), PB7 (SDA)
OLED SSD1306	I2C2	PB10 (SCL), PB3 (SDA)
SD Card	SPI1	PB13 (SCK), PB14 (MISO), PB15 (MOSI), PA5 (CS)
ESP-12E	USART6	PC6 (TX), PC7 (RX)
PZEM-004T	USART2	PA2 (TX), PA3 (RX)
LEDs	GPIO Output	To be configured: LED_WIFI_STATUS, LED_ERROR, TASK_ALIVE

<br>
🧾 Project Structure
bash
Copy
Edit
STM-IoTHub/
├── Core/
│   ├── Inc/
│   │   ├── main.h
│   │   ├── BME680/
│   │   ├── OLED/
│   │   ├── SD/
│   │   └── TASKS/
│   ├── Src/
│   │   ├── main.c
│   │   ├── TASKS/
│   │   │   ├── sensor_task.c
│   │   │   ├── display_task.c
│   │   │   ├── pzem_task.c
│   │   │   ├── relay_task.c
│   │   │   ├── blynk_task.c
│   │   │   └── logger_task.c
├── Drivers/
│   ├── BME680/
│   ├── SSD1306/
│   ├── FATFS/
│   ├── Blynk/
├── Middlewares/
├── STM32CubeMX/
└── README.md
<br>
📲 Blynk App Setup
Note: Blynk integration is already set up and running via the ESP-12E module using UART6.

Create a new project in the Blynk app

Use WiFi (ESP8266) device option

Add widgets like Value Display, Gauge, Graph, etc.

Use your Auth Token and configure it in the STM32 firmware

<br>
🧪 Tasks Implemented
Task	Function
sensor_task	Reads BME680
pzem_task	Reads voltage, current, power from PZEM
display_task	Updates SSD1306 OLED
blynk_task	Sends data to Blynk using ESP-12E
logger_task	Writes sensor data to SD Card
relay_task	Controls relay based on sensor or command
status_task	Manages LED indicators (WiFi/Error/Alive)

<br>
🔧 How to Build
Open STM32CubeIDE

Import the project folder

Ensure .ioc file matches pin config mentioned above

Click Build

Flash to STM32 Nucleo F446RE

<br>
📌 Dependencies
STM32 HAL Drivers

FreeRTOS CMSIS v2

FATFS

SSD1306 Library

ESP AT Command Interface

PZEM UART Protocol

Blynk Virtual Pin Library (Custom)

<br>
🧠 Future Improvements
🔒 Add MQTT for secure communication

📡 OTA updates via Wi-Fi

📈 Host a web dashboard locally

⚡ Integrate solar panel current sensor

🗃️ Implement filesystem navigation on SD

<br>
🧑‍💻 Author
Abhinav Kalintha
Embedded Systems Engineer
LinkedIn • GitHub • Portfolio (Add links once live)