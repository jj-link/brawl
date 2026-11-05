#pragma force_active on

typedef int s32;

extern void fn_8035D498(void *);
extern void fn_8035E00C(void *);
extern void fn_8035C2D8(s32, s32);
extern void closesocket(s32);
extern void fn_8037BBB8(void *);
extern int strncmp(const char *, const char *, unsigned long);
extern char lbl_804905E8[];

void fn_8037C81C(void *arg0) {
    char *p = (char *)arg0;
    s32 tmp;
    void (*fn)(void *, void *);

    *(s32 *)(p + 0x10) = 0;
    tmp = *(s32 *)(p + 0x1B0);
    if (tmp != 0) {
        fn_8035D498((void *)tmp);
        fn_8035E00C((void *)(*(s32 *)(p + 0x1B0)));
        *(s32 *)(p + 0x1B0) = 0;
    }
    fn_8035E00C((void *)(*(s32 *)(p + 0x14)));
    *(s32 *)(p + 0x14) = *(s32 *)(p + 0x12C);
    *(s32 *)(p + 0x12C) = 0;
    fn_8035E00C((void *)(*(s32 *)(p + 0x18)));
    *(s32 *)(p + 0x18) = 0;
    *(s32 *)(p + 0x1C) = 0;
    *(short *)(p + 0x20) = 0;
    fn_8035E00C((void *)(*(s32 *)(p + 0x24)));
    *(s32 *)(p + 0x24) = 0;
    fn_8035C2D8(*(s32 *)(p + 0x4C), 2);
    closesocket(*(s32 *)(p + 0x4C));
    *(s32 *)(p + 0x4C) = -1;
    fn_8037BBB8(p + 0x54);
    fn_8037BBB8(p + 0x78);
    fn_8037BBB8(p + 0x9C);
    fn_8037BBB8(p + 0xC0);
    *(s32 *)(p + 0x10C) = 0;
    *(s32 *)(p + 0x110) = 0;
    *(s32 *)(p + 0x114) = 0;
    *(s32 *)(p + 0x118) = 0;
    *(s32 *)(p + 0x11C) = 0;
    *(s32 *)(p + 0x154) = 0;
    if (*(s32 *)(p + 0x198) != 0) {
        fn = (void (*)(void *, void *))(*(s32 *)(p + 0x1A4));
        if (fn != 0) {
            fn(arg0, p + 0x190);
        }
        *(s32 *)(p + 0x198) = 0;
        if (strncmp((const char *)lbl_804905E8, (const char *)(*(s32 *)(p + 0x14)), 8) != 0) {
            *(s32 *)(p + 0x194) = 0;
            *(s32 *)(p + 0x190) = 0;
        }
    }
    (*(s32 *)(p + 0x130))++;
}