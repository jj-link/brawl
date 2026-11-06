#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void fn_801D8690(const char *, int, const char *, ...);
extern char lbl_80485278[0x2B];
extern char lbl_8059EE38[6];

void fn_8025BF24(u8 *arg0) {
    u16 i;
    u32 off;

    if (*(u32 *)arg0 != 0x0020AF30) {
        fn_801D8690(lbl_8059EE38, 0x19, lbl_80485278);
    }
    *(u32 *)(arg0 + 8) = (u32)arg0 + *(u32 *)(arg0 + 8);
    for (i = 0; i < *(u32 *)(arg0 + 4); i++) {
        off = i * 8;
        if (*(u32 *)(*(u32 *)(arg0 + 8) + off) != 0) {
            *(u32 *)(*(u32 *)(arg0 + 8) + off) = (u32)(arg0 + *(u32 *)(*(u32 *)(arg0 + 8) + off));
            if (*(u8 *)(*(u32 *)(*(u32 *)(arg0 + 8) + off) + 0x23) == 0) {
                *(u32 *)(*(u32 *)(*(u32 *)(arg0 + 8) + off) + 8) = (u32)(arg0 + *(u32 *)(*(u32 *)(*(u32 *)(arg0 + 8) + off) + 8));
                *(u8 *)(*(u32 *)(*(u32 *)(arg0 + 8) + off) + 0x23) = 1;
            }
        }
        if (*(u32 *)(*(u32 *)(arg0 + 8) + off + 4) != 0) {
            *(u32 *)(*(u32 *)(arg0 + 8) + off + 4) = (u32)(arg0 + *(u32 *)(*(u32 *)(arg0 + 8) + off + 4));
            if (*(u8 *)(*(u32 *)(*(u32 *)(arg0 + 8) + off + 4) + 2) == 0) {
                *(u32 *)(*(u32 *)(*(u32 *)(arg0 + 8) + off + 4) + 8) = (u32)(arg0 + *(u32 *)(*(u32 *)(*(u32 *)(arg0 + 8) + off + 4) + 8));
                *(u8 *)(*(u32 *)((u8 *)*(u32 *)(arg0 + 8) + off + 4) + 2) = 1;
            }
        }
    }
}
