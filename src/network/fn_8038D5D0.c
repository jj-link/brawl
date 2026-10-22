#pragma force_active on
extern int snprintf(char *s, unsigned long n, const char *fmt, ...);
extern char lbl_80490DF4[];

int fn_8038D5D0(unsigned char *arg0, char *arg1) {
    if (arg0 == 0 || arg1 == 0 || *(int *)arg0 == 0 || *(int *)(arg0 + 0x24) == 0) {
        return 0;
    }
    return snprintf(arg1, 0x80, lbl_80490DF4, arg0 + 4, *(int *)(arg0 + 0x14), *(int *)(arg0 + 0x28)) >= 0;
}
