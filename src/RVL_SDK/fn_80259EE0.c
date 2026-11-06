#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

extern u8 lbl_8052D9C0[];
extern char lbl_80484DE0[];
extern void *fn_8025AF74(void);
extern void fn_802319E4(int, const char *);
extern u16 fn_8024A530(int, void *);
extern void fn_8025AFE8(void *);
extern void *memcpy(void *, const void *, unsigned long);

void *fn_80259EE0(void *arg0) {
    char *s = lbl_80484DE0;
    u8 *obj;
    u16 result;

    obj = fn_8025AF74();
    if (obj == 0) {
        if (lbl_8052D9C0[0x4630] >= 2U) {
            fn_802319E4(0xA0001, s + 0x28C);
        }
        return 0;
    }
    if (lbl_8052D9C0[0x4630] >= 4U) {
        fn_802319E4(0xA0003, s + 0x2A8);
    }
    obj[1] |= 1;
    memcpy(obj + 2, arg0, 6);
    obj[0] = 1;
    result = fn_8024A530(1, arg0);
    if (result != 0) {
        *(u16 *)(obj + 0x22) = result;
        return obj;
    }
    if (lbl_8052D9C0[0x4630] >= 2U) {
        fn_802319E4(0xA0001, s + 0x2C0);
    }
    fn_8025AFE8(obj);
    return 0;
}
