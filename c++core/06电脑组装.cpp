#include<iostream>
#include<string>
using namespace std;

//����ͬ�����
//�����cpu��
class CPU
{
public:
	//����ļ��㺯��
	virtual void calculate() = 0;
};

//������Կ�
class VideoCard
{
public:
	//������ʾ����
	virtual void display() = 0;
};

//����Ĵ洢
class Mermory
{
public:
	//����洢����
	virtual void storage() = 0;
};

//������
class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vc, Mermory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	//�ṩ�����ĺ���
	void work()
	{
		//������������������ýӿ�
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}

	//�ṩ�����������ͷ�3���������
	~Computer()
	{
		//�ͷ�CPU���
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		//�ͷ��Կ����
		if (m_vc != NULL)
		{
			delete m_vc;
			m_vc = NULL;
		}
		//�ͷ��ڴ������
		if (m_mem != NULL)
		{
			delete m_mem;
			m_mem = NULL;
		}
	}
private:
	CPU * m_cpu; //CPU�����ָ��
	VideoCard  * m_vc; //�Կ����ָ��
	Mermory* m_mem; //�ڴ������ָ��
};

//���峧��
//Intel����
class IntelCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Intel��CPU��ʼ���㣡" << endl;
	}
};

class IntelVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Intel���Կ���ʼ��ʾ��" << endl;
	}
};

class IntelMermory :public Mermory
{
public:
	virtual void storage()
	{
		cout << "Intel���ڴ�����ʼ�洢��" << endl;
	}
};

//Lenovo����
class LenovoCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Lenovo��CPU��ʼ���㣡" << endl;
	}
};

class LenovoVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Lenovo���Կ���ʼ��ʾ��" << endl;
	}
};

class LenovoMermory :public Mermory
{
public:
	virtual void storage()
	{
		cout << "Lenovo���ڴ�����ʼ�洢��" << endl;
	}
};

void test01()
{
	//��һ̨�������
	CPU* intelCpu = new IntelCPU;
	VideoCard* intelCard = new IntelVideoCard;
	Mermory* intelMen = new IntelMermory;

	cout << "��һ̨���Կ�ʼ������" << endl;
	//������һ̨����
	Computer* computer1 = new Computer(intelCpu, intelCard, intelMen);
	computer1->work();
	delete computer1;

	cout << "----------------------" << endl;
	cout << "�ڶ�̨���Կ�ʼ������" << endl;
	//�����ڶ�̨����
	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMermory);
	computer2->work();
	delete computer2;

	cout << "----------------------" << endl;
	cout << "����̨���Կ�ʼ������" << endl;
	//��������̨����
	Computer* computer3 = new Computer(new LenovoCPU, new IntelVideoCard, new LenovoMermory);
	computer3->work();
	delete computer3;
}

int main()
{
	test01();

	system("pause");
	return 0;
}