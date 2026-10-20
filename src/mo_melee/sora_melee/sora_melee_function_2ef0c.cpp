#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Flags8 {
    u8 hi : 6;
    u8 bit1 : 1;
    u8 bit0 : 1;
};

struct Flags32 {
    u32 hi : 30;
    u32 bit1 : 1;
    u32 bit0 : 1;
};

extern "C" void fn_27_2EF0C(void* self, u32 flag, u32 n) {
    u8* inner = *(u8**)((u8*)self + 0x4);
    Flags8* f = (Flags8*)(inner + 0x73);
    f->bit1 = flag;
    if (n != 1) {
        return;
    }
    Flags32* w = (Flags32*)((u8*)self + 0x38);
    w->bit1 = flag;
}
