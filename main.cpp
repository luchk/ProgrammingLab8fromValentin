#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include "fourierSeries.h"

using namespace std;

int main()
{
    int N=2000; // кількість поділок еа які поділений мій графік
    int t1=0; // рахує кількість ітераційциклу табулювання
    int numbers = 2010; // розмір масиву для збереження данних
    double bk, ak, akk = 0, bkk = 0, smt, k, tt = 0.0, smtt = 0.0;
    double aoo = 0; // коефіциіент а0 (а нульове)
    double T = 1e-3; // період
    double h = T/N; // дорівнює період поділити на 2000
    double t = 0; // наша вісь Х по якій ми і табулюємо функцію
    double s; // наша вісь У якій ми присвоюємо значення якого набуває наша функція у точці t
    double h2 = 2*h/T; // частинка формули
    double PI = 3.1415926535897932384626433832795; // число пі
    double w = (2*PI)/T; // частинка формул
    double a[numbers]; // зберігаються всі значення змінної s (по осі У)
    double b[numbers]; // зберігаються всі значення змінної t (по осі Х)


    FILE*ffur; // оголошуємо змінні файлу
    FILE*ffurr;
    ffur  = fopen("furieLine.txt","wt"); // створюємо файли
    ffurr = fopen("furieLine2.txt","wt");

//    for (t=0, t1 = 0;t<=0.001;t+=0.001/N, t1++)
    while(t <= 0.001) // цикл який робить табуляцію нашого сигналу
    {
        if (t<=0.00025)
        {
            s = 5 * t / 0.00025;
            a[t1] = s;
            b[t1] = t;
//            cout << setprecision(10) << t << " " << setprecision(10) << s << endl;
        }
        else if (t>0.00025 && t<=0.0005)
        {
            s = 5 - 5 * (t - 0.00025) / 0.00025;
            a[t1] = s;
            b[t1] = t;
//            cout << t << " " << s << endl;
        }
        else if (t>0.0005 && t<= 0.001)
        {
            s = 6 * sin(2 * PI * t / 0.001);
            a[t1] = s;
            b[t1] = t;
//            cout << t << " " << s << endl;
        }
        fprintf(ffur,"%.10f\t", t); // записуємо у файл отримані значення
        fprintf(ffur,"%.10f\n", s);

        t += 0.001/N; // додаємо значень до нашого лічильника
        t1++;
    }

   // t = 0;
    fclose(ffur);
    for (int i = 0; i < numbers; i++)
    {
        aoo = aoo+a[i];
    }
    aoo = multiplex(aoo, h2);
   // printf("%.4f\n", aoo);


    for (tt = 0.00; tt <= 0.001; tt+=0.001/N)
    {
        for (k = 1; k <= 10; k++)
        {
            for (int i = 0; i < t1; i++)
            {
                akk += akate(a, k, b, i);
                bkk += bkate(a, k, b, i);
            }
            akk = multiplex(akk, h2);
            bkk = multiplex(bkk, h2);
            smtt += sumOffurier(akk, k, tt, bkk);
        }
        smtt += aoo / 2;
//        printf("%.10f\t", tt);
        fprintf(ffurr,"%f\t", tt);
//        printf("%.10f\n", smtt);
        fprintf(ffurr,"%f\n", smtt);

    }
    cout << "t " << t << endl;
    cout << "t1 " << t1 << endl;
    cout << "PI " << PI << endl;
//    cout << "PI " << setprecision(10) << PI * 1035*1035 << endl;
//    cout << "PI " << setprecision(10) << 3.14159 * 1035*1035 << endl;
    cout << setprecision(100) << w << endl;

    return 0;
}
