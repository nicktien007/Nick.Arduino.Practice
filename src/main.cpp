#include <Arduino.h>
#include "seg7.h"

#define ButtonPin_2 2
#define ButtonPin_10 10
#define LedPin_2 2
#define LedPin_3 3
#define LedPin_5 5
#define LedPin_13 13

#define LedPin_red 11
#define LedPin_green 9
#define LedPin_blue 10

const byte potPin = A0;


int ledPin = 13;
int inPin = 7;
int val = 0;

int num = 0;
int flag = 0;

void ex_01();

void ex_02();

void ex_03();

void ex_04();

void ex_05();

void ex_06();

void ex_07();

void ex_08();

void ex_09();

void ex_10();

void ex_11();

void ex_12();

void ex_13();

void ex_14();

void ex_15();

void ex_16();

void showLED();


void setup() {
    Serial.begin(9600);
//
//    pinMode(LedPin_13, OUTPUT);//內建LED接腳
//    pinMode(LedPin_5, OUTPUT); //外

//    pinMode(LedPin_13, OUTPUT);
//    pinMode(inPin, INPUT);
//
//    pinMode(LedPin_13, OUTPUT);
    pinMode(ButtonPin_2, INPUT_PULLUP);
//    digitalWrite(LedPin_13, LOW);

//    pinMode(potPin, INPUT);

//    pinMode(ButtonPin_10, INPUT_PULLUP);

//    seg7_x1_init(LedPin_2);

//    seg7_x4_init(LedPin_2);
//    randomSeed(analogRead(A0));
//    num=random(0,10000);

    pinMode(LedPin_3, OUTPUT);
//    pinMode(LedPin_13, OUTPUT); // sets the ledPin to be an output
//    pinMode(LedPin_red, OUTPUT); // sets the redPin to be an output
//    pinMode(LedPin_green, OUTPUT); // sets the greenPin to be an output
//    pinMode(LedPin_blue, OUTPUT); // sets the bluePin to be an output
}

void loop() {

    ex_01();
//    ex_02();
//    ex_03();
//    ex_04();
//    ex_05();
//    ex_06();
//    ex_07();
//    ex_08();
//    ex_09();
//    ex_10();
//    ex_11();
//    ex_12();
//    ex_13();
//    ex_14();
//    ex_15();
//    ex_16();
}

/**
 * 使用d5接腳外接一顆LED，然後與內建的led以1秒鐘的時間交互閃爍
 * 對應講議 範例4-1
 */
void ex_01() {
    digitalWrite(LedPin_13, HIGH);
    delay(1000);
    digitalWrite(LedPin_13, LOW);

    digitalWrite(LedPin_5, HIGH);
    delay(1000);
    digitalWrite(LedPin_5, LOW);
}

/**
 * 浮接的範例...沒啥用
 */
void ex_02() {
    val = digitalRead(inPin);
    digitalWrite(LedPin_13, val);
}

/**
 * 按一下 button點亮內建led，按一下熜滅
 */
void ex_03() {
    if (digitalRead(ButtonPin_2) == LOW)
        digitalWrite(LedPin_13, HIGH);
    else
        digitalWrite(LedPin_13, LOW);
}

int buttonState = HIGH;  // variable for reading the pushbutton status
int preState = HIGH;    //按鈕有無被按住的狀態 1=>按著 0=>放開
int countValue = 0;

/**
 * 練習4-1，以按鈕開關實作一個計數器裝置，當使用者按壓開關一次計數值就加1
 * 同時也會將更新後的數直顯示在pc端的串列阜視窗
 */
void ex_04() {
    buttonState = digitalRead(ButtonPin_2);// high(1) or low(0)

    if (buttonState == HIGH      //代表放開按鈕 並且 preState 設為0，則計數器加1
        && preState == LOW) {    //按鈕上一回合是按住的

        countValue++;
        Serial.println(countValue);

        //點亮LED
        digitalWrite(LedPin_13, HIGH);
        delay(100);
        digitalWrite(LedPin_13, LOW);

        preState = HIGH;         //再把prestate 設為1
    } else if (buttonState == LOW) {  //按住按鈕
        preState = LOW;               //設為按住
    }

    //step init : preState=>1,buttonState=>,countValue=>0
    //迴圈ing...不停的把 preState=>0
    //按下button,buttonState => (high:1) and preState=0，進入計數器
    //並且打印和leo，最後prestate=>1

    showLED();
}

void showLED() {
    if (countValue % 2 == 1) {
        digitalWrite(ledPin, LOW);
    } else {
        digitalWrite(ledPin, HIGH);
    }
}

/**
 * 一位數七段顯示器從0顯示到9
 */
void ex_05() {
    for (int i = 0; i < 10; ++i) {
        seg7_x1_display(i);
        delay(1000);
    }
}

