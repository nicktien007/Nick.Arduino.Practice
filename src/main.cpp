#include <Arduino.h>
#include "music.h"  //載入音樂定義檔
#include "seg7.h"
#include "DHT.h"
#include<avr/wdt.h>
#include <avr/power.h>
#include <avr/sleep.h>
#include <wiring_private.h>

#define ButtonPin_2 2
#define ButtonPin_10 10
#define LedPin_2 2
#define LedPin_3 3
#define LedPin_5 5
#define LedPin_11 11
#define LedPin_13 13

#define LedPin_red 11
#define LedPin_green 9
#define LedPin_blue 10

#define Buzzer 2  //指定蜂鳴器的接腳為D3
#define DHpin  8
#define dhtType DHT11



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

void ex_17();

void ex_18();

void ex_19();

void ex_20();

void ex_21();

void ex_22();

void ex_23();

void ex_24();

void ex_25();

void ex_26();

void ex_27();

void ex_28();

void ex_29();

void ex_30();

void ex_31();

void ex_32();
void ex_33();
void ex_34();
void ex_35();

void my_ISR();

void showLED();

void color(unsigned char red, unsigned char green, unsigned char blue);

void showLed();

void showLed_18();

void runEx18();

void init_ex18();

void init_ex18_time();

void showCounter();

void counter_ISR();

void setupTimer_ex23();
void setupTimer_ex24();
void setupTimer_ex31();

//const byte rowPins[4]={13,12,11,10};
//const byte colPins[4]={9,8,7,6};
const byte rowPins[4] = {11, 10, 9, 8};
const byte colPins[4] = {7, 6, 5, 4};
const char keymap[4][4] = {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'*', '0', '#', 'D'},
};

void showKeyNumber();
//DHT dht(DHpin, dhtType);
void setup() {
    Serial.begin(9600);
//
//    pinMode(LedPin_13, OUTPUT);//內建LED接腳
//    pinMode(LedPin_5, OUTPUT); //外

//    pinMode(LedPin_13, OUTPUT);
//    pinMode(inPin, INPUT);
//
//    pinMode(LedPin_13, OUTPUT);
//    digitalWrite(LedPin_13, LOW);

//    pinMode(potPin, INPUT);

//    pinMode(ButtonPin_10, INPUT_PULLUP);

//    seg7_x1_init(LedPin_2);

//    seg7_x4_init(LedPin_2);
//    randomSeed(analogRead(A0));
//    num = random(0,10000);
//    num = random(0,9);
//    pinMode(LedPin_11, OUTPUT);


//    pinMode(LedPin_3, OUTPUT);
//    pinMode(LedPin_13, OUTPUT); // sets the ledPin to be an output
//    pinMode(LedPin_red, OUTPUT); // sets the redPin to be an output
//    pinMode(LedPin_green, OUTPUT); // sets the greenPin to be an output
//    pinMode(LedPin_blue, OUTPUT); // sets the bluePin to be an output

//    pinMode(ButtonPin_2, INPUT_PULLUP);
    pinMode(Buzzer,OUTPUT);       //設定蜂鳴器接腳為輸出模式
//    pinMode(DHpin,OUTPUT);

    pinMode(LedPin_13, OUTPUT);
//    digitalWrite(LedPin_13, LOW);
//    attachInterrupt(digitalPinToInterrupt(ButtonPin_2), my_ISR, FALLING);
//    attachInterrupt(digitalPinToInterrupt(ButtonPin_2), counter_ISR, RISING);

    // |= 通常指設為"1"的動作
    // &= 通常指設為"0"的動作
    // ~ 反向
//    EIMSK |= _BV(INT0);
//    EICRA &= ~_BV(ISC01);
//    EICRA |= _BV(ISC00);

//    for (int i = 0; i <= 3; i++) {
////        pinMode(rowPins[i],INPUT);
//        pinMode(rowPins[i], INPUT_PULLUP);
//        pinMode(colPins[i], OUTPUT);
//        digitalWrite(colPins[i], HIGH);
////        digitalWrite(rowPins[i], HIGH);
//    }
//
//    PCICR |= 0b00000001;//enables PCINT0
//    PCMSK0 |= 0b00001111;//choose D8,9,10,11 to be active

//    setupTimer_ex23();
//    setupTimer_ex24();

    //dht.begin();

//    wdt_enable(WDTO_4S);
//    Serial.println("System reboot......");
//    Serial.println("Input char");

//   MCUSR &= ~(1 << WDRF);
//   WDTCSR |= (1 << WDCE) |(1<<WDE);
//   WDTCSR = 1 << WDP3 | 1 << WDP0;
//   WDTCSR |= (1 << WDIE);
//   Serial.println("System reboot......");
//   Serial.println("Input char");

//    setupTimer_ex31();

//    Serial.println("Initialising...");
//    delay(100);
//    MCUSR &= ~(1 << WDRF);
//    WDTCSR |= (1 << WDCE) | (1 << WDE);
////    WDTCSR = 1<<WDP3 | 1<<WDP0;
//    WDTCSR = 1 << WDP3 ;
//    WDTCSR |= (1 << WDIE);
//    Serial.println("complete");
}

