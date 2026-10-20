#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct Obj {
    u8 pad[8];
    u32 flags;
};

extern "C" void fn_27_1D5ACC(Obj* p) {
    p->flags |= 0x10000;
}
