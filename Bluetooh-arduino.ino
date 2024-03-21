//*****************DIRETIVAS DO PRÉ-PROCESSADOR*************

//includes (arquivos de inclusão) e define (definições)


#include "BluetoothSerial.h";

//*****************DECLARAÇÕES GLOBAIS**********************

//declaração de variáveis e funções (subrotinas)

char recebido = 0; 
BluetoothSerial SerialBT;

//**********************SETUP*******************************

//define condições de trabalhos dos pinos (input/output), velocidade de comunicação e outras funções

void setup()
{
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif


Serial.begin(115200);
SerialBT.begin("ESP32_PCB3");

//Serial.println("O dispositivo foi inicializado! Pareando...");

pinMode(2,OUTPUT);
}

//*********************PROGRAMA PRINCIPAL******************

void loop()
{
  if (SerialBT.available() > 0)
  {
    recebido = SerialBT.read();
    Serial.write(recebido);  
  }

  if (recebido == 0)
  {
    digitalWrite(2, LOW)
  } 
  else 
  {
    digitalWrite(2, HIGH)
  }

}

//**********************DEFINIÇÕES DAS FUNÇÕES************
//subrotinas da programação
