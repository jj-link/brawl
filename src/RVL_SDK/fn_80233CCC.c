#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

extern void fn_80232034(u8 *dst, const u8 *src);
extern char *strncpy(char *dst, const char *src, u32 n);
extern u32 lbl_8040D768[];
extern char lbl_80529994[];

int fn_80233CCC(const u8 *arg0, int unused1, const char *arg2, int unused2, u32 arg4) {
    u8 buf[0x110];
    u8 i;
    void (*func)(int, void *);

    i = 1;
    fn_80232034(buf, arg0);
    strncpy((char *)(buf + 6), arg2, 0x20);

    for (; i <= 0x17; i++) {
        if (arg4 == lbl_8040D768[i]) {
            buf[0xFE] = i;
            break;
        }
    }

    func = *(void (**)(int, void *))(lbl_80529994 + 0x50);
    if (func != 0 && i <= 0x17) {
        func(4, buf);
        return 1;
    }
    return 0xB;
}
