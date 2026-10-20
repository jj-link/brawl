#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct FnObj27 {
    u8 pad_0[8];
    u32 flags;
};

extern "C" void fn_27_C9AD8(FnObj27* p) {
    p->flags &= 0xFDFFFFFF;
}
