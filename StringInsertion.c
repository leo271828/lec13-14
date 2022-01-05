void strins(char *P, char *s, char *t) {
    int p_len = strlen(P), s_len = strlen(s), t_len = strlen(t);
    char *p = P;
    for(int i=0; i < (p_len - s_len) ; i++){
        char buf[MAX_LEN_S], newp[MAX_LEN_P];
        strncpy(buf, p+i, s_len);
        if( strstr(buf, "\n") )
            continue;
        if( strcmp(buf, s) == 0 ){
            i += s_len;
            strncpy(newp, p, i);
            newp[i] = '\0';
            strcat(newp, t);
            strcat(newp, p + i);
            strcpy(p, newp);
            p_len = strlen(P);
        }
    }
}
