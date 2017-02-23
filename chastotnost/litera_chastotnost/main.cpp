#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stdio.h>
#include <windows.h>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream f_in("text.txt");
    if (!f_in)
    {
        cout << "Error!" << endl;
        return 0;
    }

    /*char str[SHRT_MAX];
    while (!f_in.eof()) f_in.getline(str, SHRT_MAX, '\0');

    int rus_alph = 32; double str_len = strlen(str);
    int kolvo[BUFSIZ]={0};
    double per_simbol[rus_alph+1]={0};

    for(int i=0; i<str_len; i++)
        kolvo[(int)(unsigned char)str[i]]++;
        */
        int rus_alph = 32;
    int kolvo[BUFSIZ]={0};
    double per_simbol[rus_alph+1]={0};
    unsigned char c;
    double str_len = 0;
    while (!f_in.eof())
    {
        c = f_in.get();
        if (((int)c == 184) || ((int)c >=192 && (int)c <=255))
        {
            str_len++;
            kolvo[(int)c]++;
        }

    }

    ofstream f_out("result.txt");

    int h=0;
    for(int i=224; i<=255; i++)
    {
        per_simbol[h] = (kolvo[i] + kolvo[i-rus_alph])/str_len;
        f_out << (char)i << '\t' << setprecision(4) << per_simbol[h] << endl;
        h++;
    }

    per_simbol[rus_alph] = kolvo[184]/str_len;
    f_out << (char)184 << '\t' << setprecision(4) << per_simbol[rus_alph] << endl;

    f_in.close();
    f_out.close();

    return 0;
}
