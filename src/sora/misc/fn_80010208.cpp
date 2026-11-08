#pragma force_active on
typedef unsigned char u8;
struct S { u8 b, t; inline bool valid() const { return b != 255; } };
extern "C" void fn_80010208(int base, S* p) {
    if (p->valid()) {
        u8* entry = (u8*)(base + p->b * 12);
        *(int*)(entry + 0x68) = 0;
        entry[0x6C] = (entry[0x6C] & ~0x80) | 0x40;
        entry[0x6F] = 20;
        entry[0x70] = 20;
        entry[0x72] = 0;
        entry[0x71] = 0;
        p->b = 255;
        p->t = 20;
    }
}