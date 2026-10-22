#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;

u64 OSGetTime(void);
void fn_80335638(s32, const char *, ...);
void fn_8034E160(s32, u8, u8 *, s32);

extern char lbl_8048C6F0[];
extern u8 *lbl_805A0FA8;

void fn_803490B4(u8 arg0, s32 arg1) {
    u8 sp[4];
    u8 var_r6;
    u64 t;

    fn_80335638(0x80, lbl_8048C6F0, arg1 - 2, arg0);
    switch (arg1) {
    case 2:
        var_r6 = 1;
        sp[0] = arg0 == *(lbl_805A0FA8 + lbl_805A0FA8[0xD] + 0x2E8);
        while (var_r6 <= lbl_805A0FA8[0xD]) {
            if (arg0 == *(lbl_805A0FA8 + var_r6 + 0x2E8)) {
                sp[1] = var_r6;
                sp[2] = arg0;
                break;
            }
            var_r6++;
        }
        break;
    case 3:
        sp[0] = (u8)*(u16 *)(lbl_805A0FA8 + 0x1C2);
        sp[1] = (u8)((u32)*(u16 *)(lbl_805A0FA8 + 0x1C2) >> 8);
        break;
    case 4:
        sp[0] = (u8)*(u32 *)(lbl_805A0FA8 + 0x558);
        sp[1] = (u8)(*(u32 *)(lbl_805A0FA8 + 0x558) >> 8);
        sp[2] = (u8)(*(u32 *)(lbl_805A0FA8 + 0x558) >> 16);
        sp[3] = (u8)(*(u32 *)(lbl_805A0FA8 + 0x558) >> 24);
        break;
    }
    fn_8034E160(arg1, arg0, sp, 4);
    t = OSGetTime();
    *(u64 *)(lbl_805A0FA8 + 0x1F8) = t;
}
