#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string dashuxiangjian(string s1,string s2)
{
    //因为在主函数已经确定s1的长度必将大于等于s2长度,所以以下并未考虑s2.length>s1.length的情况
    string s3;
    int len1=s1.size()-1;
    int len2=s2.size()-1;
    string str="";   //用来储存结果
    while(len1>=0&&len2>=0)
    {
        int t=s1[len1]-s2[len2];  //储存此位的结果
        if(t<0)   //如果t<0代表需要进借位
        {
            t+=10;
            if(s1[len1-1]=='0') //如果上位等于0,则需要再往上一位借
            {
                int len=len1-1;
                while(len--)  //直到某一上位不为0
                {
                    if(s1[len]!='0')
                        break;
                }
                for(int i=len+1;i<=len1-1;i++)  //从不为0的上位的下一位到需要借位的上一位均变为9
                    s1[i]='9';
                s1[len]--;   //不为0的上位减一;
            }
            else     //上位不为0则直接减一
                s1[len1-1]--;
        }
        str+=t+'0';  //此位的结果储存到字符串str里
        --len1;
        --len2;
    }
    while(len1>=0)   //如果len1最后不为0,把s1剩余的位数拷贝到str里
    {
        str+=s1[len1];
        --len1;
    }
    int i;
    reverse(str.begin(),str.end()); //因为我们是从个位开始往后存储的，所以需要给结果逆序
    for(i=0;i<str.size();i++)   //判断前导是否为0
        if(str[i]!='0')
            break;
    if(i==str.size())   //如果str所有位数均为0则结果为0
        return "0";
    else        //反之删除前导0
        str.erase(str.begin(),str.begin()+i);
    return str;
}
int main()
{
    string s1,s2,s,s3;
    while( cin >> s1 >> s2)
    {
        int flag=0;  //旗帜,表示结果是否为负数
        //这里
        if(s1.size()<s2.size())  //如过减数比被减数小,将被减数和减数换值
        {
            flag = 1;
            s3=s1;
            s1=s2;
            s2=s3;
        }
        if(s1.size()==s2.size())  //同上
        {
            for(int i=0;i<s1.size();i++)
            {
                if(s1[i] == s2[i])
                    continue;
                if(s1[i]<s2[i])
                {
                    flag = 1;
                    s3=s1;
                    s1=s2;
                    s2=s3;
                }
                else
                    break;
            }
        }
        //到这里都是为了判断结果是否为负数。
        if(flag==1)
            cout << '-';
        s=dashuxiangjian(s1,s2);
        cout << s << endl;
    }
    return 0;
}


