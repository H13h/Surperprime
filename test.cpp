#include<iostream>
using namespace std;
class SuperPrime;




class Prime//������ 
{
public:
    friend class SuperPrime;//��Ԫ 
    Prime();//���캯�� 
private:
    int prime[1000];//�������� 
    int t = 0;//�������� 
};

class SuperPrime//���������� 
{

public:
    SuperPrime();//SuperPrime���캯�� 
    void showSuperprime();//չʾ�������� 
private:
    int superprime[1000] = {0};//���泬������ 
    int t = 0;//������������ 
    Prime a;//������
};

SuperPrime::SuperPrime()
{
    int g = 0;
    int s = 0;
    int b = 0;
    for(int i = 0; i < a.t; i++)//���ѭ���������� Ѱ�ҳ������� 
    {
        b = a.prime[i] / 100;//��λ 
        s = a.prime[i] % 100 / 10;//ʮλ 
        g = a.prime[i] % 10;//��λ 
        int sum = g + s + b;//��λ�� 
        int sum2 = g*g + s*s + b*b;//��λƽ���� 
        if(sum == 2 && sum2 == 2)//2Ϊ����������� 
        {
            superprime[t] = a.prime[i];
            t++;
        }
        else//һ��������� 
        {
            int flag1 = 0;//�жϱ�־1
            int flag2 = 0;//�жϱ�־2
            for(int j = 2; j < sum; j++)
            {
                if(sum % j == 0)
                {
                    flag1 = 1;
                }
            }//��λ���Ƿ�Ϊ���� 
            for(int j = 2; j < sum2; j++)
            {
                if(sum2 % j == 0)
                {
                    flag2 = 1;
                }
            }//��λƽ�����Ƿ�Ϊ���� 
            if(flag1 == 0 && flag2 == 0)//���߳��� ��Ϊ�������� 
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
    int flag = 0;//�жϱ�־ 
    for(int i = 100; i <= 999; i++)//Ѱ��100-999������
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
        if(flag == 1)//�ж�ʧ�ܣ�������һ���ж� 
            continue;
        else//�жϳɹ����������������������� 
        {
            prime[t] = i;
            t++;
        }
    }
}

int main()
{
    SuperPrime b;//���쳬�����������b 
    b.showSuperprime();//����������� 
    return 0;
}




