#include<iostream>
#include<string>
using namespace std;
int longs(string s){               //��Կ����
    int len=s.length();
    for (int i=1;i<=10;i++)          //long
    {
        double CI=0;
        for (int j=1;j<=i;j++)          //lie
        {
            double ci[26]={0};
            int g=j-1;          //ÿ�е�һ���Ľű�
            int L=0;
            while(g<=len){
                ci[(int)s[g]-97]++;
                L++;
                g+=i;
            }
            double ic=0;
            for (int k=0;k<26;k++)      //ÿ��ic
            {
                ic=ic+ci[k]*(ci[k]-1)/L/(L+1);
            }
            CI+=ic;
        }
        CI=CI/i;
        if (CI>0.0585&&CI<0.0725){
            return i;
            break;
        }
    }
}
string yiwei(string z){
    int len=z.length();
    for (int i=0;i<len;i++){
        int x=(int)z[i]-97;
        x+=25;
        if (x>25){
            x=x%26;
        }
        x=x+97;
        z[i]=(char)x;
    }
    return z;
}
string miyao(string s,int l){
    int len=s.length();
    string key="";
    for (int i=0;i<l;i++)       //����
    {
        double CI[26]={0.082,0.015,0.028,0.043,0.127,0.022,0.02,0.061,0.07,0.002,0.008,0.04,0.024,0.067,0.075,0.019,0.001,0.06,0.063,0.091,0.028,0.01,0.023,0.001,0.02,0.001};
        string z="";
        int g=i;
        while(g<len){
            z=z+s[g];
            g+=l;
        }
        for (int j=0;j<26;j++)      //��λ,��1��ʼ������󲻱�,ע���Ǽ�����λ
        {
            z=yiwei(z);
            double ci[26]={0};
            for (int k=0;k<z.length();k++){
                ci[(int)z[k]-97]++;
            }
            double M=0;
            for (int k=0;k<26;k++){
                M=M+CI[k]*ci[k]/z.length();
            }
            if(M>0.0585&&M<0.0725){
                int a=j;
                if (a+1>25){                //���a����Ϊ�����Ǵ�1����0��ʼ�ģ����ܸı�j��ֵ����a������
                    a=a%26;
                }
                key=key+(char)(a+1+97);
                //cout<<(char)(a+1+97)<<endl;
            }
        }
    }
    return key;
}
char jiemi(char s,int k){
    int a=(int)s-97;
    a-=k;
    if (a<0){
        a+=26;
    }
    s=(char)(a+97);
    return s;
}
int main(){
    string y;
    string s;
    cout<<"������������ַ�������Сд����ν���з���Ҳ�У�"<<endl;
    cin>>y;
    string z=y;
    bool daxie[z.length()]={0};
    for (int i=0;i<z.length();i++)          //���������������˷��Ż�����
    {
        if (z[i]>='A'&&z[i]<='Z'){
            daxie[i]=1;
        }
        z[i]= tolower(z[i]);
    }
    for (int i=0;i<z.length();i++){         //���˷���
        if (z[i]<'a'||z[i]>'z'){
                //���ﱾ���д����
        }
        else{
            s=s+z[i];
        }
    }
    int l=longs(s);              //��Կ����
    if(l>10){
        cout<<"���ܲ���ά������"<<endl;
        return 0;
    }
    cout<<"��Կ�����ǣ�"<<l<<endl;
    string key=miyao(s,l);
    cout<<"��Կ�ǣ�"<<key<<endl;
    int k=0;
    string mingwen="";
    for (int i=0;i<z.length();i++){         //����
        if (k>=l){
            k=k%l;
        }
        if (y[i]>='a'&&y[i]<='z'){       //Сд����
            mingwen+=jiemi(y[i],(int)key[k]-97);
            k++;
        }
        else if (y[i]>='A'&&y[i]<='Z'){
            y[i]=tolower(y[i]);
            mingwen+=toupper(jiemi(y[i],(int)key[k]-97));       //ֱ�����toupper��Ȼ�����֣������޷�
            k++;
        }
        else{
            mingwen+=y[i];
        }
    }
    cout<<mingwen<<endl;
}
//��������
//CHREEVOAHMAERATBIAXXWTNXBEEOPHBSBQMQEQERBWRVXUOAKXAOSXXWEAHBWGJMMQMNKGRFVGXWTRZXWIAKLXFPSKAUTEMNDCMGTSXMXBTUIADNGMGPSRELXNJELXVRVPRTULHDNQWTWDTYGBPHXTFALJHASVBFXNGLLCHRZBWELEKMSJIKNBHWRJGNMGJSGLXFEYPHAGNRBIEQJTAMRVLCRREMNDGLXRRIMGNSNRWCHRQHAEYEVTAQEBBIPEEWEVKAKOEWADREMXMTBHH VKAKOEWADREMXMTBHHCHRTKDNVRZ TKDNVRZCHRCLQOHPWQAIIWXNRMGWOIIFKEE
//BZGTNPMMCGZFPUWJCUIGRWXPFNLHZCKOAPGLKYJNRAQFIUYRAVGNPANUMDQOAHMWTGJDXGOMPJPTKAAVZIUIWKVTUCWBWNFWDFUMPJWPMQGPTNWXTSDPLPMWJAXUHHXWPFXXGVAPFNTXVFKOYIRBOQJHCBVWVFYCGQFGUSUBDWVIYATJGTBNDKGHCTMTWIUEFJITVUGJHHIMUVJICUWYQWYGGUWPUUCWIFGWUANILKPHDKOSPJTTWJQOJHXLBJAPZHVQWPDYPGLLGDBCHTGIZCCMEGVIIJLIFFBHSMEGUJHRXBOQUBDNASPEUCWNGWSNWXTSDPLPMWJAIUHUMWPSYCTUWFBMIAMKVBNTDMQNBVDKILQSSDYVWVXIGDQFIBHSLEAVDBXGOLGDBCHTGIZVNFQFKTNGRWXUDCTGKWCOXIXKZPPFDZG
