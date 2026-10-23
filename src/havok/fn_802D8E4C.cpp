#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;

extern "C" s32 fn_802D8E4C(void* arg0, s32 arg1) {
    u8* table = *(u8**)((char*)arg0 + 0x1C);
    s32 base = *(s32*)((char*)arg0 + 0x3C);
    u16 hw = *(u16*)((char*)base + 6);
    return table[arg1] * 0x14 + (hw << 5) + ((base + 0x37) & 0xFFFFFFF0);
}
