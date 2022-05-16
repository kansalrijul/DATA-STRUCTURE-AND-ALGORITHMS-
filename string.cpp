#include <bits/stdc++.h>
using namespace std;

class String
{
    string s;

public:
    void read()
    {
        cout << "enter string ";
        getline(cin, s);
    }
    void display()
    {
        cout << s;
    }
    int len();
    void change_case();
    int counting_words();
    int validation();
    void reverse();
    void comparing(string);
    int anagram(string);
    void duplicate();
};

int String ::len()
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
    }
    return i;
}

void String ::change_case()
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
        {
            s[i] = s[i] + 32;
        }
        else if (s[i] >= 97 && s[i] <= 122)
        {
            s[i] = s[i] - 32;
        }
    }
}

int String ::counting_words()
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] = ' ' && s[i - 1] != ' ')
            count++;
    }
    return count + 1;
}
int String ::validation()
{
    int flag = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (!(s[i] >= 65 && s[i] <= 90) && !(s[i] >= 97 && s[i] <= 122) && !(s[i] >= 48 && s[i] <= 57))
        {
            return 0;
        }
    }
    return 1;
}

void String ::reverse()
{
    string s1;
    int y = len();
    for (int i = 0; i < y; i++)
    {
        s1[i] = s[y - 1 - i];
    }
    s1[y] = '\0';
    for (int i = 0; i < y; i++)
    {
        s[i] = s1[i];
    }
}
void String ::comparing(string ss)
{
    int i, j;
    for (i = 0, j = 0; s[i] != '\0' && ss[i] != '\0'; i++, j++)
    {
        if (s[i] != ss[j])
            break;
    }
    if (s[i] > ss[j])
        cout << "s is greater then ss";
    else if (s[i] < ss[j])
        cout << "ss ig greater then s";
    else
        cout << "both are equal";
}
int String ::anagram(string ss)
{
    if (s.length() == ss.length())
    {
        int hash[26]{0};
        for (int i = 0; i < s.length(); i++)
        {
            hash[s[i] - 97]++;
        }

        for (int i = 0; i < ss.length(); i++)
        {
            hash[ss[i] - 97]--;
        }
        int flag = 0;
        for (int i = 0; i < 26; i++)
        {
            if (hash[i] != 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            return 0;
        else if (flag == 1)
            return -1;
    }
    else
        return -1;
}
void String ::duplicate()
{
    int hash[26]{0};
    for (int i = 0; i < s.length(); i++)
    {
        hash[s[i] - 97]++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (hash[i] > 1)
        {
            cout << hash[i] << " ";
            printf("%c", i + 97);
            cout << endl;
        }
    }
}

int main()
{
    class String s1;
    s1.read();
    return 0;
}
