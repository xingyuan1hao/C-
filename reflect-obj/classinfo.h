#pragma once
#include "reflex.h"

//����ָ�롢ָ�򴴽���ʵ���Ļص�����
typedef Reflex* (*ObjConstructorFun)();
class ClassInfo
{
public:
	ClassInfo(const std::string className, ObjConstructorFun classConstructor)
		:m_className(className), m_objectConstructor(classConstructor)
	{
		//classInfo�Ĺ��캯���Ǵ������������Ӧ��new����Ȼ���Զ�ע���map��
		Reflex::Register(this);
	}
	virtual ~ClassInfo() {}
	Reflex* CreateObject()const { return m_objectConstructor ? (*m_objectConstructor)() : NULL; }
	bool IsDynamic()const { return NULL != m_objectConstructor; }
	const std::string GetClassName()const { return m_className; }
	ObjConstructorFun GetConstructor()const { return m_objectConstructor; }
public:
	std::string m_className;
	ObjConstructorFun m_objectConstructor;
};
//
