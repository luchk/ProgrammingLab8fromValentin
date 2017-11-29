#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int N=200, i, t1=0, numbers = 1000;
    double w, ao, bk, ak, sm, aoo = 0, akk = 0, bkk = 0, smt, k, tt = 0.0, smtt = 0.0;
    double h = 0.005, T = 1e-3;
    double t = 0, s;
    double h2;
    double PI = 3.1415926535897932384626433832795;
    double a[numbers];
    double b[numbers];

    FILE*ffur;
    FILE*ffurr;
    ffur  = fopen("furieLine.txt","wt");
    ffurr = fopen("furieLine2.txt","wt");

//    for (t=0, t1 = 0;t<=0.001;t+=0.001/N, t1++)
    while(t <= 0.001)
    {
        if (t<=0.00025)
        {
            s = 5 * t / 0.00025;
            a[t1] = s;
            b[t1] = t;
            cout << setprecision(10) << t << " " << setprecision(10) << s << endl;
        }
        else if (t>0.00025 && t<=0.0005)
        {
            s = 5 - 5 * (t - 0.00025) / 0.00025;
            a[t1] = s;
            b[t1] = t;
            cout << t << " " << s << endl;
        }
        else if (t>0.0005 && t<= 0.001)
        {
            s = 6 * sin(2 * PI * t / 0.001);
            a[t1] = s;
            b[t1] = t;
            cout << t << " " << s << endl;
        }
        fprintf(ffur,"%.10f\t", t);
        fprintf(ffur,"%.10f\n", s);

        t+=0.001/N;
        t1++;
    }

   // t = 0;
    fclose(ffur);
    h2 = 2*h/T;
    for (i = 0; i < 41; i++)
    {
        ao = a[i];
        aoo = aoo+ao;
    }
    aoo = aoo*h2;
   // printf("%.4f\n", aoo);




    w = (2*PI)/T;
    for (tt = 0.00; tt <= 0.201; tt+=0.005)
    {
        for (k = 1; k <= 10; k++)
        {
            for (i = 0; i < t1; i++)
            {
                ak = a[i]*cos(k*w*b[i]);
                akk+=ak;
                bk = a[i]*sin(k*w*b[i]);
                bkk+=bk;
            }
            akk = akk*h2;
            bkk = bkk*h2;
            smt = (akk*cos(k*w*tt)+bkk*sin(k*w*tt));
            smtt+=smt;
            akk = 0.0;
            bkk = 0.0;
        }
        smtt+= aoo/2;
        printf("%.4f\t", tt);
        fprintf(ffurr,"%f\t", tt);
        printf("%.4f\n", smtt);
        fprintf(ffurr,"%f\n", smtt);

        smtt = 0;
    }
    cout << "t " << t << endl;
    cout << "t1 " << t1 << endl;
    cout << "PI " << PI << endl;

    return 0;
}
