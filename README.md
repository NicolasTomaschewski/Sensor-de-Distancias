# Esquema de Conexões do Projeto de Medição de Distância

## Componentes Utilizados
- **Arduino Uno/Nano**
- **Sensor Ultrassônico HC-SR04**
- **Display LCD I2C (endereço 0x27)**
- **LEDs (3 LEDs)**
- **Resistores (se necessário para LEDs)**

## Ligações

### 1. **Sensor Ultrassônico HC-SR04**
- **VCC**: Pino de alimentação do sensor (5V) -> **5V** no Arduino.
- **GND**: Pino de terra do sensor -> **GND** no Arduino.
- **Trig**: Pino de trigger do sensor -> **Pino Digital 8** no Arduino.
- **Echo**: Pino de echo do sensor -> **Pino Digital 9** no Arduino.

### 2. **Display LCD I2C**
- **VCC**: Pino de alimentação do LCD -> **5V** no Arduino.
- **GND**: Pino de terra do LCD -> **GND** no Arduino.
- **SDA**: Pino de dados I2C do LCD -> **A4** no Arduino Uno/Nano (ou pino SDA no Arduino Mega).
- **SCL**: Pino de clock I2C do LCD -> **A5** no Arduino Uno/Nano (ou pino SCL no Arduino Mega).

### 3. **LEDs**
- **LED 1 (Pino 4)**
  - **Anodo**: Pino longo do LED -> **Pino Digital 4** no Arduino.
  - **Catodo**: Pino curto do LED -> **Resistor de Limitação** (220Ω, por exemplo) -> **GND** no Arduino.
- **LED 2 (Pino 5)**
  - **Anodo**: Pino longo do LED -> **Pino Digital 5** no Arduino.
  - **Catodo**: Pino curto do LED -> **Resistor de Limitação** (220Ω, por exemplo) -> **GND** no Arduino.
- **LED 3 (Pino 6)**
  - **Anodo**: Pino longo do LED -> **Pino Digital 6** no Arduino.
  - **Catodo**: Pino curto do LED -> **Resistor de Limitação** (220Ω, por exemplo) -> **GND** no Arduino.


Certifique-se de que as conexões estão feitas corretamente e que o endereço I2C do LCD está correto. Se o LCD ainda não funcionar, pode ser necessário verificar a biblioteca `LiquidCrystal_I2C` ou o módulo LCD para garantir que não há problemas com o hardware.

