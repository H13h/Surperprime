#include<iostream>
using namespace std;
class SuperPrime;




class Prime//素数类 
{
public:
    friend class SuperPrime;//友元 
    Prime();//构造函数 
private:
    int prime[1000];//储存素数 
    int t = 0;//素数个数 
};

class SuperPrime//超级素数类 
{

public:
    SuperPrime();//SuperPrime构造函数 
    void showSuperprime();//展示超级素数 
private:
    int superprime[1000] = {0};//储存超级素数 
    int t = 0;//超级素数个数 
    Prime a;//素数类
};

SuperPrime::SuperPrime()
{
    int g = 0;
    int s = 0;
    int b = 0;
    for(int i = 0; i < a.t; i++)//外层循环遍历素数 寻找超级素数 
    {
        b = a.prime[i] / 100;//百位 
        s = a.prime[i] % 100 / 10;//十位 
        g = a.prime[i] % 10;//个位 
        int sum = g + s + b;//个位和 
        int sum2 = g*g + s*s + b*b;//各位平方和 
        if(sum == 2 && sum2 == 2)//2为特殊情况讨论 
        {
            superprime[t] = a.prime[i];
            t++;
        }
        else//一般情况讨论 
        {
            int flag1 = 0;//判断标志1
            int flag2 = 0;//判断标志2
            for(int j = 2; j < sum; j++)
            {
                if(sum % j == 0)
                {
                    flag1 = 1;
                }
            }//个位和是否为素数 
            for(int j = 2; j < sum2; j++)
            {
                if(sum2 % j == 0)
                {
                    flag2 = 1;
                }
            }//个位平方和是否为素数 
            if(flag1 == 0 && flag2 == 0)//两者成立 即为超级素数 
            {
                superprime[t] = a.prime[i];
                t++;
            }
        }
    }
}

void SuperPrime::showSuperprime()
{
    for(int i = 0; i < t; i++)
    {
        cout << superprime[i] << endl;
    }
}


Prime::Prime()
{
    int flag = 0;//判断标志 
    for(int i = 100; i <= 999; i++)//寻找100-999的素数
    {
        flag = 0;
        for(int j = 2; j < i; j++)
        {
            if(i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)//判断失败，进行下一次判断 
            continue;
        else//判断成功，将超级素数储存入数组 
        {
            prime[t] = i;
            t++;
        }
    }
}

int main()
{
    SuperPrime b;//建造超级素数类变量b 
    b.showSuperprime();//输出超级素数 
    return 0;
}




