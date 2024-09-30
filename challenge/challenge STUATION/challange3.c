#include <stdio.h>
#include <stdlib.h>
int main() {
int list[5]={0,1,2,3,4};
int n;
printf("entre le nomber pour edit : ");
scanf("%d",&n);
for(int i=0;i<= 5;i++){
    if(list[i] == n){
        printf("entrer nouveaux valeur: ");
        scanf("%d",& list[i]);
    }
}

for(int i=0;i<= 5;i++){
    printf("%i",list[i]);
}
 return 0;

}
