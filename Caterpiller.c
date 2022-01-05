void swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverse_caterpillar(char *l, char *r) {
    for(char *l_p = l, *r_p = r, *idx = l ; idx < r ; l_p++, r_p--, idx+=2)
        swap(l_p, r_p);
        
}

void lineup_again(char line[]) {
    int len = 0;
    char *p = line;
    for(char *tmp = line;*(tmp) != '\0';tmp++, len++){}
    for(int i=0 ; p < line + len ; i++, p++){
        if(*p == 'Z'){
            int end=1;
            while(*(p+end) != 'A') end++;
            char *p_end = p + end;
            reverse_caterpillar(p, p_end);
            p+=(end);
        }
        else if(*p == 'A')
            while(*p != 'Z') p++;
    }
}
