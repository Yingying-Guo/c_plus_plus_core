#include<iostream>
using namespace std;

//���һ��ѧ���࣬������������ѧ��
//���Ը�������ѧ�Ÿ�ֵ��������ʾѧ����������ѧ��

class Student
{
public: //����Ȩ��
	//����
	string m_Name;//����
	int m_Id;//ѧ��
	
	//��Ϊ
	//��ʾ������ѧ��
	void showStudent()
	{
		cout << "������ " << m_Name << " ѧ�ţ� " << m_Id << endl;
	}

	//��������ֵ
	void setName(string name)
	{
		m_Name = name;
	}
	//��ѧ�Ÿ�ֵ
	void setId(int id)
	{
		m_Id = id;
	}
};

int main()
{
	//����һ������ѧ�� ʵ��������
	Student s1;
	//��s1����������Ը�ֵ����
	s1.setName("����");
	s1.setId(1);
	//��ʾѧ����Ϣ

	s1.showStudent();

	Student s2;
	s2.m_Name = "����";
	s2.m_Id = 2;
	s2.showStudent();

	system("pause");
	return 0;
}
