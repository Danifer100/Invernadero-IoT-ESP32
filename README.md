# 🌱 Proyecto IoT – Invernadero Inteligente con ESP32

Este proyecto desarrolla un sistema IoT para medir temperatura, humedad ambiental y humedad de suelo dentro de un invernadero automatizado.  
La solución controla el riego mediante un relé y publica todos los datos en MQTT para visualización en plataformas como Node-RED.

---

## ✔ Tecnologías utilizadas
- ESP32 DevKit V1  
- Sensor DHT22  
- Sensor de humedad de suelo  
- Módulo relé  
- Wokwi (simulación)  
- MQTT (HiveMQ)  
- Node-RED (dashboard)  
- GitHub (control de versiones)

---

## 📡 Arquitectura del sistema

Sensores → ESP32 → MQTT (HiveMQ) → Node-RED Dashboard

## 📁 Estructura del repositorio
/codigo → Código en Arduino para ESP32
/wokwi → Simulación completa (diagram.json)
/documentacion → PDF, informe, anexos
/backlogs → Product Backlog, Sprint Backlog, DoD
/img → Capturas del proyecto



---

## ▶ Cómo ejecutar la simulación en Wokwi
1. Abre el archivo `diagram.json`
2. Copia todo en https://wokwi.com/
3. Agrega las librerías:
   - PubSubClient
   - DHT sensor library
   - Adafruit Unified Sensor
4. Presiona ▶ Run
5. Abre Serial Monitor (Ctrl + Shift + M)

---

## 📡 MQTT Topics utilizados
invernadero/temperatura
invernadero/humedad
invernadero/suelo
invernadero/riego

---

## 🧪 Dashboard Node-RED
- Gráfica de temperatura  
- Gráfica de humedad  
- Indicador de humedad de suelo  
- Estado del riego  
- Botón de control manual  

---

## 👨‍💻 Autor
Daniel Fernando I.  
Ingeniería de Sistemas
