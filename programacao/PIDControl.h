#ifndef PIDCONTROL_H
#define PIDCONTROL_H

void setupPIDControl(double kpp, double kip, double kdp);
double getPIDControl(int position);

#endif
