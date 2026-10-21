#pragma force_active on
typedef unsigned char u8;

extern "C" {
int fn_800F1820(u8* a, u8* b, u8* c, u8* d, int e, int f, int g, int h);

void fn_800F177C(u8* self) {
    *(int*)(self + 0x5c) = fn_800F1820(self + 0x54, self + 0x68, *(u8**)(self + 0x58), *(u8**)(self + 0x0), 0xc4, 0x2a, 0x2a, 6);
}
}
