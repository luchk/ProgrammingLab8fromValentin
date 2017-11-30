//
// Created by Vika on 11/30/17.
//

#ifndef PROGRAMMINGLAB8FROMVALENTIN_FOURIERSERIES_H
#define PROGRAMMINGLAB8FROMVALENTIN_FOURIERSERIES_H

#endif //PROGRAMMINGLAB8FROMVALENTIN_FOURIERSERIES_H


double sumOffurier(double akk, double k,double tt, double bkk)
{
    double w = 6283.1853071795858340919949114322662353515625;
    return (akk * cos(k * w * tt) + bkk * sin(k * w * tt));
}

double multiplex(double x, double y)
{
    return x * y;
}