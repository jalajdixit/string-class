
/* My String Class */

#include<iostream>
#include<cstring>
using namespace std;

class my_string
{
	char *str;
public:
	 my_string() { cout << "Constructor" << endl; }	//Constructor
	~my_string() {					//Destructor
		delete str;
		cout << "~Destructor" << endl; 
	}

	my_string(const char *s) {		//Parametrized
		str = new char[strlen(s)+1];
		strcpy(str,s);
		cout << "obj(string)" << endl;
	}
	my_string(const my_string &temp) {	//Copy Constructor
		str = new char[strlen(temp.str)+1];
		strcpy(str,temp.str);
		cout << "obj(obj)" << endl;
	}

	void print() { cout << str << endl; }
	void change() { str[0] = 'X'; }
};

/* = = = = = = = = = = = = = = = = = = = = = = */
int main()
{
	my_string obj1("Bangalore"),obj2="Vector";
	my_string obj3;

	obj1.print();
	obj2.print();
	obj3.print();


	return 0;
}
