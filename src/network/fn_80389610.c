#include <string.h>
#include <stdio.h>
#pragma force_active on
extern char *lbl_804901F0[];
extern char lbl_8059FBC0[4];
extern void fn_80388498(unsigned char *, unsigned char);
extern int fn_8038A904(void *, char *, int, int, int);
extern void fn_8035D774(unsigned int);
extern void fn_8038831C(void *);
extern int fn_8038D2E8(void *);
int fn_80389610(unsigned char *obj, int flag, int value, unsigned char *keys, int count, int a, int b, int c)
{
    char buf[256] = {0};
    unsigned char *p;
    char **table = lbl_804901F0;
    char *name;
    int len = 0;
    int i;
    int result;
    *(int *)(obj + 0x828) = value;
    p = keys;
    *(int *)(obj + 0x40) = 0;
    for (i = 0; i < count; i++, p++) {
        name = table[*p];
        if ((int)(len + strlen(name) + 1) >= 256)
            break;
        len += sprintf(buf + len, lbl_8059FBC0, name);
        fn_80388498(obj, *p);
    }
    result = fn_8038A904(obj + 0x4c, buf, a, b, c);
    if (result != 0)
        return result;
    if (flag == 0) {
        while (*(int *)(obj + 0x4c) == 3 || (*(int *)(obj + 0x10) > 0 && result == 0)) {
            fn_8035D774(10);
            fn_8038831C(obj);
            result = fn_8038D2E8(obj + 0x4c);
        }
    }
    return result;
}