#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <limits.h>
#include <algorithm>

using namespace std;

int main()
{
    vector <int> arr;
    cin.exceptions(ios::failbit | ios::badbit);
    cout << "Type a value! (typing in end causes loop to break)\n";
    string n;
    int con = 0;
    bool check = true;


    while (true)
    {
        cin >> n;
        if (n == "end")
            break;
        for (char ch : n)
            if (!isdigit(ch)) check = false;
        if (check == false)
        {
            cout << "A char being non-numerical value detected, type different value" << endl;
            check = true;
            continue;
        }
        try
        {
            con = stoi(n);
            arr.push_back(con);
        }
        catch (exception&)
        {
            cout << "Size of int exceeded, type in different value" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    cout << "End detected, broke up of loop. User's array:" << endl;
    vector<int>::iterator it_arr = arr.begin();
    for (; it_arr != arr.end(); it_arr++)
        cout << *it_arr << " ";
    cout << "\n";
    sort(arr.begin(), arr.end());
    cout << "Missing values:" << endl;
    for (int y = 1; y < arr.size(); y++)
    {
        if (arr[y] - arr[y - 1] > 1)
        {
            int z = y;
            for (int x = arr[y - 1] + 1; x < arr[y]; x++)
            {
                cout << x << endl;
                arr.insert(arr.begin() + z, x);
                z++;
            }
        }
    }
    cout << "Array after filling with missing numbers:" << endl;
    it_arr = arr.begin();
    for (; it_arr != arr.end(); it_arr++)
        cout << *it_arr << " ";
}