#include <types.h>
#pragma force_active on

extern void *fn_803A976C(void *dest, int value, u32 size);
extern int fn_803C4B10(char *path, int mode);
extern int fn_803C9ECC(int a, char *b, int c);

int fn_803C4E74(char *src, int arg1) {
    char buf[256];
    char *dst = buf;
    char *s = src;
    int i;
    char c;

    fn_803A976C(dst, 0, 0xFF);
    for (i = 0; i < 0xFF && (c = *s) != 0; i++) {
        if (c == '\\') {
            *dst = '/';
        } else {
            *dst = c;
        }
        s++;
        dst++;
    }
    if (fn_803C4B10(buf, -10) == 0xB001) {
        return fn_803C9ECC(arg1, buf, 0x100);
    }
    return 0;
}
