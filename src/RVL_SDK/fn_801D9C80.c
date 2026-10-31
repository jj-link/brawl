#pragma force_active on
extern void fn_801D7184(int);
extern void fn_801D716C(int);
extern unsigned int fn_801D718C(int, int);
extern void fn_801DF700(void);
extern int fn_801E38A8(void);
extern void fn_801E3B04(void);
extern void fn_801E3E20(int, int *, int *);
extern int fn_80211080(void);
extern int fn_8021111C(int, int, unsigned int);
extern int fn_802112C8(int, int, unsigned int, int *);
extern int fn_802113E0(int, unsigned int);
extern int fn_80211720(int *);
extern void *memcpy(void *, const void *, int);
extern void *memset(void *, int, int);

void fn_801D9C80(void)
{
    __declspec(align(32)) int locals_storage[10];
    int *locals = locals_storage - 8;
    int result;
    unsigned int buf;
    unsigned int buf2;
    unsigned int zero;

    locals[10] = 1;
    fn_801D7184(0x81280000);
    fn_801D716C(0x812F0000);

    if (fn_80211080() != 0) {
        fn_801DF700();
    }

    if (fn_80211720(&locals[16]) != 0) {
        fn_801DF700();
    }

    buf = fn_801D718C(0xE0, 0x20);
    zero = 0;
    if (buf == zero) {
        fn_801DF700();
    }

    memset((void *)buf, 0, 0xE0);

    result = fn_802113E0(0, buf);
    if (result == -0x3F9) {
        if (fn_802112C8(locals[16], locals[17], 0U, &locals[10]) != 0) {
            fn_801DF700();
        }

        buf2 = fn_801D718C((locals[10] * 0xD8 + 0x1F) & ~0x1F, 0x20);
        zero = 0;
        if (buf2 == zero) {
            fn_801DF700();
        }

        if (fn_802112C8(locals[16], locals[17], buf2, &locals[10]) != 0) {
            fn_801DF700();
        }

        memcpy((void *)buf, (void *)buf2, 0xD8);
    } else if (result != 0) {
        fn_801DF700();
    } else if (fn_801E38A8() != 0) {
        locals[9] = 0;
        locals[8] = -1;
        fn_801E3E20(buf, &locals[9], &locals[8]);
        if (locals[8] == 0) {
            fn_801E3B04();
            fn_801DF700();
        }
    }

    if (fn_8021111C(locals[16], locals[17], buf) != 0) {
        fn_801DF700();
    }

    for (;;) {
    }
}