void loop() {
//    ex_01();
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
//    ex_17();
//    ex_18();
//    ex_19();
//    ex_20();
//    showCounter();
//    ex_21();
//    ex_22();
//    ex_23();
//    ex_24();
//    ex_25();
//    ex_26();
//    ex_27();
//    ex_28();
//    ex_29();
//    ex_30();
//    ex_31();
//    ex_32();
//    ex_33();
    ex_35();
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

int buttonState = HIGH;  // 按鈕狀態 LOW=>按著 HIGH=>放開
int preState = HIGH;
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

/**
 * 四位數七段顯示器基本 DEMO
 */
void ex_11() {
    seg7_x4_display(3, 3);
    delay(5);
    seg7_x4_display(2, 2);
    delay(5);
    seg7_x4_display(1, 1);
    delay(5);
    seg7_x4_display(0, 0);
    delay(5);
}
int dig0 = 0;
int dig1 = 0;
int dig2 = 0;
int dig3 = 0;
/**
 * 練習4-1 使用四位數的七段顯器來顯示0000~9999的亂數，持續監聽serial port
 * 當pc端輸入任一按鍵後，就換下一組亂數
 */
void ex_12() {
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

/**
 * 接一個led，先遞增亮，接著遞減亮
 */
void ex_13() {
    int val;

    //遞增亮
    for (val = 0; val < 256; val = val + 15) {
        analogWrite(LedPin_3, val);
        delay(100);
    }

    //遞減亮
    for (val = 255; val >= 0; val = val - 15) {
        analogWrite(LedPin_3, val);
        delay(100);
    }
}

/**
 * 使用可變電阻控制LED
 */
void ex_14() {
    int val;
    float volt;
    int v;

    val = analogRead(potPin);
    volt = val * 0.00488;
//    Serial.println(val);
//    Serial.println(volt);
    delay(500);

    analogWrite(LedPin_3, volt);
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

/**
 * the color generating function
 * @param red
 * @param green
 * @param blue
 */
void color(unsigned char red, unsigned char green, unsigned char blue) {
    analogWrite(LedPin_red, red);
    analogWrite(LedPin_blue, blue);
    analogWrite(LedPin_green, green);
}

int lightness;
int step = 30;

/**
 * 使用一個按鈕按一下遞增led亮度
 * 達到最亮，遞減 led 亮度
 */
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

int target = 2;         //答案
int guessVal = 0;       //儲存每次按下按鈕猜測的數字
bool isGuess = false;   //是否正在
unsigned long timeNow = 0;
unsigned long timeNow0 = 0;
unsigned long timeNow1 = 0;
unsigned long timeNow2 = 0;
unsigned long timeNow3 = 0;

void ex_17() {
    delay(100);
    buttonState = digitalRead(ButtonPin_10);

    if (buttonState == HIGH      //放開按鈕
        && preState == LOW) {

        isGuess = !isGuess; //每次放開按鈕，更新是否有在猜的狀態 => 按一下:猜，按一下:不猜
        guessVal = num;     //把隨機數塞給guessVal，稍候7段顯示器做顯示
        digitalWrite(LedPin_11, LOW);

        preState = HIGH;
        return;
    }

    if (buttonState == LOW) {  //按住按鈕
        preState = LOW;
        return;
    }

    int v = analogRead(potPin);
    int timeOut = map(v, 0, 1023, 50, 2000);
    //這邊開始進行 Delay
    if (millis() >= timeNow + timeOut) {
        timeNow += timeOut;
        //如果是猜數字模式，顯示猜的數字
        if (isGuess) {
            seg7_x1_display(guessVal);
            showLed();
            return;
        }
        num = random(0, 9);
        seg7_x1_display(num);
    }
}

void showLed() {
    if (guessVal == target) {
        digitalWrite(LedPin_11, HIGH);
    } else {
        digitalWrite(LedPin_11, LOW);
    }
}

bool isStart = false;
int vv;

void ex_18() {

    if (Serial.available()) {
        init_ex18();
        seg7_x1_display(target);
        delay(2000);
        init_ex18_time();
    }

    if (isStart) {
        runEx18();
    }
}

void init_ex18_time() {
    timeNow = millis();
    timeNow2 = millis();
}

void init_ex18() {
    target = Serial.parseInt();
    Serial.println(target);
    vv = 0;
    analogWrite(LedPin_11, 0);
    isGuess = false;
    isStart = true;
}

void runEx18() {
    delay(100);
    buttonState = digitalRead(ButtonPin_10);

    if (buttonState == HIGH      //放開按鈕
        && preState == LOW) {

        isGuess = !isGuess; //每次放開按鈕，更新是否有在猜的狀態 => 按一下:猜，按一下:不猜
        guessVal = num;     //把隨機數塞給guessVal，稍候7段顯示器做顯示
        digitalWrite(LedPin_11, LOW);

        preState = HIGH;
        return;
    }

    if (buttonState == LOW) {  //按住按鈕
        preState = LOW;
        return;
    }

    int v = analogRead(potPin);
    int timeOut = map(v, 0, 1023, 50, 2000);
    //這邊開始進行 Delay
    if (millis() >= timeNow + timeOut) {
        timeNow += timeOut;
        //如果是猜數字模式，顯示猜的數字
        if (isGuess) {
            seg7_x1_display(guessVal);
            showLed_18();
            return;
        }
        num = random(0, 10);
        seg7_x1_display(num);
    }
}

int interval = 30;

void showLed_18() {
    if (guessVal == target) {

        if (guessVal == 0) {
            analogWrite(LedPin_11, 0);
            return;
        }

        if (vv >= (target * 255 / 10))
            interval = -25;

        if (vv <= 0)
            interval = 25;

        if (millis() >= timeNow2 + 100) {
            timeNow2 += 100;
            analogWrite(LedPin_11, vv += interval);
        }
    } else {
        analogWrite(LedPin_11, 0);
    }
}

/**
 * 外部中斷範例(polling)
 */
void ex_19() {

    if (digitalRead(ButtonPin_2) == HIGH) {
        flag = 1;
    }

    if (digitalRead(ButtonPin_2) == LOW && flag == 1) {
        digitalWrite(LedPin_13, !digitalRead(LedPin_13));
        flag = 0;
    }
}



//ISR(INT0_vect){
//    my_ISR();
//}

//ISR(PCINT0_vect) {
//    showKeyNumber();
//}

byte i, j;
byte scanVal;
bool doShow = false;
char showVal = 0;
void showKeyNumber() {
    for (i = 0; i <= 3; i++) {
        for (j = 0; j <= 3; j++) {
            digitalWrite(colPins[j], LOW);
            scanVal = digitalRead(rowPins[i]);
            digitalWrite(colPins[j], HIGH);
            delay(200);
            if (scanVal == LOW) {
                showVal = keymap[i][j];
                doShow = true;
                break;
            }
        }
    }
}

void ex_20() {

    if (digitalRead(ButtonPin_2) == LOW) {
        digitalWrite(LedPin_13, HIGH);
    } else {
        digitalWrite(LedPin_13, LOW);
    }
}

void counter_ISR() {
    num++;
    flag = 1;
}

void showCounter() {
    if (flag == 1) {
        Serial.println(num);
        flag = 0;
    }
}

void ex_21() {
    for (i = 0; i <= 3; i++) {
        for (j = 0; j <= 3; j++) {
            digitalWrite(colPins[j], LOW);
            scanVal = digitalRead(rowPins[i]);

            if (scanVal == LOW) {
                Serial.println(keymap[i][j]);
                delay(200);
                digitalWrite(colPins[j], HIGH);
                break;
            }

            digitalWrite(colPins[j], HIGH);
        }
    }
}

/**
 * HW-2(Keymap)
 * https://thewanderingengineer.com/2014/08/11/arduino-pin-change-interrupts/
 * https://blog.csdn.net/acktomas/article/details/88365129
 */
void ex_22() {
    if (doShow) {
        Serial.println(showVal);
        doShow = false;
    }

    for (j = 0; j <= 3; j++) {
        digitalWrite(colPins[j], LOW);
    }
}

void ex_23() {
    for (int i = 0; i < 100; ++i) {
        Serial.println(i);
    }
}

//ISR(TIMER1_COMPA_vect){
//    digitalWrite(LedPin_13, !digitalRead(LedPin_13));
//}

void setupTimer_ex23(){
    //init 暫存器
    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1 = 0;

    //設定CTC 模式
    TCCR1B = TCCR1B | (1 << WGM12);

    //設定預先除頻倍數prescaler與正確的TOP上限值
    TCCR1B = TCCR1B | (1 << CS12);
    OCR1A = 62500;

    //致能對應的中斷
    TIMSK1 = TIMSK1 | (1<< OCIE1A);
}

void ex_24() {
    //它沒有用了...
}

//int timeOut0 = 2000;
//int timeOut1 = timeOut0 * 2;
//int timeOut2 = timeOut0 * 3;
//int timeOut3 = timeOut0 * 4;
//ISR(TIMER2_COMPA_vect){
//    if (Serial.available()) {
//        num = random(0, 10000);
//        Serial.println(num);
//
//        dig3 = num / 1000;
//        dig2 = (num / 100) % 10;
//        dig1 = (num / 10) % 10;
//        dig0 = num % 10;
//
//        Serial.read();
//        return;
//    }
//
//    //這邊開始進行 Delay
//    if (micros() >= timeNow0 + timeOut0) {
//        timeNow0 += timeOut0;
//        seg7_x4_display(0, dig0);
//    }
//
//    if (micros() >= timeNow1 + timeOut1) {
//        timeNow1 += timeOut1;
//        seg7_x4_display(1, dig1);
//    }
//
//    if (micros() >= timeNow2 + timeOut2) {
//        timeNow2 += timeOut2;
//        seg7_x4_display(2, dig2);
//    }
//
//    if (micros() >= timeNow3 + timeOut3) {
//        timeNow3 += timeOut3;
//        seg7_x4_display(3, dig3);
//    }
//}
#define bbs(x) (1<<x)
void setupTimer_ex24(){
    //init 暫存器
    TCCR2A = 0;
    TCCR2B = 0;
    TCNT2 = 0;

    //設定CTC 模式
    TCCR2B = TCCR2B | (1 << WGM21);

    //設定預先除頻倍數prescaler與正確的TOP上限值
    TCCR2B = TCCR2B | (1 << CS21);
    OCR2A = 63; //delay 0.001s

    //致能對應的中斷
    TIMSK2 = TIMSK2 | (1<< OCIE2A);

    //============================使用上面的代碼，或下面的都可以====================

//    cli();  // 禁止中斷
//    TCCR2A = bbs(WGM21);  // CTC mode 2; Clear Timer on Compare, see p.158-162
//    TCCR2B = bbs(CS22);  // Prescaler == 64; see p.162 in datasheet
//    ///// 注意 WGM22 在 TCCR2B, 但 WGM21 與 WGM20 在 TCCR2A;
//    ///// mode 由 WGM22, WGM21, WGM20 決定 (see datasheet p.158-162)
//    OCR2A = 24999;  // TOP count for CTC, 與 prescaler 有關
//    TCNT2 = 0;  // counter 歸零
//    TIMSK2 |= bbs(OCIE2A);  // enable CTC for TIMER2_COMPA_vect
//    sei();  // 允許中斷IMER2_COMPA_vect
}

void ex_25() {
    tone(LedPin_13, 31,2000);
    delay(3000);
}

void play0() {
    for(int i=0;i<10;i++) {
        digitalWrite(Buzzer,HIGH); delay(50);
        digitalWrite(Buzzer,LOW); delay(200);
    }
}

void play1() {
    for(int i=0;i<5;i++) {
        digitalWrite(Buzzer,HIGH); delay(600);
        digitalWrite(Buzzer,LOW); delay(100);
    }
}

void play2() {
    for(int i=0;i<5;i++) {
        digitalWrite(Buzzer,HIGH); delay(300);
        digitalWrite(Buzzer,LOW); delay(50);
        digitalWrite(Buzzer,HIGH); delay(50);
        digitalWrite(Buzzer,LOW); delay(50);
        digitalWrite(Buzzer,HIGH); delay(50);
        digitalWrite(Buzzer,LOW); delay(50);
    }
}

/**
 * 有源蜂鳴器範例
 */
void ex_26() {
    //讀取Button接腳的電位是否為LOW
    if (digitalRead(ButtonPin_2) == LOW)  {
        num = ++num % 3;
        flag = 1;
    }
    //若是，就代表按下開關，num+1後取3的餘數
    if (flag == 1) {
        switch (num) {
            case 0:
                play0();
                break;
            case 1:
                play1();
                break;
            case 2:
                play2();
        }
        flag = 0;
    }
}
//S140:每分鐘140拍
int speed[3] = {S140, S80, S60};   //三首歌的速度
//定義音高,XX表結束
int pitch[3][30] = {
        {G4, E4, E4, 0,  F4, D4, D4, 0,  C4, D4, E4, F4, G4, G4, G4, 0,  XX},     //小蜜蜂
        {C4, C4, D4, E4, E4, D4, C4, D4, E4, C4, 0,  E4, E4, F4, G4, G4, F4, E4, F4, G4, E4, 0, XX},//蝴蝶
        {C4, C4, D4, F4, G4, F4, G4, A4, 0,  C5, A4, A4, G4, F4, G4, 0, 0,   XX}}; //望春風
//定義節拍
float tempo[3][30] = {
        {T4,  T4, T4, T4, T4, T4, T4, T4, T4, T4,  T4, T4, T4, T4, T4, T4},      //小蜜蜂
        {T4,  T8, T8, T4, T4, T8, T8, T8, T8, T4,  T4, T4, T8, T8, T4, T4, T8, T8, T8, T8, T4, T4},//蝴蝶
        {T4d, T8, T4, T4, T4, T8, T8, T4, T4, T4d, T8, T8, T8, T4, T2, T4, T4}}; //望春風

void play(int num) {
    int i, T1time, duration;
    T1time = 4 * 60000 / speed[num];          //計算全音符T1的時間(ms)
    for (i = 0;; i++) {
        if (pitch[num][i] == 9999) return;   //判斷結尾
        duration = T1time * tempo[num][i];    //計算節拍時間(ms)
        tone(Buzzer, pitch[num][i], duration / 2);  //演奏一半
        delay(duration / 2);                //停頓一半，才不會所有的音都連在一起
    }
}

/**
 * 無源蜂鳴器範例
 */
void ex_27() {
    if (digitalRead(ButtonPin_2) == LOW)  //讀取Button接腳的電位是否為LOW
    {
        num = ++num % 3;
        flag = 1;
    }    //若是，就代表按下開關，num+1後取3的餘數
    if (flag == 1) {
        play(num);
        flag = 0;
    }
}

byte dat[5];
byte read_data(){
    byte data;
    for (int i = 0; i < 8; i++) {
        if (digitalRead(DHpin) == LOW) {
            while (digitalRead(DHpin) == LOW);
            delayMicroseconds((30));
            if (digitalRead(DHpin) == HIGH) data |= (1 << (7 - i));
            while (digitalRead(DHpin) == HIGH);
        }
    }

    return data;
}

void start_test() {
    digitalWrite(DHpin, LOW);
    delay(30);
    digitalWrite(DHpin, HIGH);
    delayMicroseconds(40);
    pinMode(DHpin, INPUT);
    while (digitalRead(DHpin) == HIGH);
    delayMicroseconds(80);

    if (digitalRead(DHpin) == LOW);
    delayMicroseconds(80);

    for (int i = 0; i < 4; i++) {
        dat[i] = read_data();
    }
    pinMode(DHpin, OUTPUT);
    digitalWrite(DHpin, HIGH);
}

void ex_28() {
    start_test();
    Serial.print("current humdity = ");
    Serial.print(dat[0], DEC);
    Serial.print('.');
    Serial.print(dat[1], DEC);
    Serial.print('%');

    Serial.print("current temperature = ");
    Serial.print(dat[2], DEC);
    Serial.print('.');
    Serial.print(dat[3], DEC);
    Serial.print('C');
    delay(1000);
}

void ex_29() {

//    float h = dht.readHumidity();
//    float t = dht.readTemperature();
//    float f = dht.readTemperature(true);

//    if (isnan(h)|| isnan(t)|| isnan(f)){
//        Serial.println("XX");
//        return;
//    }
//
//    Serial.print("current humdity = ");
//    Serial.print(h);
//    Serial.print("%\t");
//
//    Serial.print("current temperature = ");
//    Serial.print(t);
//    Serial.print("C\t");
//    Serial.print(f);
//    Serial.print("F\n");
//    delay(5000);
}

void ex_30() {

    char keyin;

    if (Serial.available()>0){
        digitalWrite(LedPin_13, HIGH);
        keyin = Serial.read();
        if (keyin=='x') while(1);
        else{
            delay(1000);
            digitalWrite(LedPin_13, LOW);
        }
    }

    wdt_reset();
}

volatile int f_wdt = 1,WDT_flag = 1;
int WUP_cnt = 0;
int WDT_cnt = 0;
//ISR(WDT_vect){
//    if (WDT_flag==0) {
//        WDT_flag = 1;
//    } else{
//        Serial.println("WDT overrun!!");
//    }
//    WDT_cnt++;
//}


//ISR(WDT_vect){
//    Serial.println("Timeout , not reboot");
//    digitalWrite(LedPin_13, LOW);
//    flag = 0;
//}

void setupTimer_ex31(){
    //init 暫存器
    TCCR2A = 0;
    TCCR2B = 0;
    TCNT2 = 0;

    //設定CTC 模式
    TCCR2B = TCCR2B | (1 << WGM21);

    //設定預先除頻倍數prescaler與正確的TOP上限值
    TCCR2B = TCCR2B | (1 << CS21);
    OCR2A = 63; //delay 0.001s

    //致能對應的中斷
    TIMSK2 = TIMSK2 | (1<< OCIE2A);

    //============================使用上面的代碼，或下面的都可以====================

//    cli();  // 禁止中斷
//    TCCR2A = bbs(WGM21);  // CTC mode 2; Clear Timer on Compare, see p.158-162
//    TCCR2B = bbs(CS22);  // Prescaler == 64; see p.162 in datasheet
//    ///// 注意 WGM22 在 TCCR2B, 但 WGM21 與 WGM20 在 TCCR2A;
//    ///// mode 由 WGM22, WGM21, WGM20 決定 (see datasheet p.158-162)
//    OCR2A = 24999;  // TOP count for CTC, 與 prescaler 有關
//    TCNT2 = 0;  // counter 歸零
//    TIMSK2 |= bbs(OCIE2A);  // enable CTC for TIMER2_COMPA_vect
//    sei();  // 允許中斷IMER2_COMPA_vect
}


//int timeOut0 = 1000;
//ISR(TIMER2_COMPA_vect){
//    //這邊開始進行 Delay
//    if (micros() >= timeNow0 + timeOut0) {
//        timeNow0 += timeOut0;
//
//        num = random(0, 21);
//        Serial.println(num);
//    }
//}

void ex_31() {

    char keyin;

    if (Serial.available()>0){
        digitalWrite(LedPin_13, HIGH);
        keyin = Serial.read();
        if (keyin=='x'){
            flag = 1;
            while(flag);
        }
        else{
            delay(1000);
            digitalWrite(LedPin_13, LOW);
        }
    }

    asm("WDR");
}

//void enterSleep(){
//    set_sleep_mode(SLEEP_MODE_PWR_SAVE);
//    sleep_enable();
//    sleep_mode();
//
//    sleep_disable();
//    power_all_enable();
//    Serial.println("Wake up:");
//    Serial.println(++num);
//    delay(100);
//}

void enterSleep(){
    Serial.println("Sleepp...");
    delay(100);
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_mode();

//    sleep_disable();
//    power_all_enable();
    Serial.println("Wake up:");
    Serial.println(WUP_cnt++);
    delay(100);
}

void ex_32() {
    if (f_wdt==1){
        digitalWrite(LedPin_13,!digitalRead(LedPin_13));
        f_wdt = 0;
        enterSleep();
    }
}

void ex_33() {
    if (WDT_flag==1){
        WDT_flag = 0;
        if (WDT_cnt % 2){
            enterSleep();
        }
    }

    Serial.println(num++ % 1000);
    delay(100);
}


int pin3PWM(int freq,int dc){
    int i, pre[6] = {8, 32, 64, 128, 256, 1024};
    float TOP;

    pinMode(3, OUTPUT);
    if (dc == 0){
        digitalWrite(3,LOW);
        return 1;
    }
    if (dc==100){
        digitalWrite(3, HIGH);
        return 1;
    }
    for (i = 0; i < 6; i++) {
        TOP = 16000000 / pre[i] / freq / 2;
        if (TOP < 255 && TOP > 0) {
            OCR2A = TOP;
            break;
        }
    }

    switch (i) {
        case 0:
            sbi(TCCR2B,CS21);
            break;
        case 1:
            sbi(TCCR2B,CS21);
            sbi(TCCR2B,CS20);
            break;
        case 2:
            sbi(TCCR2B,CS22);
            break;
        case 3:
            sbi(TCCR2B,CS22);
            sbi(TCCR2B,CS20);
            break;
        case 4:
            sbi(TCCR2B,CS21);
            sbi(TCCR2B,CS22);
            break;
        case 5:
            sbi(TCCR2B,CS21);
            sbi(TCCR2B,CS22);
            sbi(TCCR2B,CS20);
            break;
        default:
            return 0;
    }
    sbi(TCCR2B,WGM22);
    sbi(TCCR2A,WGM20);
    OCR2B = OCR2A * dc/100;
    sbi(TCCR2A,COM2B1);

    return 1;
}


void ex_35() {
//    pin3PWM(31, 5);
    pin3PWM(31, 95);
//    delay(3000);
//    pin3PWM(2000, 90);
//    delay(3000);
}