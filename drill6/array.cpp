#include "../std_lib_facilities.h"

//1:Define a global int array ga of ten ints initialized to 1, 2, 4, 8, 16, etc.
int ga[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
void print_ar(const int ai[], int n)
{
    for (int i = 0; i<n; ++i) 
        cout << ai[i] << " ";
}

void f(int ai[], int n) 
{
//2:Define a local int array la of ten ints.
    int la[10]; 
    
    for (int i = 0; i<10; ++i) //3:Copy the values from ga into la through a loop
        la[i] = ga[i];
    
    print_ar(la,10);      //4:Print out the elements of la.
    cout << endl;
    
    int* p = new int[n];  //5:Define a pointer p to int and 
                          //  initialize it with an array allocated on the free store with the same number of elements as the argument array.
    
    for (int i = 0; i<n; ++i) 
        p[i] = ai[i];   //6:Copy the values from the argument array into the free-store array.
    print_ar(p,n);      //  Print out the elements of the free-store array.
    cout << endl;
    
    delete[] p;         //7:Deallocate the free-store array.
}

int main()
try
{
    f(ga,10);           //8:Call f() with ga as its argument.
    
    int aa[10] = { 1 }; //9:Define an array aa with ten elements, and initialize it with the first ten factorial values (1, 2*1, 3*2*1, 4*3*2*1, etc.).
    for (int i = 1; i<10; ++i) 
        aa[i] = aa[i-1]*(i+1);
    f(aa,10);
}
catch (exception& e)
{
    cerr << "exception: " << e.what() << endl;
}
catch (...) 
{
    cerr << "exception\n";
}
