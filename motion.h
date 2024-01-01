void motion_start(int v)
{
  Serial.println("motion_start");
  analogWrite(MOTOR_PIN1, v); // 0-255, output vary the motor speed
}

void motion_stop()
{
  Serial.println("motion_stop");
  analogWrite(MOTOR_PIN1, 0);
}

void motion_init()
{
  pinMode(MOTOR_PIN1, OUTPUT);
  digitalWrite(MOTOR_PIN1, LOW);
  pinMode(MOTOR_PIN2, OUTPUT);
  digitalWrite(MOTOR_PIN2, LOW);

  motion_start(127);
  delay(1000);
  motion_stop();
}
