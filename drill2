
#include "../std_lib_facilities.h"

class Token
{	
	public:
		char kind;
		double value;
		string name;// three constructors
		Token(char ch) :kind(ch), value(0) {}
		Token(char ch, double val) :kind(ch), value(val) {}
		Token(char ch, string n) : kind(ch), name(n) {}
};

class Token_stream 
{
	public:
		Token_stream();full(0), buffer(0) { }
		Token get();
		void putback(Token t);{ buffer = t; full = true; }
		void ignore(char); // discard characters up to and including a char
	private:
		bool full;
		Token buffer;
};

//Symbolic constants
const char let = 'L';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char square_root = 's';
const char power_ = 'p';
const char constant = 'c';

const string prompt = "> ";
const string result = "= ";

Token Token_stream::get()
{
	if (full) 
  { 
      full = false;
      return buffer;
   }
   char ch;
	 cin >> ch;
   switch (ch)
	{
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case ';':
		case '=':
		case ',':
			return Token(ch);
		case '.':
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token(number, val);
	}
	case '#':
		return Token(let);
	default:
		if (isalpha(ch))
		{
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) 
				s += ch;
			cin.putback(ch);
			
			if (s == squareroot)
				return Token(square_root);
			if (s == power)
				return Token(power_);
			if (s == "const") 
				return Token(constant);
			if (s == "quit") 
				return Token(name);
			return Token(name,s);
		}
			error("Bad token");
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch=0;
	while (cin >> ch)
		if (ch == c) return;
}

class Variable
{
	public:
		string name;
		double value;
		Variable(string n, double v) :name(n), value(v) {}
};

vector<Variable> var_table;

double get_value(string s)
{
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s)
			return var_table[i].value;
	error("get: undefined name ", s);
	return -1;
}

void set_value(string s, double d)
{
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s) 
		{
			var_table[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s)
{
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s) 
			return true;
		return false;
}

Token_stream ts;

double expression();

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		//added below line
		return d;
	}
	case sq:
	{
		t = ts.get();	// get the '(' 
		if (t.kind != '(') error("'(' expected");
		double d = sqrt(expression());
		if (isnan(d)) error("negative sqrt computed");
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;
	}
	case pwr:
	{
		t = ts.get();
		if (t.kind != '(') error("'(' expected");

		double d = expression();
		t = ts.get();
		if (t.kind != ',') error("',' expected");

		int m = narrow_cast<int>(expression());
		d = pow(d,m);

		t = ts.get();
		if (t.kind != ')') error("')' expected");
		
		return d;
	}
	case '-':
		return - primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	default:
		error("primary expected");
	}
}

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
				if (d == 0) error("divide by zero");
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

double declaration()
{
	Token t = ts.get();
	if (t.kind != name) 
		error("name expected in declaration");
	
	string var_name = t.name;
	
	Token t2 = ts.get();
	if (t2.kind != '=') 
		error("= missing in declaration of ", name);
	
	double d = expression();
	define_name(var_name, d);
	return d;
}



double statement()
{
	Token t = ts.get();
	switch(t.kind) {
	case let:
		return declaration();
	case constant:
		return declare_const();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
	
}

void calculate() // expression evaluation loop
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) 
			t = ts.get();
		if (t.kind == quit) 
			return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()

try {
	calculate();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}
