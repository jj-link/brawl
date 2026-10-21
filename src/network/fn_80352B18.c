#pragma force_active on
extern char lbl_80534030[];
char *strcpy(char *dst, const char *src);

void fn_80352B18(char *arg1, char *arg2) {
    strcpy(arg1, &lbl_80534030[4]);
    strcpy(arg2, &lbl_80534030[0x131]);
}
