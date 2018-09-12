#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <cstring>
using namespace std;

void countchar()
{

	ifstream infile;

	infile.open("input.txt", ios::in);   //���ļ����������ļ��������� 

	assert(infile.is_open());   //��ʧ��,�����������Ϣ,����ֹ�������� 


	char c;

	int n = 0;

	infile >> noskipws;
	while (infile.peek() != EOF)
	{

		infile >> c;
		if (c > ' '&&c <= '~')//�ո� ��ĸ 
			n = n + 1;
		if (c == 9 || c == 10)//ˮƽ���з� �����з� 
		{
			n = n + 1;
		}
	}



	infile.close();
	ofstream outfile;
	outfile.open("result.txt", ios::out);

	outfile << "characters:" << n << endl;

	outfile.close();//��� 
}


void countword()
{

	ifstream infile;

	infile.open("input.txt", ios::in);   //���ļ����������ļ��������� 

	assert(infile.is_open());   //��ʧ��,�����������Ϣ,����ֹ�������� 

	char c, wd;
	int n = 0, flag = 0, word = 0;
	//int xx=0;
	char str[9999];
	infile >> noskipws;
	while (infile.peek() != EOF)
	{

		infile >> c;

		str[n] = c;

		n = n + 1;
	}

	for (int wn = 0; wn < n; wn++)
	{



		if (str[wn] >= 'A'&&str[wn] <= 'Z')
		{
			str[wn] = str[wn] + 32;//��дתСд 


		}
		if (str[wn] >= 'a' &&str[wn] <= 'z')
		{

			flag++;

		}
		if (str[wn] == ' ')//�����ʽ�β�ǿո�ʱ 
		{
			if (flag >= 4)//�ж��Ƿ����ĸ���ĸ��ͷ 
			{
				word++;
			}

			flag = 0;




		}

		if (str[wn] == '\n')//���ʵ���β�ǻ��з�ʱ 
		{
			if (flag >= 4)//�ж��Ƿ����ĸ���ĸ��ͷ 
			{
				word++;
			}

			flag = 0;




		}


	}
	infile.close();

	ofstream outfile;
	outfile.open("result.txt", ios::app);
	outfile << "word:" << word << endl;
	outfile.close();//��� 


}



void countlines()
{
	string str;
	ifstream infile;

	infile.open("input.txt", ios::in);   //���ļ����������ļ��������� 

	assert(infile.is_open());   //��ʧ��,�����������Ϣ,����ֹ�������� 



	int n = 0;

	infile >> noskipws;

	int lines = 0;

	while (getline(infile, str))
	{
		int len = str.length();
		if (len != 0)//����Ϊ���У���+1 
		{
			lines++;
		}

	}
	infile.close();
	ofstream outfile;
	outfile.open("result.txt", ios::app);
	outfile << "lines:" << lines << endl;
	outfile.close();//��� 

}



int main()
{
	int lines;
	countchar();
	countword();
	countlines();

}

