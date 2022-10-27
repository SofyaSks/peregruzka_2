#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <conio.h>

using namespace std;
void menu();
void hw();

class Drob
{
private:
    int ch = 0;
    int zn = 1;
public:
    void Set_drob(int _num1, int _num2)
    {
        ch = _num1;
        zn = _num2;
    }
    void Set_ch(int _num1)
    {

        ch = _num1;

    }
    void Set_zn(int _num2)
    {
        if (_num2 != 0)
        {
            zn = _num2;
        }
        else
        {
            cout << "Error!" << endl;
        }

    }

    Drob()
    {
        ch = 0;
        zn = 1;
    }
    Drob(int _num1, int _num2)
    {
        ch = _num1;
        zn = _num2;
    }

    int Get_ch()
    {
        return ch;
    }
    int Get_zn()
    {
        return zn;
    }
    double Get_res()
    {
        return ch / zn;
    }
    void Print_drob()
    {
        int t = 0;
        if (ch > zn)
        {
            while (ch > zn)
            {
                t++;
                ch -= zn;
            }
            if (ch == zn)
            {
                t++;
                cout << t;
            }
            else
            {
                cout << t << "." << ch << "/" << zn << endl;
            }
        }
        else if (ch == zn)
        {
            t++;
            cout << t;
        }
        else
        {
            cout << ch << "/" << zn << endl;
        }

    }

    // нельзя перегрузить \  &  .
    Drob operator /(Drob n)
    {
        Drob tmp3;
        tmp3.ch = ch * n.zn;
        tmp3.zn = zn * n.ch;
        return tmp3;
    }

    void operator % (Drob n)
    {
        double res = (double)ch / zn;
        cout << res * 100 << " %" << endl;
        res = (double)n.ch / n.zn;
        cout << res * 100 << " %" << endl;
    }
    Drob operator + (Drob n)
    {
        Drob tmp3;
        if (zn == n.zn)
        {
            tmp3.ch = ch + n.ch;
            tmp3.zn = zn;
        }
        else
        {
            tmp3.ch = ch * n.zn + n.ch * zn;
            tmp3.zn = zn * n.zn;
        }
        return tmp3;
    }
    Drob operator - (Drob n)
    {
        Drob tmp3;
        if (zn == n.zn)
        {
            tmp3.ch = ch - n.ch;
            tmp3.zn = zn;
        }
        else
        {
            tmp3.ch = ch * n.zn - n.ch * zn;
            tmp3.zn = zn * n.zn;
        }
        return tmp3;
    }
    Drob operator * (Drob n)
    {
        Drob tmp3;
        if (zn == n.zn)
        {
            tmp3.ch = ch * n.ch;
            tmp3.zn = zn;
        }
        else
        {
            tmp3.ch = ch * n.ch;
            tmp3.zn = zn * n.zn;
        }
        return tmp3;
    }
    Drob operator * (int n)
    {
        ch *= n;
        zn = zn;
        return *this;
    }
    void operator ,(Drob n)
    {
        double res = (double)ch / zn;
        cout << fixed << setprecision(2) << res << endl;
        res = (double)n.ch / n.zn;
        cout << fixed << setprecision(2) << res << endl;
    }
    //
    Drob operator ++()
    {
        ch += zn;
        zn = zn;
        return *this;
    }
    Drob operator ++(int n)
    {
        ch += zn;
        zn = zn;
        return *this;
    }
    Drob operator --()
    {
        ch -= zn;
        zn = zn;
        return *this;
    }
    Drob operator --(int n)
    {
        ch -= zn;
        zn = zn;
        return *this;
    }

    //
    bool operator >(Drob n)
    {
        cout << (double)ch / zn << " > " << (double)n.ch / n.zn << endl;
        return (double)ch / zn > n.ch / n.zn;
    }
    bool operator <(Drob n)
    {
        cout << (double)ch / zn << " < " << (double)n.ch / n.zn << endl;
        return (double)ch / zn < n.ch / n.zn;
    }
    bool operator ==(Drob n)
    {
        cout << (double)ch / zn << " == " << (double)n.ch / n.zn << endl;
        return (double)ch / zn == n.ch / n.zn;
    }
    bool operator !=(Drob n)
    {
        cout << (double)ch / zn << " != " << (double)n.ch / n.zn << endl;
        return (double)ch / zn != n.ch / n.zn;
    }

    void pr_2(bool n)
    {
        if (n)
        {
            cout << "True" << endl;
        }
        else
        {
            cout << "Faulse" << endl;
        }
    }
    void Print_drob2()
    {
        cout << ch << "/" << zn << endl;
    }

    friend ostream& operator << (ostream& os, Drob& d); // переопределяем cout <<
    friend istream& operator >> (istream& is, Drob& d); // cin


};

void main()
{
    srand(time(NULL));


    Drob res;
    Drob d1(2, 3);
    Drob d2(3, 5);

    //cout << d2;

    cin >> res;
    cout << res;
}

ostream& operator<<(ostream& os, Drob& d) // cout
{
    os << d.ch << " / " << d.zn;
    return os;
}

istream& operator>>(istream& is, Drob& d) // cin
{
    cout << "Enter ch: ";
    is >> d.ch;
    cout << "Enter z: ";
    is >> d.zn;
    return is;
}
