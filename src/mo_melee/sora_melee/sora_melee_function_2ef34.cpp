#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct fn_27_2EF34_Bits {
    u8 pad[0x71];
    u8 hi : 7;
    u8 lo : 1;
};

extern "C" void fn_27_2EF34(u8* p, u32 flag) {
    fn_27_2EF34_Bits* q = (fn_27_2EF34_Bits*)(*(u8**)(p + 4));
    q->lo = flag;
}
