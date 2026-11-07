#include <types.h>
#pragma force_active on
extern void *fn_803A976C(void *, int, u32);
extern int fn_803C7058(char *);

char *fn_803C35A8(int *out, char *path) {
    char buf[8];
    char *p = path;
    int len = 0;
    char *result = path;
    char *dst;
    char c;
    *out = -1;
    fn_803A976C(buf, 0, 8);
    dst = buf;
    while ((c = *p) != 0) {
        if (c == '\\' || c == '/') break;
        if (c == ':') {
            *out = fn_803C7058(buf);
            if (*out == -1 || len > 7)
                result = 0;
            else
                result = p + 1;
            break;
        }
        if (len < 7) *dst = c;
        p++;
        dst++;
        len++;
    }
    return result;
}