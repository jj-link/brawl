#pragma force_active on
extern void fn_803520B8(void *a, void *b, unsigned long long c, int e, int f);
extern void *memset(void *s, int c, unsigned int n);
extern char *strncpy(char *d, const char *s, unsigned int n);

extern char lbl_80534200[];
extern int lbl_8059F1CC;
extern int lbl_8059F1D0;
extern char *lbl_805A0FD4;

int fn_80352260(const char *arg0, int arg1, int arg2)
{
    fn_803520B8(&lbl_8059F1CC, &lbl_8059F1D0, 0, arg1, arg2);
    memset(lbl_80534200, 0, 0x174);
    strncpy(lbl_805A0FD4 + 0x41BE, arg0, 5);
    *(int *)(lbl_805A0FD4 + 0x59E4) = 2;
    return 1;
}
