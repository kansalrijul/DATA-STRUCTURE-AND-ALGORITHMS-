// this array helps us to create an array  in heap so its will not use stack memory
// rijul kansal
// Btech computer science student at vit vellore
#include <bits/stdc++.h>
using namespace std;

template <class t>
void swap(t *x, t *y)
{
    t temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

template <class T = int>
class Array
{

    T *arr;
    int max_size;
    int length;

public:
    ~Array()
    {delete[] arr;}
    void set_size();
    void no_of_element();
    void create();
    void display();
    void append(T);
    void insert(int, T);
    T Delete(int);
    T linear_search(T);
    T linear_search_transpose(T);
    T linear_search_move(T);
    T binary_search(T);
    T binary_search_recursion(T, int, int, T);
    T get(T);
    void set(int, T);
    T max();
    T min();
    T sum();
    double avg();
    void reverse_aux();
    void reverse_swap();
    void insert_sorted(T);
    T is_sorted();
    void rearrange();
};
template <class T>
void Array<T>::no_of_element()
{
    cout << "enter no of element ";
    cin >> length;
    cout << endl;
}
template <class T>
void Array<T>::set_size()
{
    cout << "enter the max size ";
    cin >> max_size;
    cout << endl;
}
template <class T>
void Array<T>::create()
{
    no_of_element();
    arr = new T[max_size];
    cout << "entering all elemnts ";
    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
}
template <class T>
void Array<T>::display()
{
    cout << "printing all elements " << endl;
    cout << "[";
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}
template <class T>
void Array<T>::append(T x)
{
    if (length < max_size)
        arr[length] = x;
    length++;
}
template <class T>
void Array<T>::insert(int index, T x)
{
    if (index >= 0 && index <= length)
    {
        for (int i = length; i > index; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[index] = x;
        length++;
    }
}
template <class T>
T Array<T>::Delete(int index)
{
    cout << endl;
    T x = 0;
    if (index >= 0 && index <= length)
    {
        x = arr[index];
        for (int i = index; i < length - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        length--;
    }
    return x;
}
template <class T>
T Array<T>::linear_search(T key)
{
    cout << endl;
    for (int i = 0; i < length; i++)
    {
        if (key == arr[i])
        {
            return i;
        }
    }
    return -1;
}
template <class T>
T Array<T>::linear_search_transpose(T key)
{
    cout << endl;
    for (int i = 0; i < length; i++)
    {
        if (key == arr[i])
        {
            return i;
            swap(&arr[i], &arr[i - 1]);
        }
    }
    return -1;
}
template <class T>
T Array<T>::linear_search_move(T key)
{
    cout << endl;
    for (int i = 0; i < length; i++)
    {
        if (key == arr[i])
        {
            return i;
            swap(&arr[i], &arr[0]);
        }
    }
    return -1;
}
template <class T>
T Array<T>::binary_search(T x)
{
    cout << endl;
    int l, h, mid;
    l = 0;
    h = length - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (x == arr[mid])
        {
            return mid;
            cout << endl;
        }
        else if (x < arr[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
template <class T>
T binary_search_recursion(T arr1[], int l, int h, T key)
{
    cout << endl;
    int mid;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (arr1[mid] == key)
        {
            return mid;
        }
        else if (key < arr1[mid])
            return binary_search_recursion(arr1, l, mid - 1, key);
        else
            return binary_search_recursion(arr1, mid + 1, h, key);
    }
}
template <class T>
T Array<T>::get(T x)
{
    cout << endl;
    if (x >= 0 && x <= length)
    {
        return arr[x];
    }
    return -1;
}
template <class T>
void Array<T>::set(int x, T y)
{
    if (x >= 0 && x <= length)
    {
        arr[x] = y;
    }
}
template <class T>
T Array<T>::max()
{
    cout << endl;
    T maxx = arr[0];
    for (int i = 1; i < length; i++)
    {
        if (arr[i] > maxx)
        {
            maxx = arr[i];
        }
    }
    return maxx;
}
template <class T>
T Array<T>::min()
{
    cout << endl;
    T maxx = arr[0];
    for (int i = 1; i < length; i++)
    {
        if (arr[i] < maxx)
        {
            maxx = arr[i];
        }
    }
    return maxx;
}
template <class T>
T Array<T>::sum()
{
    cout << endl;
    T s = 0;
    for (int i = 0; i < length; i++)
    {
        s = s + arr[i];
    }
    return s;
}
template <class T>
double Array<T>::avg()
{
    cout << endl;
    T s = 0;
    for (int i = 0; i < length; i++)
    {
        s = s + arr[i];
    }
    return static_cast<double>(s) / length;
}
template <class T>
void Array<T>::reverse_aux()
{
    T *b;
    b = new T[length];
    for (int i = 0; i < length; i++)
    {
        b[i] = arr[length - 1 - i];
    }
    for (int i = 0; i < length; i++)
    {
        arr[i] = b[i];
    }
}
template <class T>
void Array<T>::reverse_swap()
{
    for (int i = 0; i < length; i++)
    {
        swap(arr[i], arr[length - 1 - i]);
    }
}
template <class T>
void Array<T>::insert_sorted(T x)
{
    if (length < max_size)
    {
        int i = length - 1;
        while (arr[i] > x)
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = x;
        length++;
    }
}
template <class T>
T Array<T>::is_sorted()
{
    cout << endl;
    int count = 0;
    for (int i = 0; i < length - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return 0;
    }
    return 1;
}
template <class T>
void Array<T>::rearrange()
{
    int i = 0;
    int j = length - 1;
    while (i < j)
    {
        while (arr[i] < 0)
            i++;
        while (arr[j] > 0)
            j++;
        if (i < j)
            swap(arr[i], arr[j]);
    }
}
int main()
{
    class Array<int> a;
    a.set_size();
    a.create();
    a.display();
    return 0;
}
