#pragma force_active on
extern void fn_8036A328(void **, void *, const char *);
extern void fn_8036A384(void **, void *, int);
extern char lbl_8059F7E0[8];
extern char jumptable_8048F1C0[];

int fn_8036D1B4(void **arg0, void *arg1)
{
    char *table = jumptable_8048F1C0;
    char *data = (char *)*arg0;

    if (*(int *)(data + 0x464) > 0) {
        fn_8036A328(arg0, arg1, table + 0xF8);
        fn_8036A384(arg0, arg1, *(int *)(data + 0x198));
        fn_8036A328(arg0, arg1, *(const char **)(data + 0x45C));
        fn_8036A328(arg0, arg1, table + 0x110);
        fn_8036A384(arg0, arg1, *(int *)(data + 0x1A4));
        fn_8036A328(arg0, arg1, lbl_8059F7E0);
        *(int *)(data + 0x464) = 0;
    }
    if (*(int *)(data + 0x474) > 0) {
        fn_8036A328(arg0, arg1, table + 0x11C);
        fn_8036A384(arg0, arg1, *(int *)(data + 0x198));
        fn_8036A328(arg0, arg1, *(const char **)(data + 0x46C));
        fn_8036A328(arg0, arg1, lbl_8059F7E0);
        *(int *)(data + 0x474) = 0;
    }
    return 0;
}
