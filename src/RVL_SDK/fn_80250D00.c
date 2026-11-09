#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern u8 lbl_8052D5A8[];
extern char lbl_80483E98[];

extern void fn_802319E4(int, const char *);
extern void fn_802516E4(void *, int);
extern void *fn_80251AD0(void *, u32);
extern void fn_80254850(void *, u8, void *);
extern void fn_80254A30(void *, u8);

void fn_80250D00(void *arg0, u32 arg1, u32 arg2, s32 arg3) {
    char *s = lbl_80483E98;
    u8 *obj;

    obj = fn_80251AD0(arg0, arg1);
    if (lbl_8052D5A8[0x414] >= 4U) {
        fn_802319E4(0x90003, s + 0x150);
    }
    if (obj == 0) {
        if (lbl_8052D5A8[0x414] >= 2U) {
            fn_802319E4(0x90001, s + 0x160);
        }
    } else {
        if (arg3 != 0) {
            obj[0xE] = 0xE;
            fn_80254A30(arg0, obj[0xD]);
            fn_802516E4(obj, 0xE);
            return;
        }
        if (!(obj[0x64] & 1)) {
            fn_80254850(*(void **)(obj + 0x6C), obj[0xD], obj + 0x5A);
            return;
        }
        if (lbl_8052D5A8[0x414] >= 2U) {
            fn_802319E4(0x90001, s + 0x178);
        }
    }
}
