#include <stdio.h> // for printf()

long f05(float n) {
	int N=n/0.5;
	long ans=0;
	for(int i=0;i<=N;i++)
	ans+=1;
	return ans;
}
long f1(float n) {
	int N=n/1;
	long ans=0;
	for(int i=0;i<=N;i++)
	ans+=f05(n-1*i);
	return ans;
}
long f5(float n) {
	int N=n/5;
	long ans=0;
	for(int i=0;i<=N;i++)
	ans+=f1(n-5*i);
	return ans;
}
long f10(float n) {
	int N=n/10;
	long ans=0;
	for(int i=0;i<=N;i++)
	ans+=f5(n-10*i);
	return ans;
}
long f20(float n) {
	int N=n/20;
	long ans=0;
	for(int i=0;i<=N;i++)
	ans+=f10(n-20*i);
	return ans;
}
long f50(float n) {
	int N=n/50;
	long ans=0;
	for(int i=0;i<=N;i++)
	ans+=f20(n-50*i);
	return ans;
}
long f100(float n) {
	int N=n/100;
	long ans=0;
	for(int i=0;i<=N;i++)
	ans+=f50(n-100*i);
	return ans;
}




int main() {
	float n;
	while(scanf("%f",&n)!=EOF){
			printf("%ld\n",f100(n));
	}
	
	return 0;
}
