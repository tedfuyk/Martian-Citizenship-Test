#include <bits/stdc++.h>
#include <fstream>

using namespace  std;
int N;
int Ans;
int T;
ofstream outfile("output.txt");

struct Save{
	int maxn,num,id;
	bool operator >(const Save& save)const{
		return maxn!=save.maxn?maxn>save.maxn:num<save.num;
	}
};

void init(){
	/*puts("input N : ");
	cin>>N;*/
	//puts("input Ans : ");
	//cin>>Ans;
	outfile<<"N = "<<N<<endl<<"Ans = "<<Ans<<endl;
	return ;
}

int Xor(int a,int b){
	int x=a^b;
	int re=0;
	while(x!=0){
		re+=x%2;
		x/=2;
	}
	return re;
}

int check(int a){
	T++;
	int x=Xor(a,Ans);
	if(x==0) outfile<<"#Done "<<T<<endl;
	return x;
}

int guess(vector<int> *v){
	priority_queue<Save,vector<Save>,greater<Save> > pq;
	for(int i=0;i<1<<N;i++){
		map<int,int> m; int maxn=1;
		for(int j=0;j<(int)(*v).size();j++){
			int x=Xor(i,(*v)[j]);
			if(m.find(x)!=m.end()){
				m[x]++;
				maxn=max(maxn,m[x]);
			}
			else m[x]=1;
		}
		pq.push({maxn,(int)m.size( ), i } );
	}
	return pq.top().id;
}

void change(vector<int> *v,int gnum,int xnum){
	vector<int> ve;
	for(int i=0;i<(int)(*v).size();i++){
		if(Xor((*v)[i],gnum)==xnum){
			ve.push_back((*v)[i]);
		}
	}
	(*v)=ve;
	return ;
}

void fguess(vector<int> *v){
	outfile<<"#guess 0"<<endl;
	int x=check(0);
	for(int i=0;i<1<<N;i++){
		if(Xor(i,0)==x){
			(*v).push_back(i);
		}
	}
	return ;
}

int main(){
	vector<int> vec;
	int p;
	int c;
	for(int a=5;a<14;a++) {
		for(int b=1;b<int(a/2)+1;b++) {
			int maxnn=0;
			p=a;
			c=b;
			int f=p-c;
			int sum=0;
			for(int i=0;i<p;i++){
				if(i<f)	vec.push_back(0);			
				else vec.push_back(1);
			}
			do{
				for(int i=0;i<vec.size();i++){
			 		sum=sum+vec[i]*pow(2,i);
				}
				N=p;
				Ans=sum;
				init();
				bool tf=false;
				T=0;
				vector<int> v;
				fguess(&v);
				while(v.size()!=1){
					int g=guess(&v);
					outfile<<"#guess "<<g<<endl;
					int c=check(g);
					if(c==0){
						tf=true;
						maxnn=max(maxnn,T);
					}
					change(&v,g,c);
				}
				if(!tf){
					outfile<<"#guess "<<v[0]<<endl;
					check(v[0]);
					maxnn=max(maxnn,T);
				}
				outfile<<"maxT"<<maxnn<<endl;
				outfile<<endl<<endl<<endl;
				sum=0;
			}while (next_permutation(vec.begin(),vec.end()));
			vec.clear();
			outfile<<"-----------------------------"<<endl;
		}
	}
return 0;
}
