#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#include"Queue_ToNext.h"
//#define MAX 255;
using namespace std;

const int MAX=255;

int main(int argc,char **argv)
{
/*读模式文件，得到模式串数字patt，patt_num记录模式串个数,patt_maxlen记录最长模式串长度,patt_len存放每个模式串的长度*/
     ifstream in("Pattern");
     string patt[MAX]{""};
    int i=0;
    while(in>>patt[i])
      { 
           i++;
      }
    int patt_num=i;
    int patt_maxlen=0;
    int patt_len[patt_num];
   for(i=0;i<patt_num;i++)
      {
         if(patt[i].size>patt_maxlen)
              patt_maxlen=patt[i].size;
              patt_len[i]=patt[i].size;
     }

//   for (i=0;i<patt_num;i++)
  //  cout<<patt[i][2]<<endl;

   int Next[MAX];     //定义Next，Base，Check数组，Nextres记录状态对应的字符
   char Nextres[MAX];
    bool Nextif[MAX]={0};
   int Nextne=0;
   int Base[MAX];
   int Check[MAX];
   int Fail[MAX];
   int Output[MAX];
//两个队列数组
 LinkQueue L1[patt_num];
 LinkQueue *L1ptr=L1;
 for(i=0;i<patt_num;i++)
    InitQueue(L1ptr+i);
 LinkQueue L2[patt_num];
 LinkQueue *L2ptr=L2;
  for(i=0;i<patt_num;i++)
    InitQueue(L2ptr+i);

/*分层处理，最大层深度为最长串的长度*/
Next[0]=0;
Nextres[0]="";
Nextif[0]=1;
Nextne=1;
Check[0]=0;
Fail[0]=0;
Output[0]=0;
int j=0,k=0,a=0,b=0,l=0,t=0,x=0;
bool flag=false;
string tem[MAX]{""};
int temlen=0;
string curr[MAX]{""};
for(i=1;i<=patt_maxlen;i++)
{
   a=0;
   tem[a]="";
   curr[MAX]={""};
   for(j=0;j<patt_num;j++)
     {  
      if(i=1)
         curr[j]="";
      else{
            for(k=0;k<i-1;k++)
            curr[j]=curr[j]+patt[j][k];
         
         }
     b=0;
      while(b<=a)  
          { if(curr[j]==tem[b])
            flag=true;
          }
     if(flag=false)
          { 
            L1[l]->front->current=curr[j];//头结点初始化为前缀
            l++;
            tem[a]=curr[j];
            a++;
          }
      }
     
     for(k=0;k<patt_num;k++)
       {  curr[k]="";
          if(i=1)
             curr[k]="";
         else
          { 
             for(b=0;b<i-1;b++)
                  curr[k]=curr[k]+patt[k][b]; 
          }
           for(b=0;b<=l;b++)
              {
                  if(L1[b]->front->current==curr[k])
                       if (!EnQueue(L1ptr+b,patt[k][i-1],k))
                          {
                            cout<<i<<"::EnQueue:::"<<k<<endl;
                             return 0;
                          }
              }
         
          
        }
       int ind_a=0;
       for(k=0;k<=l;k++)
           {   
              for(b=0;b<L1[k].count;b++)
                 {	
   			string a[L1[k].count]={""};
             		string *aptr=a;
             		if(!DelQueue(L1ptr+k,aptr+b))
                           {
  				cout<<i<<"::DelQueue:::"<<k<<endl;
                             return 0;
			   }
    		 }
               char aa[L1[k].count];
               char *bb=aa;
               for(b=0;b<L1[k].count;b++)
                  {
                      aa[b]=a[b][0];
                  }
               Sort(bb,strlen(aa)); //排序，使得字符按照从小到大排列
                /*构造Next，Check，Base*/
                 int c[strlen(aa)];
                  c[0]=Nextne;
               for(b=0;b<strlen(aa);b++)
                  
              
           }
    
  }
}
