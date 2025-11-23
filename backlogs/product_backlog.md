# Product Backlog – Invernadero IoT

| ID | Historia de Usuario | Prioridad | Criterios de Aceptación |
|----|----------------------|-----------|--------------------------|
| PB1 | Como agricultor quiero ver la temperatura del invernadero | Alta | El dato se publica en MQTT y se muestra en el dashboard |
| PB2 | Como agricultor quiero monitorear la humedad relativa | Alta | El DHT22 reporta la humedad correctamente |
| PB3 | Como agricultor quiero medir la humedad del suelo | Alta | Lectura analógica del sensor de suelo se registra cada 2 segundos |
| PB4 | Quiero que el riego se active automáticamente cuando la humedad esté baja | Alta | El relé se activa cuando el valor analógico del suelo es menor al umbral |
| PB5 | Quiero que los datos de temperatura y humedad se vean en un dashboard IoT | Media | Node-RED recibe y grafica los valores |
| PB6 | Quiero poder controlar manualmente el riego desde el dashboard | Media | Botón de riego ON/OFF en Node-RED |

