#include "../std_lib_facilities.h"

class Token
{
    public:
        char kind;        // what kind of token
        double value;     // for numbers: a value 
        Token (char ch) 
	:kind(ch), value(0) {}  // make a Token from a char
        Token (char ch, double val) 
	: kind(ch), value(val) {}// make a Token from a char and a double
};


class Token_stream
{
    public:
        Token_stream();   // make a Token_stream that reads from cin
        Token get();      // get a Token (get() is defined elsewhere)
        void putback(Token t);    // put a Token back
    private:
        bool full;        // is there a Token in the buffer?
        Token buffer;     // here is where we keep a Token put back using putback()
};



Token_stream::Token_stream(): full(false), buffer(0) {}


// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) 
        error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}


Token Token_stream::get()
{
    if (full) // do we already have a Token ready?
    {       
            // remove token from buffer
            full = false;
            return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch)
    {
        case 'x':    // for "quit"，q was replaced by x
        case '=':    // for "print"，; was replaced by =
        case '(': 
        case ')': 
        case '+': 
        case '-': 
        case '*': 
        case '/':
            return Token(ch);        // let each character represent itself
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            {
                cin.putback(ch);         // put digit back into the input stream
                double val = 0;
                cin >> val;              // read a floating-point number
                return Token('8', val);   // let '8' represent "a number"
            }
        default:
            error("Bad token");
            return 0;
    }
}


Token_stream ts;      


double expression();    


// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) 
    {
        case '(':    // handle '(' expression ')'
            {
                double d = expression();
                t = ts.get();
                if (t.kind != ')') 
			error("')' expected");
                return d;
            }
        case '8':            // we use '8' to represent a number
            return t.value;  // return the number's value
        default:
            error("primary expected");
            return 0;
    }
}


// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get();        
    while (true) 
    {   
        switch (t.kind) 
        {
            case '*':
            	left *= primary();
            	t = ts.get();
            	break;
            case '/':
            {
            	double d = primary();
            	if (d == 0) 
                	error("divide by zero");
            	left /= d;
            	t = ts.get();
            	break;
            }
        	default:    
            	ts.putback(t);     
            	return left;
        }
    }
}
// deal with + and -
double expression()
{
    double left = term();      
    Token t = ts.get();        
    while (true)
    {
        switch (t.kind) 
        {
            case '+':
                left += term();   
                t = ts.get();
                break;
            case '-':
                left -= term();    
                t = ts.get();
                break;
            default:
                ts.putback(t);     
                return left;      
        }
    }
}

int main()
{
	cout << "Welcome to simple calculator." << endl;		 // greeting line in main
	cout << "Please enter numbers to be calculated." << endl;
	cout << enter 'x' to leave, or enter '=' to result!”  << endl;
try
{   
    double val = 0;
    
    while (cin) 
    {
        Token t = ts.get();
        if (t.kind == 'q') 
            break; // 'q' for quit
        if (t.kind == '=')        // '=' for "print now"
            cout << val << '\n';
        else
            ts.putback(t);
        val = expression();
    }
    keep_window_open();
	return 0;
}
catch (exception& e) 
{
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...) 
{
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}
}
