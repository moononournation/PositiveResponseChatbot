/*
    VoiceRecognition.ino
        Demonstrate the voice recognition technology.

    This sketch supports the following board types:
        Arduino Nano RP2040 Connect
            https://store.arduino.cc/products/arduino-nano-rp2040-connect
        Arduino Nano 33 BLE Sense
            https://store.arduino.cc/products/arduino-nano-33-ble-sense
        Arduino Portenta H7
            https://store.arduino.cc/products/portenta-h7

    To run the free demo with a pre-defined keyword set:
        1. Verify & upload the GetSerialNumber.ino sketch to get the board's serial number and print it on the console output.
        2. Go to the DSpotter Free Demo License Page:
            https://tool.cyberon.com.tw/ArduinoDSpotterAuth/FDMain.php
        3. Enter the board's serial number and click Submit. The license data of the board will show on the webpage.
        4. Copy & paste the license data into the CybLicense.h file under your sketch folder.
        5. Verify & upload the sketch to the board.
        6. The voice recognition is ready to go.

    To try out a custom keyword set:
        Users can create their own custom keyword sets through the DSpotter Model Configuration Page:
            https://tool.cyberon.com.tw/ArduinoDSpotterAuth/CTMain.php
        and obtain the Custom Trial Model & the corresponding Custom Trial License to test on the board.
            1. Go to the DSpotter Model Configuration Page.
            2. Select the board type of your board, enter your email address and enter the board's serial number.
            3. Read & agree to the end-user license agreement, then click Next.
            4. You can choose to create a new model set or import model from an existing .dsproj file.
            5. To create a new model, select the desired language for the model and click Create.
            6. You can set the trigger & command keyword simply by text input.
                    The keyword ID will be used in the sketch to identify the speech recognition results.
            7. After completing trigger keyword configuration, click Next and proceed to command keyword configuration.
            8. If all the configurations in the review project page are correct, click Confirm.
                    The Custom Trial Model, the corresponding Custom Trial License, and the .dsproj file will be sent to your email.
            9. For example, you would receive files like:
                    Custom Trial Model     Model_xxxxxxxxxxx.h
                    Custom Trial License   CybLicense_xxxxxxxxxxx.h
                    DSpotter Project File  Model_xxxxxxxxx_Arduino_[board type].dsproj
               xxxxxxxxxxx is a random tamp number use to differ each download.
               Copy & paste Model_xxxxxxxxxxx.h and CybLicense_xxxxxxxxxxx.h to your sketch folder.
            10. Modify the following lines in the sketch:
                    #include "CybLicense.h" ----> #include "CybLicense_xxxxxxxxxxx.h"
                    #include "Model_L1.h" ----> #include "Model_xxxxxxxxxxx.h"
            11. Verify & upload the sketch to the board.
            12. The voice recognition with your custom keyword set is ready to go.
        Please note that the Custom Trial Model and the Custom Trial License are free to use with some limitations:
            1. Recognize 50 times each reboot. Once the number of recognitions is reached, the model will stop until the next reboot.
            2. There is a 20-second delay between entering the trigger mode and starting to recognize the trigger mode keywords.

    To unlock the limitations of the Custom Trial version:
        Users can remove the limitations of the Custom Trial version by upgrading to the Custom Formal version
        through the DSpotter License Activation Page:
            https://tool.cyberon.com.tw/ArduinoDSpotterAuth/CFMain.php
        to obtain the Custom Formal Model & the corresponding Custom Formal License for the final product.
            1. Purchase a valid voucher code from Arduino Online Store:
                    https://store.arduino.cc/speech-recognition-engine
            2. Go to the DSpotter License Activation Page.
            3. Select the board type of your board, then enter your email address, the board's serial number, and the voucher code you just purchased.
            4. Import the .dsproj file you received with your tested Custom Trial Model.
            5. Read & agree to the end-user license agreement, then click Next.
            6. If all the configurations in the review project page are correct, click Confirm.
                    The Custom Formal Model, the corresponding Custom Formal License will be sent to your email.
            7. For example, you would receive files like:
                    Custom Formal Model     Model_xxxxxxxxxxx.h
                    Custom Formal License   CybLicense_xxxxxxxxxxx.h
               xxxxxxxxxxx is a random tamp number use to differ each download.
               Please keep these data properly.
               Copy & paste Model_xxxxxxxxxxx.h and CybLicense_xxxxxxxxxxx.h to your sketch folder.
            8. Modify the following lines in the sketch:
                    #include "CybLicense.h" ----> #include "CybLicense_xxxxxxxxxxx.h"
                    #include "Model_L1.h" ----> #include "Model_xxxxxxxxxxx.h"
            9. Verify & upload the sketch to the board.
            10.The voice recognition for the custom keyword set is ready and without any limitation.

    16 Feb 2023 by Cyberon Corporation.
    https://www.cyberon.com.tw/index.php?lang=en
*/
#include <Arduino.h>

