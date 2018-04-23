
/* My String Class */

#include<iostream>
#include<cstring>
using namespace std;

class my_string
{
	char *str;
	int len;
	public:

/*===============================================================*/
	 my_string() { 				//Constructor
		 len=0;
		 cout << "Constructor" << endl;
	 }
	~my_string() {				//Destructor
		delete str;
		cout << "~Destructor" << endl; 
	}

	my_string(const char *s) {		//Parametrized
		len = strlen(s);
		str = new char[len+1];
		strcpy(str,s);
		cout << "obj(string)" << endl;
	}
	my_string(const my_string &temp) {	//Copy Constructor
		len = temp.len;
		str = new char[temp.len+1];
		strcpy(str,temp.str);
		cout << "obj(obj)" << endl;
	}
/*===============================================================*/

	void operator = (const my_string &temp) {
		if(len!=0) delete str;
		len = temp.len;
		str = new char[len+1];
		strcpy(str,temp.str);
		cout << "obj = obj" << endl;
	}
	void operator = (const char *s) {
		if(len!=0) delete str;
		len = strlen(s);
		str = new char[len+1];
		strcpy(str,s);
		cout << "obj = string" << endl;
	}
/*===============================================================*/
	
	void print() { cout << str << " - " << len << endl; }
	void change() { str[0] = 'X'; }
	int length() { return len; }

/*===============================================================*/
	bool operator == (const my_string &t2)
	{
		if(! strcmp(str,t2.str))
			return true;
		else
			return false;
	}
	bool operator != (const my_string &t2)
	{
		if(strcmp(str,t2.str))
			return true;
		else
			return false;
	}
	bool operator > (const my_string &t2)
	{
		if(strcmp(str,t2.str)>0)
			return true;
		else
			return false;
	}
	bool operator >= (const my_string &t2)
	{
		if(strcmp(str,t2.str)>0)
			return true;
		else if(! strcmp(str,t2.str))
			return true;
		else
			return false;
	}
	bool operator < (const my_string &t2)
	{
		if(strcmp(str,t2.str)<0)
			return true;
		else
			return false;
	}
	bool operator <= (const my_string &t2)
	{
		if(strcmp(str,t2.str)<0)
			return true;
		else if(! strcmp(str,t2.str))
			return true;
		else
			return false;
	}
/*===============================================================*/
friend my_string operator + (const my_string &t1, const my_string &t2);
friend my_string operator + (const my_string &t1, const char *s);
friend my_string operator + (const char *s, const my_string &t2);
};
/* = = = = = = = = = = = = = = = = = = = = = = */


/* = = = = = = = = = = = = = = = = = = = = = = */

my_string operator + (const my_string &t1, const my_string &t2)
{
	my_string temp;
	temp.len = t1.len + t2.len ;
	temp.str = new char[temp.len+1];
	strcpy(temp.str,t1.str);
	strcat(temp.str,t2.str);
	return temp;
}
my_string operator + (const my_string &t1, const char *s)
{
	my_string temp;
	temp.len = t1.len + strlen(s) ;
	temp.str = new char[temp.len+1];
	strcpy(temp.str,t1.str);
	strcat(temp.str,s);
	return temp;
}
my_string operator + (const char *s, const my_string &t2)
{
	my_string temp;
	temp.len = strlen(s) + t2.len ;
	temp.str = new char[temp.len+1];
	strcpy(temp.str,s);
	strcat(temp.str,t2.str);
	return temp;
}

/* = = = = = = = = = = = = = = = = = = = = = = */
int main()
{
	my_string s1("jalaj"),s2="dixit";
	cout << "- - - - - - - - - - - - - " << endl;
	s1.print();
        s2.print();
	if(s1==s2)
		cout << " == " << endl;
	if(s1!=s2)
		cout << " != " << endl;
	if(s1>s2)
		cout << "  > " << endl;
	if(s1>=s2)
		cout << " >= " << endl;
	if(s1<s2)
		cout << "  < " << endl;
	if(s1<=s2)
		cout << " <= " << endl;
	return 0;
}
