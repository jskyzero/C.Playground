#include<stdio.h>
int main(){
	float n;
	int m,a,b,c,d,e,f,g,h,s=0;
	while(scanf("%f",&n)!=EOF){
		m=n*10;
        for(a=0;a<=m/1000;a++){
            for(b=0;b<=m/500;b++){
                for(c=0;c<=m/200;c++){
                    for(d=0;d<=m/100;d++){
                        for(e=0;e<=m/50;e++){
                            for(f=0;f<=m/10;f++){
                                for(g=0;g<=m/5;g++){
                                	for(h=0;h<=m;h++){
                                    if(m==a*1000+b*500+c*200+d*100+e*50+f*10+g*5+h)
                                    s++;
									}
                                }
							}
						}
					}
				}
			}
		}
        printf("%d\n",s);
        s=0;
	}
}
