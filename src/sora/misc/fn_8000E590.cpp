#pragma force_active on
typedef unsigned char u8;

struct Byte {
    u8 pad : 1;
    u8 target : 1;
    u8 rest : 6;
};

extern "C" void fn_8000E590(u8* base, int index, unsigned val) {
    Byte* p = (Byte*)(base + index * 0x18 + 0x399);
    p->target = val;
}
