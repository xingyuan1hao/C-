#pragma once
//Reflex.h
#include <string>




class ClassInfo;
class Reflex
{
public:
	Reflex() {}
	virtual ~Reflex() {}
	//hash��ע��
	static bool Register(ClassInfo* pCInfo);
	static Reflex* CreatObject(std::string className);
};

//���������Ա�����Լ�������ע��
#define DECLARE_CLASS(class_name) \
    public:\
        virtual ClassInfo* GetClassInfo() const { return &m_classInfo; }\
        static Reflex* CreatObject()\
        {\
            return new class_name;\
        }\
    protected:\
        static ClassInfo m_classInfo;


//��������ClassInfoע��
#define REGISTER_CLASS(class_name)\
    ClassInfo class_name::m_classInfo(#class_name, class_name::CreatObject);

//������д�������������
#define REFLEX_CLASS(class_name)\
    (class_name*)(Reflex::CreatObject(#class_name))
//