#define AUDIO_BUSY_PIN 3
#define MOTOR_PIN1 17
#define MOTOR_PIN2 16
#include "JR6001.h" // MP3 audio module
#include "motion.h"
#include "responseMap.h"

#include <DSpotterSDK_MakerHL.h>
#include <LED_Control.h>

// The DSpotter License Data.
// #include "CybLicense.h"
#include "CybLicense_1703081662.h"
#define DSPOTTER_LICENSE g_lpdwLicense

// The DSpotter Keyword Model Data.
// #include "Model_L0.h"             // The packed level zero model file.
#include "Model_1703081662.h"
#define DSPOTTER_MODEL g_lpdwModel

// The VR engine object. Only can exist one, otherwise not worked.
static DSpotterSDKHL g_oDSpotterSDKHL;

// Callback function for VR engine
void VRCallback(int nFlag, int nID, int nScore, int nSG, int nEnergy)
{
  if (nFlag == DSpotterSDKHL::InitSuccess)
  {
    // ToDo
  }
  else if (nFlag == DSpotterSDKHL::GetResult)
  {
    /*
      When getting an recognition result,
      the following index and scores are also return to the VRCallback function:
        nID        The result command id
        nScore     nScore is used to evaluate how good or bad the result is.
                   The higher the score, the more similar the voice and the result command are.
        nSG        nSG is the gap between the voice and non-command (Silence/Garbage) models.
                   The higher the score, the less similar the voice and non-command (Silence/Garbage) models are.
        nEnergy    nEnergy is the voice energy level.
                   The higher the score, the louder the voice.
    */
    // print input values
    Serial.print("DSpotterSDKHL::GetResult nFlag: ");
    Serial.print(nFlag);
    Serial.print(", nID: ");
    Serial.print(nID);
    Serial.print(", nScore: ");
    Serial.print(nScore);
    Serial.print(", nSG: ");
    Serial.print(nSG);
    Serial.print(", nEnergy: ");
    Serial.println(nEnergy);

    if (nID == 100) // Trigger
    {
      // Response Trigger with a short motion
      motion_start(255);
      delay(200);
      motion_stop();
    }
    else if (nID >= 10000) // Command
    {
      motion_start(127);

      responseData d = responseMap[nID - 10000]; // map responseData
      audio_play_msg(d.ids[random(0, d.count)]); // random response from response message list

      while (audio_busy())
      {
        delay(200);
      }

      motion_stop();
    }
  }
  else if (nFlag == DSpotterSDKHL::ChangeStage)
  {
    switch (nID)
    {
    case DSpotterSDKHL::TriggerStage:
      LED_RGB_Off();
      LED_BUILTIN_Off();
      break;
    case DSpotterSDKHL::CommandStage:
      LED_BUILTIN_On();
      break;
    default:
      break;
    }
  }
  else if (nFlag == DSpotterSDKHL::GetError)
  {
    if (nID == DSpotterSDKHL::LicenseFailed)
    {
      Serial.print("DSpotter license failed! The serial number of your device is ");
      Serial.println(DSpotterSDKHL::GetSerialNumber());
    }
    g_oDSpotterSDKHL.Release();
    while (1)
      ; // hang loop
  }
  else if (nFlag == DSpotterSDKHL::LostRecordFrame)
  {
    // ToDo
  }
}

void setup()
{
  // Init LED control
  LED_Init_All();

  // Init Serial output for show debug info
  Serial.begin(9600);
  // while(!Serial);
  DSpotterSDKHL::ShowDebugInfo(true);

  // Init VR engine & Audio
  if (g_oDSpotterSDKHL.Init(DSPOTTER_LICENSE, sizeof(DSPOTTER_LICENSE), DSPOTTER_MODEL, VRCallback) != DSpotterSDKHL::Success)
    return;

  motion_init();
  audio_init();
}

void loop()
{
  // Do VR
  g_oDSpotterSDKHL.DoVR();
}
