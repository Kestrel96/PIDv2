#ifndef PID_H
#define PID_H


class PID
{
public:

    PID();
    void Compute(double pv, bool PD_on_big_e);
    void Tuning(double kp, double Ti, double Td);
    void Reset();

    double CV;

private:

    double kp;
    double Ti;
    double Td;
    double dt;

    double SP;
    double e;
    double last_e;
    long double e_sum;

    double P;
    double I;
    double D;

};

#endif // PID_H
