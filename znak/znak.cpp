//program wypisuje pierwszy unikatowy znak w podanym ciągu, zwracając przy tym uwagę na wielkość liter, co można w prosty sposób zmienić, jak przy palindromie
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

char unique(char seq[], int size)
{
    char* clipboard = new char[size];
    int a = 0;
    int b = 0;
    bool next = false;
    for (int i = 0; i < size; i++)
    {
        for (int c = 0; c < a; c++)
        {
            if (seq[i] == clipboard[c])
            {
                next = true;
                break;
            }
        }
        if (next == true)
        {
            next = false;
            continue;
        }
        if (i == size - 1)
            return '-';
        for (int j = i + 1; j < size; j++)
        {
            if (seq[i] == seq[j])
            {
                clipboard[a] = seq[j];
                a++;
                break;
            }
        }
        if (a > b)
        {
            b = a;
        }
        else
            return seq[i];
    }
}

int main()
{
    cin.exceptions(ios::failbit | ios::badbit);
    string seq;
    while (true)
    {
        cout << "type in string! (end closes the program)\n";
        try
        {
            getline(cin, seq);
        }
        catch (exception&)
        {
            cout << "Size of string exceeded, type in different value" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (seq == "end")
        {
            cout << "End detected, closing program. Goodbye!";
            break;
        }
        char* chars = new char[seq.size() + 1];
        strcpy(chars, seq.c_str());

        cout << "First unique sign:" << unique(chars, seq.size() + 1) << endl;;

        delete[] chars;
    }
}