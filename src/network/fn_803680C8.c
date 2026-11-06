#pragma force_active on
extern char lbl_8048EA30[14];
extern char lbl_8059F608[8];
extern void fn_803732E0(void **, const void *);
extern void fn_80372DD8(char *, const char *, unsigned long);
extern void fn_8036A328(void **, void *, const char *);
extern void fn_8036A384(void **, void *, int);

int fn_803680C8(void **arg0, int arg1, const char *arg2) {
    char buf[0x401];
    char *p;
    char c;
    char *strings = lbl_8048EA30;
    char *data;
    if (arg0 == 0 || (data = *arg0) == 0) return 2;
    if (*(int *)(data + 0x108) != 0) return 0;
    if (*(int *)(data + 0x1f4) == 4) {
        fn_803732E0(arg0, strings + 0x84);
        return 2;
    }
    if (arg2 == 0) {
        fn_803732E0(arg0, strings + 0xd8);
        return 2;
    }
    fn_80372DD8(buf, arg2, 0x401);
    p = buf;
    while ((c = *p) != 0) {
        if (c == '\\') *p = '/';
        p++;
    }
    fn_8036A328(arg0, data + 0x210, strings + 0xe8);
    fn_8036A328(arg0, data + 0x210, strings + 0xf4);
    fn_8036A384(arg0, data + 0x210, *(int *)(data + 0x198));
    fn_8036A328(arg0, data + 0x210, strings + 0x100);
    fn_8036A384(arg0, data + 0x210, arg1);
    fn_8036A328(arg0, data + 0x210, strings + 0x110);
    fn_8036A328(arg0, data + 0x210, buf);
    fn_8036A328(arg0, data + 0x210, lbl_8059F608);
    return 0;
}