#ifndef PID_H
#define PID_H


class PID
{
public:

    PID();
    void Compute(double pv);
    void Tuning(double kp, double Ti, double Td);
    void Reset();


private:

   double kp;
   double Ti;
   double Td;
   double dt;

   double SP;
   double e;
   double last_e;
   double e_sum;
   double CV;

   double P;
   double I;
   double D;




};

#endif // PID_H
