//Program sprawdza czy znaki podane przez użytkownika w stringu są literami, jeżeli nie, prosi o ponowne podanie łańcucha znaków. Wszelkie wielkie litery są sprowadzanie do postaci małych liter w przypadku ich wystąpienia
//Znaki unikatowe dla różnych języków również są odrzucane przez program
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;
bool check(char palin[], int size)
{
    int len = 0;
    for (int i = 0; i < size; i++)
    {
        if (palin[i] == ' ')
        {
            int x = i - 1;
            for (int a = i - len; a <= x; a++)
            {
                if (::tolower(palin[a]) != ::tolower(palin[x]))
                {
                    return false;
                }
                else
                    x--;
            }
            len = 0;
            continue;
        }
        else if (i == size - 1)
        {
            for (int a = i - len; a <= i; a++)
            {
                if (::tolower(palin[a]) != ::tolower(palin[i - 1]))
                {
                    return false;
                }
                else
                    i--;

                return true;
            }
        }
        len++;
    }
    return false;
}

int main()
{
    cout << "Type in value to string! (end closes the program)\n";
    cin.exceptions(ios::failbit | ios::badbit);
    bool chck = true;
    string pal;
    while (true)
    {
        try
        {
        getline(cin, pal);
        }
        catch (exception &)
        {
            cout << "Size of string exceeded, type in different value" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        for (char ch : pal)
            if (!isalpha(ch))
            {
                if (isblank(ch))
                {
                    continue;
                }
                else
                    chck = false;
            }
        if (chck == false)
        {
            cout << "Incorrect char detected, provide different string value\n";
            chck = true;
            continue;
        }
        else if (pal == "end")
        {
            cout << "End detected, closing program. Goodbye!\n";
            break;
        }
        char* palindrom = new char[pal.size() + 1];
        strcpy(palindrom, pal.c_str());
        if (check(palindrom, pal.size() + 1) == true)
            cout << "Given setence is made out of palindroms\n" << endl;
        else
            cout << "Given setence isn't made out of palindroms\n" << endl;

        delete[] palindrom;
    }
}