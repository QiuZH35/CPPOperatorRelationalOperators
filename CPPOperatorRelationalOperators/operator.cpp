
#include <iostream>
using namespace std;

class CGirl
{
	friend bool operator==(const CGirl& g1, const CGirl& g2);
private :
	//ԽС��ֵԽ��
	string m_name;  //����
	int m_yz;//��ֵ
	int m_sc;//���
	int m_acting;//�ݼ�

public:
	CGirl(string name, int yz, int sc, int acting)
	{
		m_name = name;
		m_yz = yz;
		m_sc = sc;
		m_acting = acting;
	}
	//���ع�ϵ����������������Ƚϣ������Ա�����д���һ���Ƚ��࣬���ֻ��һ������
	// ��ϵ������Ƚϼ򵥣�û�ж���Ŀ�
	// 
	//�Ƚ�������Ů����ҵ��ֵ  ==  <  >  <=  >=  !=
	//bool operator==(const CGirl& g1)
	//{
	//	if ((m_yz + m_sc + m_acting) == (g1.m_acting + g1.m_sc + g1.m_yz))return true;
	//	return false;
	//}
	bool operator>(const CGirl& g1)
	{
		if ((m_yz + m_sc + m_acting) < (g1.m_acting + g1.m_sc + g1.m_yz))return true;
		return false;

	}
	bool operator<(const CGirl& g1)
	{
		if ((m_yz + m_sc + m_acting) > (g1.m_acting + g1.m_sc + g1.m_yz))return true;
		return false;

	}
};
bool operator==(const CGirl& g1,const CGirl& g2)  //�ǳ�Ա�����汾
{
	if ( (g1.m_acting + g1.m_sc + g1.m_yz)==(g2.m_yz + g2.m_sc + g2.m_acting) )return true;
	return false;
}

int main()
{
	CGirl g1("��ʩ", 1, 2, 3), g2("�Ѿ�", 2, 1, 3);
	if (g1 == g2)
	{
		cout << "��ʩ���Ѿ���ҵ��ֵһ��" << endl;
	}
	else
		if (g1 < g2)
		{
			cout << "��ʩ��ҵ��ֵ���Ѿ�С" << endl;
		}
		else
		{
			cout << "��ʩ��ҵ��ֵ���Ѿ���" << endl;
		}

	return 0;
}