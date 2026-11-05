#include <string.h>
#pragma force_active on
extern char lbl_8048EA30[14];
extern char lbl_8059F608[8];
extern void fn_803732E0(void **, const void *);
extern void fn_80372DD8(char *, const char *, unsigned long);
extern void fn_8036A328(void **, void *, const char *);
extern void fn_8036A384(void **, void *, int);

int fn_803686D0(void **arg0, int arg1, const char *arg2, const char *arg3) {
    char buf1[256];
    char buf2[256];
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
        fn_803732E0(arg0, strings + 0x140);
        return 2;
    }
    if (arg3 == 0) {
        fn_803732E0(arg0, strings + 0x158);
        return 2;
    }
    fn_80372DD8(buf1, arg2, 0x100);
    p = buf1;
    while ((c = *p) != 0) {
        if (c == '\\') *p = '/';
        p++;
    }
    fn_80372DD8(buf2, arg3, 0x100);
    {
        char *q = buf2;
        char d;
        while ((d = *q) != 0) {
            if (d == '\\') *q = '/';
            q++;
        }
    }
    if (arg1 == *(int *)(data + 0x230) &&
        strcmp(buf1, data + 0x234) == 0 &&
        strcmp(buf2, data + 0x334) == 0) return 0;
    *(int *)(data + 0x230) = arg1;
    fn_80372DD8(data + 0x234, buf1, 0x100);
    fn_80372DD8(data + 0x334, buf2, 0x100);
    fn_8036A328(arg0, data + 0x210, strings + 0x170);
    fn_8036A384(arg0, data + 0x210, arg1);
    fn_8036A328(arg0, data + 0x210, strings + 0xf4);
    fn_8036A384(arg0, data + 0x210, *(int *)(data + 0x198));
    fn_8036A328(arg0, data + 0x210, strings + 0x17c);
    fn_8036A328(arg0, data + 0x210, buf1);
    fn_8036A328(arg0, data + 0x210, strings + 0x18c);
    fn_8036A328(arg0, data + 0x210, buf2);
    fn_8036A328(arg0, data + 0x210, lbl_8059F608);
    return 0;
}