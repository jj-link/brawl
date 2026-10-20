#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct BitsS {
    u8 pad[0x44];
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
};

extern "C" void fn_27_B6CAC(BitsS* self, u32 flag) {
    self->b1 = flag;
}
