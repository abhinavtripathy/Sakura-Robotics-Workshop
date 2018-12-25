#include <STEMDu.h>
#include <Servo.h>

STEMDu _STEMDU_robot = STEMDu();
int _ABVAR_1_count = 0 ;
int _ABVAR_2_starttime = 0 ;
Servo servo_pin_5;
Servo servo_pin_6;

void setup()
{
  servo_pin_5.attach(5);
  servo_pin_6.attach(6);
}

void loop()
{
  if (( ( _STEMDU_robot.readSound() ) > ( 50 ) ))
  {
    if (( ( _ABVAR_1_count ) == ( 0 ) ))
    {
      _ABVAR_2_starttime = millis() ;
    }
    while ( ( ( _STEMDU_robot.readSound() ) > ( 50 ) ) )
    {
    }

    _ABVAR_1_count = ( _ABVAR_1_count + 1 ) ;
  }
  if (( ( ( millis() - _ABVAR_2_starttime ) ) > ( 2000 ) ))
  {
    if (( ( _ABVAR_1_count ) == ( 1 ) ))
    {
      servo_pin_5.write( 180 );
      delay( 100 );
      servo_pin_5.write( 90 );
    }
    if (( ( _ABVAR_1_count ) == ( 2 ) ))
    {
      servo_pin_6.write( 180 );
      delay( 100 );
      servo_pin_6.write( 90 );
    }
    if (( ( _ABVAR_1_count ) == ( 3 ) ))
    {
      servo_pin_6.write( 180 );
      servo_pin_5.write( 180 );
      delay( 100 );
      servo_pin_6.write( 90 );
      servo_pin_5.write( 90 );
    }
    _ABVAR_1_count = 0 ;
  }
}
