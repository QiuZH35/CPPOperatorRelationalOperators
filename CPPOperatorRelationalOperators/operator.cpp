
#include <iostream>
using namespace std;

class CGirl
{
	friend bool operator==(const CGirl& g1, const CGirl& g2);
private :
	//越小价值越高
	string m_name;  //姓名
	int m_yz;//颜值
	int m_sc;//身材
	int m_acting;//演技

public:
	CGirl(string name, int yz, int sc, int acting)
	{
		m_name = name;
		m_yz = yz;
		m_sc = sc;
		m_acting = acting;
	}
	//重载关系运算符，由于两两比较，在类成员函数中存在一个比较类，因此只需一个参数
	// 关系运算符比较简单，没有多余的坑
	// 
	//比较两个超女的商业价值  ==  <  >  <=  >=  !=
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
bool operator==(const CGirl& g1,const CGirl& g2)  //非成员函数版本
{
	if ( (g1.m_acting + g1.m_sc + g1.m_yz)==(g2.m_yz + g2.m_sc + g2.m_acting) )return true;
	return false;
}

int main()
{
	CGirl g1("西施", 1, 2, 3), g2("昭君", 2, 1, 3);
	if (g1 == g2)
	{
		cout << "西施和昭君商业价值一致" << endl;
	}
	else
		if (g1 < g2)
		{
			cout << "西施商业价值比昭君小" << endl;
		}
		else
		{
			cout << "西施商业价值比昭君大" << endl;
		}

	return 0;
}