// this array helps us to create an array  in heap so its will not use stack memory

#include <bits/stdc++.h>
using namespace std;


void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


class Array
{

    int *arr;
    /* it will create an array of max size 
    like in vector we can inc the no of element here also we can inc the no of element */
    int max_size;
    // total no of elements in array we are going to give 
    int length;

public:
    //set_size helps us to create the max size of any array in heap
    void set_size();
    //  no_of_elements will help us to initilize the size of an array 
    void no_of_element();
    // create fn will helps us to create an array of no_of_elements elements 
    void create();
    // display fn will display all the elements 
    void display();
    // append methon is used to append any integer 
    void append(int);
    void insert(int, int);
    int Delete(int);
    int linear_search(int);
    int linear_search_transpose(int);
    int linear_search_move(int);
    int binary_search(int);
    int binary_search_recursion(int, int, int, int);
    int get(int);
    void set(int, int);
    int max();
    int min();
    int sum();
    double avg();
    void reverse_aux();
    void reverse_swap();
    void insert_sorted(int x);
    int is_sorted();
    void rearrange();
};

void Array ::no_of_element()
{
    cout << "enter no of element ";
    cin >> length;
    cout<<endl;
}

void Array ::set_size()
{
    cout << "enter the max size ";
    cin >> max_size;
    cout<<endl;
}

void Array ::create()
{
    no_of_element();
    arr = new int[max_size];
    cout << "entering all elemnts ";
    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
}

void Array ::display()
{
    cout << "printing all elements " << endl;
    cout << "[";
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

void Array ::append(int x)
{
    if (length < max_size)
        arr[length] = x;
    length++;
}

void Array ::insert(int index, int x)
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

int Array ::Delete(int index)
{
    cout<<endl;
    int x = 0;
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
int Array ::linear_search(int key)
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

int Array ::linear_search_transpose(int key)
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
int Array ::linear_search_move(int key)
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

int Array ::binary_search(int x)
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

int binary_search_recursion(int arr1[], int l, int h, int key)
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

int Array ::get(int x)
{
    cout << endl;
    if (x >= 0 && x <= length)
    {
        return arr[x];
    }
    return -1;
}
void Array ::set(int x, int y)
{
    if (x >= 0 && x <= length)
    {
        arr[x] = y;
    }
}

int Array ::max()
{
    cout << endl;
    int maxx = arr[0];
    for (int i = 1; i < length; i++)
    {
        if (arr[i] > maxx)
        {
            maxx = arr[i];
        }
    }
    return maxx;
}
int Array ::min()
{
    cout << endl;
    int maxx = arr[0];
    for (int i = 1; i < length; i++)
    {
        if (arr[i] < maxx)
        {
            maxx = arr[i];
        }
    }
    return maxx;
}

int Array ::sum()
{
    cout << endl;
    int s = 0;
    for (int i = 0; i < length; i++)
    {
        s = s + arr[i];
    }
    return s;
}
double Array ::avg()
{
    cout << endl;
    int s = 0;
    for (int i = 0; i < length; i++)
    {
        s = s + arr[i];
    }
    return static_cast<double>(s) / length;
}
void Array ::reverse_aux()
{
    int *b;
    b = new int[length];
    for (int i = 0; i < length; i++)
    {
        b[i] = arr[length - 1 - i];
    }
    for (int i = 0; i < length; i++)
    {
        arr[i] = b[i];
    }
}
void Array ::reverse_swap()
{
    for (int i = 0; i < length; i++)
    {
        swap(arr[i], arr[length - 1 - i]);
    }
}
void Array ::insert_sorted(int x)
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

int Array ::is_sorted()
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

void Array ::rearrange()
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

void merge(int arr1[],int arr2[],int x,int y)
{
    int *arr3;
    arr3=new int[x+y];
    
    
}

int main()
{
    class Array a;

    a.set_size();
    a.create();
    a.display();

    // a.append(11);
    // a.display();

    // a.insert(3,22);
    // a.display();

    // a.Delete(2);
    // a.display();

    // int ls=a.linear_search(5);
    // cout<<ls<<endl;
    // int lst=a.linear_search_transpose(19);
    // cout<<lst<<endl;
    // int lsm=a.linear_search_move(5);
    // cout<<lsm<<endl;

    // int bs=a.binary_search(2);
    // cout<<bs<<endl;

    // int array[5] {2,3,4,5,6};
    // int bsr=binary_search_recursion(array, 0,5,2);
    // cout<<bsr<<endl;

    // int gt=a.get(2);
    // cout<<gt<<endl;

    // a.set(2,1000);
    // a.display();

    // int mx=a.max();
    // int mi=a.min();
    // cout<<mx<<endl;
    // cout<<mi<<endl;

    // int sm=a.sum();
    // double ag=a.avg();
    // cout<<sm<<" "<<ag<<endl;

    // a.reverse_aux();
    // a.display();

    // a.reverse_swap();
    // a.display();

    // a.insert_sorted(44);
    // a.display();

    // bool aa=a.is_sorted();
    // cout<<aa<<endl;

    // a.rearrange();
    a.display();

    return 0;
}
