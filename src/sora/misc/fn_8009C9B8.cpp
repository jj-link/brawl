#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" void fn_8009C9B8(u8* p, u32 bit) {
    if (bit >= 7) {
        return;
    }
    p[0x45] = (u8)(p[0x45] | (u8)(1 << bit));
}