/**
 * 範例4-3，使用一位數的七段顯示器來計數按鈕開關按下的次數以按一下就加1的方式顯示
 * 從數用0開始一直到數字9，然後又從0開始
 */
void ex_06() {
    if (digitalRead(ButtonPin_10) == LOW) {
        num = ++num % 10;
        flag = 1;
    }
    if (flag) {
        seg7_x1_display(num);
        flag = 0;
    }
}

/**
 * 一位數七段顯示器外圍，圍繞一圈
 */
void ex_07() {
    for (int i = 0; i < 8; i++) {
        digitalWrite(i, HIGH);
        delay(1000);
        digitalWrite(i, LOW);
    }
}

/**
 * 讀取可變電阻並換算電壓
 */
void ex_08() {
    int val;
    float volt;

    val = analogRead(potPin);
    volt = val * 0.00488;
    Serial.print(val);
    Serial.print("=>");
    Serial.print(volt, 1);
    Serial.println('v');
    delay(1000);
}

/**
 *
 */
void ex_09() {
    int val = analogRead(potPin);
//    float volt = val * 0.00488;

    int timeOut = 0;
    for (int i = 0; i < 8; i++) {
        timeOut = map(val, 0, 1023, 100, 2000);
        Serial.println(timeOut);
        digitalWrite(i, HIGH);
        delay(timeOut);
        digitalWrite(i, LOW);
    }
}

/**
 * 依據可變電阻產生的 timeout 去delay 1位數七段顯示器並隨機顯示0-9
 */
void ex_10() {

    int val = analogRead(potPin);
//    float volt = val * 0.00488;
    int timeOut = map(val, 0, 1023, 100, 3000);
    Serial.println(timeOut);

    int r = random(0, 9);
    seg7_x1_display(r);
    delay(timeOut);
}

void ex_11() {
    seg7_x4_display(3, 4);
    delay(5);
    seg7_x4_display(2, 3);
    delay(5);
    seg7_x4_display(1, 2);
    delay(5);
    seg7_x4_display(0, 9);
    delay(5);
}

/**
 * 練習4-1 使用四位數的七段顯器來顯示0000~9999的亂數，持續監聽serial port
 * 當pc端輸入任一按鍵後，就換下一組亂數
 */
void ex_12() {
    int dig0, dig1, dig2, dig3;

    if (Serial.available()) {
        num = random(0, 10000);
        Serial.println(num);
        Serial.read();
    }
    dig3 = num / 1000;
    seg7_x4_display(3, dig3);
    delay(5);
    dig2 = (num / 100) % 10;
    seg7_x4_display(2, dig2);
    delay(5);
    dig1 = (num / 10) % 10;
    seg7_x4_display(1, dig1);
    delay(5);
    dig0 = num % 10;
    seg7_x4_display(0, dig0);
    delay(5);
}

void ex_13() {
    int val;
    for (val = 0; val < 256; val = val + 15) {
        analogWrite(LedPin_3, val);
        delay(100);
    }

    for (val = 255; val >= 0; val = val - 15) {
        analogWrite(LedPin_3, val);
        delay(100);
    }
}

void ex_14() {
    int val;
    float volt;
    int timeOut;

    val = analogRead(potPin);
    volt = val * 0.00488;
//    timeOut = map(volt, 0, 255, 0, 255);
    Serial.println(volt);

    analogWrite(LedPin_3, volt);
}

// the color generating function
void color(unsigned char red, unsigned char green, unsigned char blue) {
    analogWrite(LedPin_red, red);
    analogWrite(LedPin_blue, blue);
    analogWrite(LedPin_green, green);
}

/**
 * 全彩 RGB LED demo
 */
void ex_15() {
    // Basic colors:
    color(255, 0, 0); // turn the RGB LED red
    delay(1000); // delay for 1 second

    color(0, 255, 0); // turn the RGB LED green
    delay(1000); // delay for 1 second

    color(0, 0, 255); // turn the RGB LED blue
    delay(1000); // delay for 1 second

    //Example blended colors:
    color(255, 255, 0); // turn the RGB LED yellow
    delay(1000); // delay for 1 second

    color(255, 255, 255); // turn the RGB LED white
    delay(1000); // delay for 1 second

    color(128, 0, 255); // turn the RGB LED purple
    delay(1000); // delay for 1 second

    color(0, 0, 0); // turn the RGB LED off
    delay(1000); // delay for 1 second
}

int lightness;
int step = 30;

void ex_16() {
    buttonState = digitalRead(ButtonPin_2);

    if (buttonState == HIGH      //放開按鈕
        && preState == LOW) {

        if (lightness >= 240)
            step = -30;

        if (lightness <= 0)
            step = 30;

        lightness += step;

        Serial.println(lightness);
        preState = HIGH;
    } else if (buttonState == LOW) {  //按住按鈕
        preState = LOW;
        delay(100);
    }
    analogWrite(LedPin_3, lightness);
}