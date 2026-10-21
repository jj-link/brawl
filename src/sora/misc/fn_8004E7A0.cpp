#pragma force_active on
typedef unsigned char u8;
typedef unsigned long u32;

extern "C" {
int fn_8004E7A0(char* self, int off, int val) {
    u8* base = *(u8**)(self + 0x24);
    u8* p = base + off;
    return (u32)(val - p[0x2e6]) >> 31;
}
}
