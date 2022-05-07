#include "../std_lib_facilities.h"

template<class T> struct S      
{
    S() : val(T()) { }      
    S(T d) : val(d) { }    
    T& operator=(const T&); 
    T& get();               
    const T& get() const;  
    void set(const T& d);  
private:
    T val;                  
};

template<class T> T& S<T>::operator=(const T& d)
{
    val = d;
    return val;
}


/*

template<class T1,class T2> void A<T1,T2>::h(){}
*/
template<class T> T& S<T>::get() { return val; }                    //Put the definition of get() outside the class.

template<class T> const T& S<T>::get() const { return val; }        //Provide const versions of get().

template<class T> void S<T>::set(const T& d) { val = d; }           //Add a set() function template so that you can change val.

// Define a function template<typename T> read_val(T& v) that reads from cin into v.
template<class T> istream& operator>>(istream& is, S<T>& ss)
{
    T v;
    cin >> v;
    if (!is) return is;
    ss = v;
    return is;
}

template<class T> void read_val(T& v)
{
    cin >> v;
}

template<class T> ostream& operator<<(ostream& os, const vector<T>& d)
{
    os << "{ ";
    for (int i = 0; i<d.size(); ++i)
    {
        os << d[i];
        if (i<d.size()-1) 
            os << ',';
        os << ' ';
    }
    os << "}";
    return os;
}

template<class T> istream& operator>>(istream& is, vector<T>& d)
{
    char ch1;
    char ch2;
    T temp;
    vector<T> v_temp;
    is >> ch1;
    if (!is) 
        return is;
    if (ch1!='{') 
    {
        is.clear(ios_base::failbit);
        return is;
    }
    while (cin>>temp>>ch2 && ch2==',')
    {
        v_temp.push_back(temp);
    }
    if (ch2!='}')
    {
        is.clear(ios_base::failbit);
        return is;
    }
    v_temp.push_back(temp); // ch2=='}', read last value

    // copy temp vector only now so d is not changed if input fails
    d = v_temp;
}

int main()
try {
    // Define variables of types S<int>, S<char>, S<double>, S<string>, and S<vector<int>>; initialize them with values of your choice.
    S<int> s_int (5);                //S(T d) : val(d) { } ; s_int is the name of the int variable.
    S<char> s_char ('x');
    S<double> s_dbl (3.14);
    S<string> s_strg ("String1");
    
    vector<int> vi;                  //first of all we define a vector named vi
    vi.push_back(1);
    vi.push_back(2);
    vi.push_back(3);                 //initalize the vector
    S<vector<int>> s_v_int (vi);     //define the variable of vector named s_v_int

    
/*  Read those values and print them.
    cout << "s_int: " << s_int.val << endl;
    cout << "s_char: " << s_char.val << endl;
    cout << "s_dbl: " << s_dbl.val << endl;
    cout << "s_strg: " << s_strg.val << endl;
    for (int i = 0; i<s_v_int.val.size(); ++i)
        cout << "s_v_int[" << i << "]: " << s_v_int.val[i] << endl;
*/

    // Do 4 again using get().
    cout << "s_int: " << s_int.get() << endl;
    cout << "s_char: " << s_char.get() << endl;
    cout << "s_dbl: " << s_dbl.get() << endl;
    cout << "s_strg: " << s_strg.get() << endl;
    for (int i = 0; i<s_v_int.get().size(); ++i)
        cout << "s_v_int[" << i << "]: " << s_v_int.get()[i] << endl;

    // Add a set() function template so that you can change val.
    s_int.set(55);
    s_char.set('y');
    s_dbl.set(4.14);
    s_strg.set("String2");
    vi[1] = 22;
    s_v_int.set(vi);
    cout << "\ns_int: " << s_int.get() << endl;
    cout << "s_char: " << s_char.get() << endl;
    cout << "s_dbl: " << s_dbl.get() << endl;
    cout << "s_strg: " << s_strg.get() << endl;
    for (int i = 0; i<s_v_int.get().size(); ++i)
        cout << "s_v_int[" << i << "]: " << s_v_int.get()[i] << endl;

    // Replace set() with an S<T>::operator=(const T&).
    s_int = 66;
    s_char = 'z';
    s_dbl = 5.14;
    s_strg = "String3";
    vi[1] = 33;
    s_v_int = vi;
    cout << "\ns_int: " << s_int.get() << endl;
    cout << "s_char: " << s_char.get() << endl;
    cout << "s_dbl: " << s_dbl.get() << endl;
    cout << "s_strg: " << s_strg.get() << endl;
    for (int i = 0; i<s_v_int.get().size(); ++i)
        cout << "s_v_int[" << i << "]: " << s_v_int.get()[i] << endl;

    // Provide const versions of get().
    const S<int> c_s_int(5);
    cout << "\nc_s_int: " << c_s_int.get() << endl;

    // Use read_val() to read into each of the variables from 3 except the S<vector<int>> variable.
    cout << "\ns_int: ";
    read_val(s_int);
    cout << "s_char: ";
    read_val(s_char);
    cout << "s_dbl: ";
    read_val(s_dbl);
    cout << "s_strg: ";
    read_val(s_strg);
    cout << "\ns_int: " << s_int.get() << "\n";
    cout << "s_char: " << s_char.get() << "\n";
    cout << "s_dbl: " << s_dbl.get() << "\n";
    cout << "s_strg: " << s_strg.get() << "\n\n";

    /*
            Bonus: Define input and output operators (>> and <<) for vector<T>s. For both input and output use a { val, val, val }
            format. That will allow read_val() to also handle the S<vector<int>> variable.
            Remember to test after each step.
    */
    cout << "\ns_v_int: ";
    read_val(s_v_int);
    cout << "\ns_v_int: " << s_v_int.get() << endl;

}
catch (exception& e)
{
    cerr << "Exception: " << e.what() << endl;
}
catch (...)
{
    cerr << "Exception\n";
}
