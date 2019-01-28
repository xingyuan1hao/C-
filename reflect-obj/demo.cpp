// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>

#include "testClass.h"
#include "classFactory.h"


#include "reflex.h"
#include "reflextest.h"



//#define _CRT_SECURE_NO_WARNINGS

using namespace std;
class CBox1 {
};
class CBox2 {
	int length, width, height;
};
class CBox3 {
	int length, width, height;
	static int count;
};
class CBox4 {
	int foo();
};
class CBox5 {
public:
	CBox5() {};
	~CBox5() {};
};
class CBox6 {
public:
	CBox6() {};
	virtual ~CBox6() {};
};
class A {
};
class B {
};
class C :public A {
};
class D :public virtual B {
};
class E :public A, public B {
};

class String
{
public:
	String(const char *str = NULL);// ��ͨ���캯��  
	String(const String &other);// �������캯��  
	~String(void);// ��������  
	String & operator = (const String &other);// ��ֵ����  
private:
	char *m_data;// ���ڱ����ַ���  
};


vector<string> StringSplit(const string& sData, const string& sDelim) 
{
	vector<string>vItems;
	vItems.clear();
	string::size_type bpos = 0;
	string::size_type epos = 0;
	string::size_type nlen = sDelim.size();
	while ((epos = sData.find(sDelim, epos)) != string::npos) {
		vItems.push_back(sData.substr(bpos, epos - bpos));
		epos += nlen;
		bpos = epos;
	}
	vItems.push_back(sData.substr(bpos, sData.size() - bpos));
	return vItems;
}

int value = 3;
//void func(int *&p)
//{
//	p = &value;
//}
 
void func(int **p)
{
	*p = &value;
}

//��ͨ���캯��  
String::String(const char *str)
{
	if (str == NULL)
	{
		m_data = new char[1];// �÷ֵ㣺�Կ��ַ����Զ������Ž�����־'\0'�ģ��ӷֵ㣺��m_data��NULL�ж�  
		*m_data = '\0';
	}
	else
	{
		int length = strlen(str);
		m_data = new char[length + 1];// ���ܼ� NULL �ж������
		strcpy(m_data, str);
	}
	printf("String:%s\r\n", m_data);

}


// String����������  
String::~String(void)
{
	delete[] m_data; // ��delete m_data;  
}


//�������캯��  
String::String(const String &other)// �÷ֵ㣺�������Ϊconst��  
{
	int length = strlen(other.m_data);
	m_data = new char[length + 1];// ���ܼ� NULL �ж������  
	strcpy(m_data, other.m_data);
	printf("String&:%s\r\n", m_data);

}


//��ֵ����  
String & String::operator = (const String &other) // �÷ֵ㣺�������Ϊconst��  
{
	if (this == &other)//�÷ֵ㣺����Ը�ֵ  
		return *this;
	if (m_data)
		delete[] m_data;//�÷ֵ㣺�ͷ�ԭ�е��ڴ���Դ  
	int length = strlen(other.m_data);
	m_data = new char[length + 1];//�ӷֵ㣺��m_data��NULL�ж�  
	strcpy(m_data, other.m_data);
	printf("String& operator:%s\r\n", m_data);
	return *this;//�÷ֵ㣺���ر����������    
}


#if 1
int _tmain(int argc, _TCHAR* argv[])
{
#if 0
	float f = 0.123456789;

	printf("float:%.10f\r\n",f);
	double d = 0.123457689;
	 
	printf("double:%.20lf\r\n", d);

	unsigned long long ul = 0x7ffffffff;
	long long l = 0x7ffffffff;
	printf("long long:%lld\r\n", ul);

	d = 0x7ffffffff;
	printf("doubleD:%lf\r\n", d);

	f = 0x7fffffff;
	printf("floatF:%lf\r\n", f);


	char *value = "a=1&b=2&c=3";
	/*"a=1&b=2&c=3"*/
	vector<string>paras = StringSplit((const string)value, "&");
	vector<string>::iterator iter = paras.begin();
	for (; iter != paras.end(); iter++) {
		vector<string>singlepara = StringSplit(*iter, "=");
		cout << *iter << endl;
		cout << singlepara[0] << " " << singlepara[1] << endl;
	}
#endif

#if 0
	CBox1 box1obj;
	cout << "box1: " << sizeof(box1obj) << endl;//���1

	CBox2 box2obj;
	cout << "box2: " << sizeof(box2obj) << endl;

	CBox3 box3obj;
	cout << "box3: " << sizeof(box3obj) << endl;

	CBox4 box4obj;
	cout << "box4: " << sizeof(box4obj) << endl;

	CBox5 box5obj;
	cout << "box5: " << sizeof(box5obj) << endl;

	CBox6 box6obj;
	cout << "box6: " << sizeof(box6obj) << endl;

	A a;
	B b;
	C c;
	D d;
	E e;
	cout << "sizeof(a):" << sizeof(a) << endl;
	cout << "sizeof(b):" << sizeof(b) << endl;
	cout << "sizeof(c):" << sizeof(c) << endl;
	cout << "sizeof(d):" << sizeof(d) << endl;
	cout << "sizeof(e):" << sizeof(e) << endl;
#endif	
#if 0
	int n = 2;
	int *pn = &n;
	cout << *pn << endl;
	func(pn);
	cout << *pn << endl;


	int n = 1;
	int *pn = &n;
	cout << *pn << endl;
	func(&pn);
	cout << *pn << endl;
#endif
#if 0
	char* p = "Hello World !";
	String s(p); 
	//cout << s << endl;
	String s1("How are you ?");

	String s2 = s;
	//cout << s1 << endl;
	//s1 = s; cout << s << endl << s1 << endl;
	s = s2 = s1;
	//cout << s << endl << s1 << endl;
#endif

#if 0
	//ע��
	ClassFactory::getInstance().registClass("Test", create_Test);

	//��ȡ�����
	Test *t = (Test*)ClassFactory::getInstance().getClassByName("Test");
	if (!t) {
		std::cout << "get instnce Test err;" << std::endl;
		return 1;
	}

	t->print();
	delete t;
#endif


	CTest* test = (CTest*)(Reflex::CreatObject("CTest"));
	delete test;

	getchar();
	return 0;

}
#endif
