#pragma force_active on
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern void fn_802319E4(u32, const char*);
extern char lbl_80480E38[];
extern char lbl_80529CF8[];

void fn_8023B5FC(s32 arg0, s32 arg1) {
    char* base = lbl_80529CF8;
    void (*fn)(s32, s32);

    if (*(u16*)(base + 0x63C) != 0x12 && *(u8*)(base + 0x27C0) >= 4) {
        fn_802319E4(0xD0003, lbl_80480E38);
    }
    *(s32*)(base + 0x61C) = 0;
    *(u8*)(base + 0x650) = 0;
    fn = *(void (**)(s32, s32))(base + 0x56C);
    if (fn != 0) {
        fn(arg1, arg0);
    }
}
