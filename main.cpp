#include "mbed.h"

PwmOut mypwm(PWM_OUT);

AnalogIn analog_value(A0);

int main()
{
  float meas_r;
  float meas_v;

  mypwm.period_ms(10);
  mypwm.pulsewidth_ms(1);

  while(1)
  {
    meas_r = analog_value.read();

    mypwm.write(meas_r);

    printf("pwm set to %.2f %%\n", mypwm.read() * 100);

    wait(1.0);
  }
}
