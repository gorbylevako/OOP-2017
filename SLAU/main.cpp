#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void write_result(double *x, int n)
{
    ofstream f_out("xout.txt");
    for(int i=0; i<n; i++)
        f_out << x[i] << " ";
    f_out.close();
}

bool check_result(double **a, double *b, double *x)
{
    ifstream f_ain("ain.txt");
    ifstream f_bin("bin.txt");

    int n;
    f_ain >> n;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
                f_ain >> a[i][j];
    for(int i=0; i<n; i++)
            f_bin >> b[i];
    f_ain.close();
    f_bin.close();

    double *C = new double [n];

    for(int j=0; j<n; j++)
        C[j] = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            C[i]+=a[i][j]*x[j];

        cout << C[i] << " ";
    }

    for(int i=0; i<n; i++)
        if (b[i] != C[i])
        {
            cout << "Wrong answer!"; return false;
        }
    delete [] C;

    return true;
}

void gauss(double **a, double *b, double *x, int n)
{
    int i,j,k;

    //прямой ход
    for(i=0; i<n-1; i++)
        for(j=i+1; j<n; j++)
        {
            double p = a[i][i]/a[j][i];
            for(k=0; k<=n; k++)
                a[j][k] = a[j][k]*p - a[i][k];
        }

    //обратный ход
    x[n-1] = a[n-1][n]/a[n-1][n-1];
    for(i=n-2; i>=0; i--)
    {
        double summ=0;
        for(j=i+1; j<n && a[i][i]!=0; j++)
            summ += a[i][j]*x[j];
        x[i] = (a[i][n]-summ)/a[i][i];
    }

    /*
    double p = 0;
    for (int k=0; k<n-1; k++)
    {
        for (int i=k+1; i<n; i++)
        {
            p = a[i][k]/a[k][k];
            for (int j=k; j<n; j++)
            {
                a[i][j] -= p*a[k][j];
            }
            b[i] -= p*b[k];
        }
    }
    for(int i = 0; i<n; i++)
        x[i]=b[i];

    for (int i=n-1;i>=0;i--)
    {
        for (int j=i+1;j<n;j++)
                x[i]-=a[i][j]*x[j];
        x[i] /= a[i][i];
    }
    */
}

int main()
{
    ifstream f_ain("ain.txt");
    ifstream f_bin("bin.txt");

    ofstream f_out("xout.txt");
    f_out.close();

    if(!f_ain && !f_bin) cout << "Error!\n";
    else
    {
        int n;

        f_ain >> n;

        double **a = new double *[n];
        for(int i=0; i<n; i++)
            a[i] = new double [n+1];

        double *b = new double [n];

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                f_ain >> a[i][j];

        for(int i=0; i<n; i++)
        {
            f_bin >> b[i];
            a[i][n] = b[i];
        }


        double *x = new double [n];

        gauss(a, b, x, n);
        if (check_result(a, b, x)) write_result(x, n);
        else cout << "Wrong answer!";

        for(int i=0; i<n; i++)
            delete a[i];
        delete [] a;

        delete [] b;
        delete [] x;
    }

    f_ain.close();
    f_bin.close();

    return 0;
}
