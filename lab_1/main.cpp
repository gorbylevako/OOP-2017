#include <iostream>
#include <cstdlib>

using namespace std;

class A
{
    private:
        int a, b;

    public:
        void set_a_b(int a_in, int b_in)
        {
            a = a_in;
            b = b_in;
        }
        int c(int p)
        {
            switch(p)
            {
            case 1:
                {
                    return ++a; break;
                }
            case 2:
                {
                    return ++b; break;
                }
            case 3:
                {
                    return (a*=b); break;
                }
            case 4:
                {
                    return (a-b); break;
                }
            default:
                {
                    cout << "¬ведЄнное выражение не задано над пол€ми a и b." << endl; break;
                }
            }
            return 0;
        }
};

class Program
{
    public:
        void getA()
        {
            A classA;
            int a, b;
            cout << "a = "; cin >> a;
            cout << "b = "; cin >> b;

            classA.set_a_b(a, b);

            cout << "1) a++\n2) b++\n3) a*=b\n4) a-b" << endl;
            cout << endl;
            int p; cin >> p;
            cout << "\nc = " << classA.c(p) << endl;
        }


};

int main()
{
    setlocale(LC_ALL, "Russian");
    int h;
    do
    {
        system("cls");
        Program lab;
        lab.getA();
        cout << "\n\n’отите продолжить?  (да - 1/ нет - 0)\t";
        cin >> h;
    } while (h == 1);

    return 0;
}
