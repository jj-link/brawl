#pragma force_active on
extern "C" {
char* strcat(char*, char*);
extern char lbl_8059E148;

char* fn_800C34D8(char* a0, char* a1) {
    *a0 = 0;
    strcat(a0, &lbl_8059E148);
    *a0 = 0;
    strcat(a0, a1);
    return a0;
}
}