#define d13 13 //R_EN
#define d12 12 //L_EN
#define d11_L 11 //RPWM
#define d10_L 10 //LPWM

void setup(){
    pinMode(d13_L, OUTPUT);
    pinMode(d12_L, OUTPUT);
    pinMode(d11_L, OUTPUT);
    pinMode(d10_L, OUTPUT);
    motor_stop();
}
void loop(){
    motor_stop();   delay(1000);
    motor_cw();     delay(1000);
    motor_stop();   delay(1000);
    motor_ccw();    delay(1000);
}
void motor_cw(){
    analogWrite(d13, 50); //0-255
    digitalWrite(d11_L, HIGH);
    digitalWrite(d10_L, LOW);
}
void motor_ccw(){
    analogWrite(d13, 50);
    digitalWrite(d11_L, HIGH);
    digitalWrite(d10_L, LOW);
}
void motor_stop(){
    analogWrite(d13, 50);
    digitalWrite(d11_L, LOW);
    digitalWrite(d10_L, LOW);
}