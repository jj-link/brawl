#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" u32 fn_96_F5D0(u32 *obj, u32 index) {
    u32 *base = (u32 *)obj[3];
    u32 elem = index * 4;
    u32 val = *(u32 *)((u8 *)base + elem);
    return val;
}
