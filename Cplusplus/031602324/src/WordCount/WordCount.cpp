#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <cstring>
using namespace std;

void countchar()
{

	ifstream infile;

	infile.open("input.txt", ios::in);   //将文件流对象与文件连接起来 

	assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 


	char c;

	int n = 0;

	infile >> noskipws;
	while (infile.peek() != EOF)
	{

		infile >> c;
		if (c > ' '&&c <= '~')//空格 字母 
			n = n + 1;
		if (c == 9 || c == 10)//水平换行符 ，换行符 
		{
			n = n + 1;
		}
	}



	infile.close();
	ofstream outfile;
	outfile.open("result.txt", ios::out);

	outfile << "characters:" << n << endl;

	outfile.close();//输出 
}


void countword()
{

	ifstream infile;

	infile.open("input.txt", ios::in);   //将文件流对象与文件连接起来 

	assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 

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
			str[wn] = str[wn] + 32;//大写转小写 


		}
		if (str[wn] >= 'a' &&str[wn] <= 'z')
		{

			flag++;

		}
		if (str[wn] == ' ')//当单词结尾是空格时 
		{
			if (flag >= 4)//判断是否有四个字母开头 
			{
				word++;
			}

			flag = 0;




		}

		if (str[wn] == '\n')//单词当结尾是换行符时 
		{
			if (flag >= 4)//判断是否有四个字母开头 
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
	outfile.close();//输出 


}



void countlines()
{
	string str;
	ifstream infile;

	infile.open("input.txt", ios::in);   //将文件流对象与文件连接起来 

	assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 



	int n = 0;

	infile >> noskipws;

	int lines = 0;

	while (getline(infile, str))
	{
		int len = str.length();
		if (len != 0)//当不为空行，行+1 
		{
			lines++;
		}

	}
	infile.close();
	ofstream outfile;
	outfile.open("result.txt", ios::app);
	outfile << "lines:" << lines << endl;
	outfile.close();//输出 

}



int main()
{
	int lines;
	countchar();
	countword();
	countlines();

}

