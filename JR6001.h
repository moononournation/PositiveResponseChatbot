void audio_init()
{
  Serial1.begin(9600);
  Serial1.println("AF:31"); // set volume
  delay(100);
  while (Serial1.available())
  {
    Serial.print((char)Serial1.read());
  }

  pinMode(AUDIO_BUSY_PIN, INPUT);
}

bool audio_busy()
{
  return digitalRead(AUDIO_BUSY_PIN) == HIGH;
}

void audio_play_msg(uint8_t id)
{
  char buffer[16];
  snprintf(buffer, 16, "B7:%02d", id);
  Serial.println(buffer);

  int retry_count = 0;
  while ((!audio_busy()) && (retry_count < 3))
  {
    Serial1.println(buffer);
    // Serial1.println("B7:010203040506070809");
    delay(100);
    while (Serial1.available())
    {
      Serial.print((char)Serial1.read());
    }
    delay(100);
    retry_count++;
  }
}
