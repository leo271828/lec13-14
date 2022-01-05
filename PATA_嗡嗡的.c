#include<stdio.h>
#include <string.h>


int main () {
    int distance , health , num = 0 , l = 0;//num = 次數(不論什麼指令) , l = 成功次數
    char command[50] = {0};
    scanf("%d%d",&distance,&health);
    getchar();                              //拿掉\n
    while(1){
        int i = 0;                            //這裡
        do{
            command[i] = getchar();
            i++;
        } while (command[i-1] != ',' && command[i-1] != '.' &&command[i-1] != '\n');
        command[i-1] = '\0';                  //到這裡是抓一組字串
        num++;
        if (strcmp(command, "PATA PATA PATA PON") == 0)
        {
            l++;
            distance --;
            if (distance == 0) {
                printf("NO %d", health);
                return 0;
            }
        }
        else if (strcmp(command, "PON PON PATA PON") == 0)
        {
            l++;
            if (distance <= 3) {
                health --;
                if (health == 0) {
                    printf("YES %d", l);
                    return 0;
                }
            }
        }
        else if (strcmp(command, "CHAKA CHAKA PATA PON") == 0)
        {
            l++;
            distance ++;
        }
            if (strcmp(command , "CHAKA CHAKA PATA PON") != 0) {
                if (num == 10 || num==20) {
                    printf("NO %d", health);
                    return 0;
                }
            }
        for(int k = 0 ; k < 50 ; k++){//重製存指令的位置
            command[k] = 0;
        }
        if(num==30) break;
    }
    printf("NO %d",health);
    return 0;
}
