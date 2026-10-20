#pragma force_active on
typedef unsigned char u8;
typedef unsigned long u32;

struct Flags {
    unsigned char a : 1;
    unsigned char b : 1;
    unsigned char c : 6;
};

extern "C" void fn_27_1120D8(u8** self, u32 flag) {
    Flags* f = (Flags*)((u8*)*self + 0x20);
    f->b = flag & 1;
}
