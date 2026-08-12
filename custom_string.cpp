#include<iostream>
#include<cstring>
using namespace std;
class Mystring
{
	char* data;
	int length;

	public:
	//constructor
	Mystring()
	{
		length=0;
		data=new char[1];
		data[0]='\0';
	}
 
	//parameterized
	Mystring(const char *str)
	{
		if(str==0)
		{
			length=0;
			data=new char[1];
			data[0]='\0';
		}
		else
		{
			length=strlen(str);
			data=new char[length+1];
			strcpy(data,str);
		}
	}

	//copy constructor
	Mystring(const Mystring &str)
	{
		length=str.length;
		data=new char[length+1];
		strcpy(data,str.data);
	}
	//copy operator
	Mystring& operator=(const Mystring &str)
	{
		if(this!=&str)
		{
			delete []data;
			length=str.length;
			data=new char[length+1];
			strcpy(data,str.data);
		}
	}
	//move constructor
	Mystring(Mystring &&str)
	{
		data=str.data;
		length=str.length;

		str.data=new char[1];
		str.data[0]='\0';
		str.length=str.length;
	}
	//move operator
	Mystring& operator=(Mystring &&str)
	{
		if(this!=&str)
		{
			delete []data;
			data=str.data;
			length=str.length;

			str.data=new char[1];
			str.data[0]='\0';
			str.length=str.length;
		}
	}

	//character access
	char& operator[](int i)
	{
		return data[i];
	}

	//concatenation operator
	Mystring operator+(const Mystring &str)
	{
		Mystring result;
		delete[] result.data;
		result.length=length+str.length;
		result.data=new char[length+1];
		strcpy(result.data,data);
		strcat(result.data,str.data);
		return result;
	}

	//equal
	bool operator==(const Mystring &str)
	{
		return (strcmp(data,str.data)==0);
	}

	//notequal
	bool operator!=(const Mystring &str)
	{
		return (strcmp(data,str.data)!=0);
	}

	//mystrlen
	int mystrlen()
	{
		int count=0;
		while(data[count]!='\0')
		{
			count++;
		}
		return count;
	}

	//Cout
	friend ostream& operator<<(ostream& sout,Mystring &str)
	{
		sout<<str.data;
	}

	//Cin
	friend istream& operator>>(istream& sin,Mystring &str)
	{
		sin>>str.data;
	}

	//Destructor
	~Mystring()
	{
		delete[] data;
	}

};

int main()
{
	Mystring str1,str2;
	cout<<"Enter String 1:"<<endl;
	cin>>str1;
	cout<<"Enter String 2:"<<endl;
	cin>>str2;

        cout<<endl;
	cout << "String 1: " << str1 << endl;
	cout << "String 2: " << str2 << endl;
        cout<<endl;

	// length
	cout << "Length of String 1: "<< str1.mystrlen() << endl;
        cout<<endl;

	// character access
	cout << "Character at index 1: " << str1[1] << endl;
        cout<<endl;

	// concatenation
	Mystring str3 = str1 + Mystring(" ") + str2;
	cout << "Concatenated String3: "<< str3 << endl;
        cout<<endl;

	// copy constructor
	Mystring str4 = str3;
	cout << "Copied String String 4: "<< str4 << endl;
        cout<<endl;

	// equal
	if (str3 == str4)
		cout << "str3 and str4 are equal" << endl;
        cout<<endl;

	// copy operator
	Mystring str5;
	str5 = str1;
	cout << "Copy operator String5: "<< str5 << endl;
        cout<<endl;

	// move constructor
	Mystring str6 = std::move(str5);
	cout << "Moved Constructor String5: " << str5 << endl;
	cout << "Move Constructor String6: " << str6 << endl;
        cout<<endl;
 	
        // move operator
	Mystring str7;
	str7 = std::move(str6);
	cout << "Moved Constructor String6: " << str6 << endl;
	cout << "Move operator String7: "<< str7 << endl;

}
