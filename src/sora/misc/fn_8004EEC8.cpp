#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;
typedef long long s64;

extern "C" {
s64 OSGetTime(void);
s64 fn_803F1470(s64, s64);
void* memcpy(void*, const void*, unsigned long);
}

extern "C" void fn_8004EEC8(u8* arg0, u8* arg1) {
    s64 ret;
    u32 var;

    ret = fn_803F1470(OSGetTime(), (s64)(*(u32*)0x800000F8 >> 2));
    var = *(u32*)(*(u8**)(arg0 + 0x24) + 0x2D4) + (u32)(ret - (s64)*(u32*)(*(u8**)arg0 + 0x24));
    if (var >= 0x15752A00U) {
        var = 0x157529FFU;
    }
    *(u32*)(*(u8**)(arg0 + 0x24) + 0x2D4) = var;
    *(s64*)(*(u8**)arg0 + 0x20) = ret;
    *(u32*)arg1 = 0x14;
    *(u32*)(arg1 + 4) = 0xC660;
    memcpy(arg1 + 8, *(u8**)(arg0 + 0x24), 0x3CF0);
    memcpy(arg1 + 0x3CF8, *(u8**)(arg0 + 0x28), 0x88E0);
    memcpy(arg1 + 0xC5D8, *(u8**)(arg0 + 0x34), 0x88);
}
