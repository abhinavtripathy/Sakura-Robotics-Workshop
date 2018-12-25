#include <STEMDu.h>
#include <Servo.h>

int _ABVAR_1_lr = 0 ;
int _ABVAR_2_average = 0 ;
STEMDu _STEMDU_robot = STEMDu();
int _ABVAR_3_count = 0 ;
Servo servo_pin_5;
Servo servo_pin_6;

void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
  servo_pin_5.attach(5);
  servo_pin_6.attach(6);
}

void loop()
{
  Serial.print("Last Rating:");
  Serial.print(" ");
  Serial.print(_ABVAR_1_lr);
  Serial.print(" ");
  Serial.println();
  Serial.print("Average:");
  Serial.print(" ");
  Serial.print(_ABVAR_2_average);
  Serial.print(" ");
  Serial.println();
  if (_STEMDU_robot.readPush())
  {
    if (( ( _STEMDU_robot.readSlider() ) < ( 200 ) ))
    {
      Serial1.print("warui");
      Serial1.println();
      _ABVAR_1_lr = 1 ;
      _ABVAR_3_count = ( _ABVAR_3_count + 1 ) ;
      _ABVAR_2_average = ( ( _ABVAR_2_average + _ABVAR_1_lr ) / _ABVAR_3_count ) ;
    }
    if (( ( ( _STEMDU_robot.readSlider() ) > ( 200 ) ) && ( ( _STEMDU_robot.readSlider() ) < ( 400 ) ) ))
    {
      Serial1.print("heikin");
      Serial1.println();
      _ABVAR_1_lr = 2 ;
      _ABVAR_3_count = ( _ABVAR_3_count + 1 ) ;
      _ABVAR_2_average = ( ( _ABVAR_2_average + _ABVAR_1_lr ) / _ABVAR_3_count ) ;
    }
    if (( ( ( _STEMDU_robot.readSlider() ) > ( 400 ) ) && ( ( _STEMDU_robot.readSlider() ) < ( 600 ) ) ))
    {
      Serial1.print("yoi");
      Serial1.println();
      _ABVAR_1_lr = 3 ;
      _ABVAR_3_count = ( _ABVAR_3_count + 1 ) ;
      _ABVAR_2_average = ( ( _ABVAR_2_average + _ABVAR_1_lr ) / _ABVAR_3_count ) ;
    }
    if (( ( ( _STEMDU_robot.readSlider() ) > ( 600 ) ) && ( ( _STEMDU_robot.readSlider() ) < ( 800 ) ) ))
    {
      Serial1.print("subarashīdesu");
      Serial1.println();
      _ABVAR_1_lr = 4 ;
      _ABVAR_3_count = ( _ABVAR_3_count + 1 ) ;
      _ABVAR_2_average = ( ( _ABVAR_2_average + _ABVAR_1_lr ) / _ABVAR_3_count ) ;
    }
    if (( ( _STEMDU_robot.readSlider() ) > ( 800 ) ))
    {
      Serial1.print("sugureta");
      Serial1.println();
      _ABVAR_1_lr = 5 ;
      _ABVAR_3_count = ( _ABVAR_3_count + 1 ) ;
      _ABVAR_2_average = ( ( _ABVAR_2_average + _ABVAR_1_lr ) / _ABVAR_3_count ) ;
    }
    servo_pin_5.write( 0 );
    servo_pin_6.write( 180 );
    delay( 250 );
    servo_pin_5.write( 180 );
    servo_pin_6.write( 0 );
  }
}
