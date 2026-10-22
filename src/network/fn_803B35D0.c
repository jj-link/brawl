#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

s32 fn_803B35D0(void *arg0, void *arg1) {
    if (arg0 == 0) {
        return 0xA;
    }
    if (arg1 == 0) {
        return 0xA;
    }
    if (!(*(u16 *)((u8 *)arg0 + 0x1878) & 2)) {
        return 9;
    }
    *(void **)((u8 *)arg1 + 0x22C) = arg0;
    *(u16 *)((u8 *)arg1 + 0x0) = 0x5C;
    *(u16 *)((u8 *)arg1 + 0x2) = 0;
    *(u8 *)((u8 *)arg1 + 0x20A) = 0;
    *(u8 *)((u8 *)arg1 + 0x20B) = 0;
    *(u8 *)((u8 *)arg1 + 0x20C) = 0;
    *(u8 *)((u8 *)arg1 + 0x20E) = 0x5C;
    *(u8 *)((u8 *)arg1 + 0x20F) = 0;
    *(u8 *)((u8 *)arg1 + 0x21B) = 0;
    *(u8 *)((u8 *)arg1 + 0x21C) = 0x10;
    *(u8 *)((u8 *)arg1 + 0x21D) = 0;
    *(u16 *)((u8 *)arg1 + 0x21E) = 0;
    *(u16 *)((u8 *)arg1 + 0x220) = 0;
    *(u16 *)((u8 *)arg1 + 0x222) = 0;
    *(u16 *)((u8 *)arg1 + 0x224) = 0;
    *(u16 *)((u8 *)arg1 + 0x226) = 0;
    *(s32 *)((u8 *)arg1 + 0x228) = 0;
    *(s32 *)((u8 *)arg1 + 0x230) = 3;
    *(s32 *)((u8 *)arg1 + 0x234) = 1;
    *(s32 *)((u8 *)arg1 + 0x238) = -1;
    *(u16 *)((u8 *)arg1 + 0x23C) = 0;
    return 0;
}
