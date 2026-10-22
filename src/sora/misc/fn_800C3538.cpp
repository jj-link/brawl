#pragma force_active on
extern "C" {
char* strcat(char*, char*);
int strlen(char*);
extern char lbl_8059E148;

char* fn_800C3538(char* a0, char* a1, int a2) {
    *a0 = 0;
    strcat(a0, &lbl_8059E148);
    int i = 0;
    while (i < a2) {
        a1 += strlen(a1) + 1;
        i++;
    }
    *a0 = 0;
    strcat(a0, a1);
    return a0;
}
}
