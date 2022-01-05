#include<stdio.h>
#include<string.h>
#define N 1000


int main(){
    int distance, monster_blood, num = 0, idx = 0;
    char str[N][N];
    scanf("%d%d\n", &distance, &monster_blood);

    // Input data
    char tmp = getchar();
    while(tmp != '\n'){
        str[num][idx++] = tmp;
        tmp = getchar();
        if( tmp == ',' || tmp == '.' ){
            str[num][idx] = '\0';
            num++;
            idx = 0;
            tmp = getchar();
        }
    }
    // Compute the data
    int allow_cmd = 0, def_flag = 0;
    for(int i=0;i<=num && i<30;i++){
        def_flag = 0;
        if( strcmp(str[i], "PATA PATA PATA PON") == 0 ){
            allow_cmd++;
            distance--;
            if( distance <= 0 ){
                printf("NO %d\n", monster_blood);
                return 0;
            }
        }
        else if( strcmp(str[i], "PON PON PATA PON") == 0 ){
            allow_cmd++;
            if( distance <= 3 ) monster_blood--;
            if( monster_blood <= 0 ){
                printf("YES %d\n", allow_cmd);
                return 0;
            }
        }
        else if( strcmp(str[i], "CHAKA CHAKA PATA PON") == 0 ){
            allow_cmd++;
            distance++;
        }
        if( strcmp(str[i], "CHAKA CHAKA PATA PON") != 0 )
            if( (i+1) == 10 || (i+1) == 20 ){
                printf("NO %d\n", monster_blood);
                return 0;
            }
    }
    printf("NO %d\n", monster_blood);
    return 0;
}
