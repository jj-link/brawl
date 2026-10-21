#pragma force_active on
typedef unsigned char u8;
typedef signed int s32;

extern "C" s32 fn_802D8E2C(void* arg0, s32 arg1) {
    u8* table = *(u8**)((char*)arg0 + 0x1C);
    s32 base = *(s32*)((char*)arg0 + 0x3C);
    return ((base + 0x37) & 0xFFFFFFF0) + (table[arg1] << 5);
}
