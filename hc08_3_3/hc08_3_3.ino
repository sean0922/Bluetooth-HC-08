#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX

void setup()

{

pinMode(9, OUTPUT); // 給EN或KEY使用進入AT模式

digitalWrite(9, HIGH);

Serial.begin(9600);

Serial.println("Enter AT commands:");

BTSerial.begin(9600);
BTSerial.write("AT+STATE+PAIRABLE");

}

void loop()

{

// 讀取藍芽傳輸之資料且傳送至序列阜顯示

if (BTSerial.available())
Serial.write(BTSerial.read());

// 讀取序列阜傳輸之資料且傳送至藍芽顯示

if (Serial.available())
BTSerial.write(Serial.read());


/*byte cmmd[20];

int insize;


if ((insize=(BTSerial.available()))>0){

//Serial.print("input size = ");

Serial.println(insize);

for (int i=0; i<insize; i++){

Serial.print(cmmd[i]=char(BTSerial.read()));

Serial.print("\n");

}

}

//根據所收到訊號執行對應動作

switch (cmmd[0]) {

//讀取第一個字元

case 97: //'a' 黑

Serial.print("成功了A!!!!!!");

break;

case 98: //'b' 黑

Serial.print("成功了B!!!!!!");

break;}*/

}
