#include <bits/stdc++.h>
using namespace std;

// example of tail recursion
template <class T>
void fn(T n)
{
    if (n > 0)
    {
        cout << n << " ";
        fn(n - 1);
    }
}

// example of head recursion
template <class T>
void fn1(T n)
{
    if (n > 0)
    {
        fn1(n - 1);
        cout << n << " ";
    }
}

template <class T>
T fn2(T n)
{
    if (n > 0)
    {
        return fn2(n - 1) + n;
    }
}

// example of static and global recursion
template <class T>
// T x=0;
T fn3(T n)
{
    static T x = 0;
    if (n > 0)
    {
        x++;
        return fn3(n - 1) + x;
    }
}

// example of tree recursion
template <class T>
void fn4(T n)
{
    if (n > 0)
    {
        cout << n << " ";
        fn4(n - 1);
        fn4(n - 1);
    }
}

// example of indirect recursion
template <class T>
void fn6(T);
template <class T>
void fn5(T n)
{
    if (n > 0)
    {
        cout << n << endl;
        fn6(n - 1);
    }
}
template <class T>
void fn6(T n)
{
    if (n > 0)
    {
        cout << n << endl;
        fn5(n / 2);
    }
}

// example of nested recursion
template <class T>
T fn7(T n)
{
    if (n > 100)
    {
        return n - 10;
    }
    else
    {
        fn7(fn7(n + 11));
    }
}

// example of sum of first n natural no
template <class T>   
T sum(T n)
{
    if (n == 0)
        return 0;
    return n + sum(n - 1);
}

// example of exponential
template <class T>
T pow(T m, T n)
{
    if (n == 0)
        return 1;
    return m * pow(m, n - 1);
}
// same code with less call
template <class T>
T pow2(T m, T n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return pow2(m * m, n / 2);
    }
    else
    {
        return pow2(m * m, (n - 1) / 2) * m;
    }
}
// taylor series using recursion
template <class T>
double expo(T x, int n)
{
    static double p = 1, f = 1;
    double r;
    if (n == 0)
        return 1;
    else
    {
        r = expo(x, n - 1);
        p = p * x;
        f = f * n;
        return r + static_cast<double>(p) / f;
    }
}

// another method
template <class T>
double expo2(T x, int n)
{
    static double s = 1;
    if (n == 0)
    {
        return s;
    }
    else
    {
        s = 1 + x / n * s;
        return expo2(x, n - 1);
    }
}
// fibonachi
int arr[10];
int fibo(int n)
{
    if (n <= 1)
    {
        arr[n] = n;
        return n;
    }
    if (arr[n - 2] == -1)
    {
        arr[n - 2] = fibo(n - 2);
    }
    if (arr[n - 1] == -1)
    {
        arr[n - 1] = fibo(n - 1);
    }
    return fibo(n - 1) + fibo(n - 2);
}
// ncr

int ncr(int n, int r)
{
    if (r == 0 || n == r)
    {
        return 1;
    }
    return ncr(n - 1, r - 1) + ncr(n - 1, r);
}
// tower of hanoi
void toh(int n, int a, int b, int c)
{
    if (n > 0)
    {
        toh(n - 1, a, c, b);
        cout << "( " << a << " , " << c << " )" << endl;
        ;
        toh(n - 1, b, a, c);
    }
}
int main()
{
    int n = 3;
    fn<double>(3.5);

    // int x = 3;
    // fn1<int>(x);

    // int x = 5;
    // int y=fn2<int>(x);
    // cout<<y;

    // int x = 5;
    // int y=fn3<int>(x);
    // cout<<y;

    // int n = 3;
    // fn4<int>(3);

    // int n = 20;
    // fn5<int>(n);

    // int x = 95;
    // int y=fn7<int>(x);
    // cout<<y;

    // int x = 5;
    // int y=sum<int>(x);
    // cout<<y;

    // int x = 5;
    // int y=pow<int>(2,4);
    // cout<<y;

    // int x = 5;
    // int y=pow2<int>(2,4);
    // cout<<y;

    // int x = 5;
    // double y=expo<int>(2,4);
    // cout<<y;

    // int x = 5;
    // double y=expo2<int>(2,4);
    // cout<<y;

    // for (int i = 0; i < 10; i++)
    // {
    //      arr[i]=-1;
    // }
    // int x=5;
    // int y=fibo(x);
    // cout<<y;

    // int n=5,c=2;
    // int t=ncr(n,c);
    // cout<<t;

    // int n=3;
    // toh(n,1,2,3);

    return 0;
}
