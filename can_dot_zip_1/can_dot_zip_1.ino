#define RPWM 9
#define LPWM 10
#define PWM 11
#define BTN 7

void motor_cw(){
    digitalWrite(LPWM, LOW);
    digitalWrite(RPWM, HIGH);
    analogWrite(PWM, 255); //0-255
    Serial.println("MOTOR RUNS CW");
}
void motor_ccw(){
    digitalWrite(LPWM, HIGH);
    digitalWrite(RPWM, LOW);
    analogWrite(PWM, 255); //0-255
    Serial.println("MOTOR RUNS CCW");
}
void motor_stop(){
    digitalWrite(LPWM, LOW);
    digitalWrite(RPWM, LOW);
    analogWrite(PWM, 0); //0-255
    Serial.println("STOP");
}

void setup(){
    Serial.begin(9600);
    Serial.println("START");
    pinMode (RPWM, OUTPUT);
    pinMode (PWM, OUTPUT);
    pinMode (LPWM, OUTPUT);
    pinMode (BTN, INPUT);
}

void loop(){
    if(digitalRead(BTN) == HIGH){
        motor_cw();   delay(12000); //ออก
        motor_stop(); delay(750);
        motor_ccw();  delay(12000); //เข้า
        motor_stop(); delay(750);
    }
    else{
        motor_ccw();
    }
}
