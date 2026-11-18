#include <revolution/OS/OSError.h>
#pragma force_active on

extern int fn_801F5F08(const char *);
extern u32 fn_801F6548(int, char *, u32);
extern int lbl_805A08D0;
extern char *lbl_805A08E4;
extern char *lbl_805A08E8;
extern u32 lbl_805A093C;
extern char lbl_80476708[];

static u32 copy(char *dst, const char *src, u32 n) {
    u32 left = n;
    while (left && *src) {
        *dst++ = *src++;
        left--;
    }
    return n - left;
}

#define DEFINE_HELPER(NAME, NEXT)                                      \
static u32 NAME(int idx, char *buf, u32 size) {                       \
    char *name;                                                       \
    u32 len;                                                          \
    if (!idx) return 0;                                               \
    name = lbl_805A08E4 + (*(u32 *)(lbl_805A08E8 + idx * 12) & 0xffffff); \
    len = NEXT(*(int *)((lbl_805A08E8 + 4) + idx * 12), buf, size);   \
    if (len == size) return len;                                      \
    buf[len++] = '/';                                                 \
    return len + copy(buf + len, name, size - len);                   \
}

#pragma inline_depth(4)
DEFINE_HELPER(helper2, fn_801F6548)
DEFINE_HELPER(helper1, helper2)
DEFINE_HELPER(helper0, helper1)

int fn_801F6278(const char *path, u32 *info) {
    char buf[128];
    int entry = fn_801F5F08(path);

    if (entry < 0) {
        int dir = lbl_805A08D0;
        u32 len = helper0(dir, buf, 128);

        if (len == 128) {
            buf[127] = 0;
        } else {
            if (*(u32 *)(lbl_805A08E8 + dir * 12) & 0xff000000) {
                if (len == 127) {
                    buf[len] = 0;
                    goto report;
                }
                buf[len++] = '/';
            }
            buf[len] = 0;
        }
report:
        OSReport(lbl_80476708, path, buf);
        return 0;
    }

    if (*(u32 *)(lbl_805A08E8 + (entry *= 12)) & 0xff000000)
        return 0;

    info[12] = *(u32 *)(lbl_805A08E8 + entry + 4) >> lbl_805A093C;
    info[13] = *(u32 *)(lbl_805A08E8 + entry + 8);
    info[14] = 0;
    info[3] = 0;
    return 1;
}
