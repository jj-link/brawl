#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern void fn_8034F028(void *, const char *, u32);
extern char *strchr(const char *, int);

s32 fn_80343910(char *arg0, const char *arg1, s32 arg2) {
    const char *s;
    char *end;
    char *p;
    char *q;
    s32 len;
    s32 i;

    s = arg1;
    end = strchr(s, 0);
    for (i = 0; i < arg2; i++) {
        p = strchr(s, 0x2F);
        if (p == 0) {
            return -1;
        }
        s = p + 1;
    }
    q = strchr(s, 0x2F);
    if (q == 0) {
        q = end;
    }
    if (s == q) {
        return -1;
    }
    len = q - s;
    fn_8034F028(arg0, s, len);
    arg0[len] = 0;
    return len;
}
