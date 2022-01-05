#include<stdio.h>
#include<string.h>
#include<ctype.h>

void swap(char **a, char **b){
    char *tmp = *a;
    *a = *b;
    *b = tmp;
}
int L_bigger_R(char *a, char *b){
    for(int i=0; ;i++){
        if( *(b + i) == '\0' ){
            return 1;
        } 
        else if ( *(a + i) == '\0' ){
            return 0;
        }

        int A = toupper(*(a + i)), B = toupper(*(b + i));
        if( A > B ){
            return 1;
        }
        else if( A < B ){
            return 0;
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int stu_number[n];
    char stu[n][10000], *p[n];
    for(int i=0;i<n;i++){
        scanf("%s", stu[i]);
        p[i] = stu[i];
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<n-1;j++)
            if( L_bigger_R(p[j], p[j+1]) )
                swap( &p[j], &p[j+1]);

    for(int i=0;i<n;i++)
        printf("%s\n", p[i]);
    return 0;
}
