#include<iostream>
using namespace std;

int main(){
    int A[5];
    for(int i=0;i<5;i++){
        cin>>A[i];
    }
    for(int i=0;i<32768;i++){
        bool p[15];
        for(int j=1;j<16;j++){
            if(i%(2^j)==1){
                p[j-1]=1;
                i=i-2^(j-1);
            }
            else{
                p[j-1]=0;
            }
        }
        if((p[0]+p[1]+p[2]+p[3]+p[4]==A[0])&&(p[0]+p[5]+p[6]+p[7]+p[8]==A[1])&&(p[1]+p[5]+p[9]+p[10]+p[11]==A[2])&&(p[2]+p[6]+p[9]+p[12]+p[13]==A[3])&&(p[3]+p[7]+p[10]+p[12]+p[14]==A[4])){
            for(int i=0;i<16;i++){
                if(p[i]=1){
                    cout<<i+1<<" ";
                }
            }
            cout<<endl;
        }
    }


}
