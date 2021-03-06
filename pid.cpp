#include "pid.h"

#define MAX_CV 100
#define MIN_CV 0 //np dla drona min 0, dla trytona min -100 (windup)

PID::PID()
{
    Ti=1000;
    Td=0;
    kp=0;
    e=0;
    last_e=0;
    dt=0.1;//s

}


void PID::Compute (double pv, bool PD_on_big_e){

    e=SP-pv;
    P=kp*e;
    I=(kp/Ti)*e_sum;
    D=kp*Td*(e-last_e)/dt;

    if(PD_on_big_e==1){
        I=0;
        e_sum=0;
    }

    CV=P+I+D;

    if (CV>=MAX_CV){
        CV=MAX_CV;
    }

    if (CV<=MIN_CV){
        CV=MIN_CV;
    }

}

void PID::Tuning(double kp, double Ti, double Td){

    kp=this->kp;
    Ti=this->Ti;
    Td=this->Td;

}

void PID::Reset(){

   this->kp=0;
   this->Ti=1000;
   this->Td=0;

}
