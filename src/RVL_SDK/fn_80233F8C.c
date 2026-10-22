#pragma force_active on
typedef unsigned char u8;
typedef unsigned long u32;

extern void fn_80232034(u8 *dst, const u8 *src);
extern void *memcpy(void *dst, const void *src, u32 n);
extern char lbl_80529994[];

int fn_80233F8C(u8 *arg0, u8 *unused, u8 *arg2, u8 *arg3) {
    u8 buf[0x110];
    void (*f)(int, void *);

    fn_80232034(buf, arg0);
    memcpy(buf + 6, arg2, 0x1f);
    buf[0x25] = 0;
    memcpy(buf + 0xFF, arg3, 0x10);
    buf[0xFE] = 1;
    buf[0x10F] = 1;
    f = *(void (**)(int, void *))(lbl_80529994 + 0x50);
    if (f != 0) {
        f(3, buf);
    }
    return 1;
}
