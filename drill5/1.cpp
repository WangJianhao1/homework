#include "std_lib_facilities.h"

// 1:Write a function print_array10(ostream& os, int* a) that prints out the values of a (assumed to have ten elements) to os.
void print_array10(ostream& os, int* a)
{
    for (int i = 0; i<10; ++i)
        os << a[i] << " ";
}

// 2: Write a function print_array(ostream& os, int* a, int n) that prints out the values of a (assumed to have n elements) to os.
void print_array(ostream& os, int* a, int n)
{
    for (int i = 0; i<n; ++i)
        os << a[i] << " ";
}

// 3: Do 7, 8, and 9 using a vector instead of an array and a print_vector() instead of print_array().
void print_vector(ostream& os, vector<int> v)
{
    for (int i = 0; i<v.size(); ++i)
        os << v[i] << " ";
}

int main()
try
{
// 4: Allocate an array of ten ints on the free store(heap store) using new.
    int* ip = new int[10];

// 5: Print the values of the ten ints to cout.
    cout << "task 5: print the 10 ints: \n";
    for (int i = 0; i<10; ++i)
        cout << ip[i] << " " ;
    cout << endl;
  
// 6: Deallocate the array (using delete[]).
    delete[] ip;
    
// 7: Allocate an array of ten ints on the free store; initialize it with the values 100, 101, 102, etc.; and print out its values.
    cout << "task 7: print the 10 ints: \n";
    int* ip2 = new int[10];
    for (int i = 0; i<10; ++i) //initialization loop
        ip2[i] = 100 + i;
    print_array10(cout,ip2);
    cout << endl;
    delete[] ip2;
    
// 8: Allocate an array of 11 ints on the free store; initialize it with the values 100, 101, 102, etc.; and print out its values.
    cout << "task 8: print the 11 ints: \n";
    int* ip3 = new int[11];
    for (int i = 0; i<11; ++i)
        ip3[i] = 100 + i;
    print_array10(cout,ip3);
    cout << ip3[10] << "\n";
    cout << endl;
    delete[] ip3;
    
 // 9: Allocate an array of 20 ints on the free store; initialize it with the values 100, 101, 102, etc.; and print out its values.
    cout << "task 9: print the 20 ints: \n";
    int* ip4 = new int[20];
    for (int i = 0; i<20; ++i)
        ip4[i] = 100 + i;
    print_array(cout,ip4,20);
    cout << endl;
    delete[] ip4;
    
 // 10:  Do 5, 6, and 8 using a vector instead of an array and a print_vector() instead of print_array().
    cout << "task 10: \n";
    vector<int> v;
    for (int i = 0; i<10; ++i)
        v.push_back(100+i);
    print_vector(cout,v);
    cout << endl;

    vector<int> v2;
    for (int i = 0; i<11; ++i)
        v2.push_back(100+i);
    print_vector(cout,v2);
    cout << endl;

    vector<int> v3;
    for (int i = 0; i<20; ++i)
        v3.push_back(100+i);
    print_vector(cout,v3);
    cout << endl;
    
// 11: Allocate an int, initialize it to 7, and assign its address to a variable p1.
    int i1 = 7;
    int* p1 = &i1;

// 12: Print out the value of p1 and of the int it points to.
    cout << "task 12: \n";
    cout << "p1: " << p1 << endl;
    cout << "*p1: " << *p1 << endl;

// 13: Allocate an array of seven ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to a variable p2.
    int* p2 = new int[7];
    for (int i = 0; i<7; ++i)
        p2[i] = pow(2,i);

// 14: Print out the value of p2 and of the array it points to.
    cout << "task 14: \n";
    cout << "p2: " << p2 << "\n";
    cout << "print_array(cout,p2,7): ";
    print_array(cout,p2,7);
    cout << endl;

// 15: Declare an int* called p3
    int* p3 = p2;
         p2 = p1;
         p2 = p3;

// 16: Print out the values of p1 and p2 and of what they point to.
    cout << "task 16: \n";
    cout << "p1: " << p1 << "\n";
    cout << "*p1: " << *p1 << "\n";
    cout << "p2: " << p2 << "\n";
    cout << "*p2: " << *p2 << "\n";

// 17: Deallocate all the memory you allocated from the free store.
    delete[] p2;
    p3 = 0;

// 18: Allocate an array of ten ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to a variable p1.
    p1 = new int[10];
    for (int i = 0; i<10; ++i)
        p1[i] = pow(2,i);

// 19: Allocate an array of ten ints, and assign its address to a variable p2.
    p2 = new int[10];

// 20: Copy the values from the array pointed to by p1 into the array pointed to by p2.
    cout << "task 20: \n";
    for (int i = 0; i<10; ++i)
        p2[i] = p1[i];
    print_array(cout,p2,10);
    cout << endl;

// 21: Repeat 18–20 using a vector rather than an array.
    cout << "task 21: \n";
    vector<int> vec1;
    for (int i = 0; i<10; ++i)
        vec1.push_back(pow(2,i));
    vector<int> vec2;
    for (int i = 0; i<vec1.size(); ++i)
        vec2.push_back(vec1[i]);
    print_vector(cout,vec2);
    cout << endl;
    
}
catch (exception& e)
{
    cerr << "exception: " << e.what() << endl;
}
catch (...)
{
    cerr << "exception\n";
}   
