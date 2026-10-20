#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Flags44 {
    u8 hi : 2;
    u8 flag : 1;
    u8 lo : 5;
};

extern "C" {
void fn_27_B6D60(u8* self, u32 flag) {
    ((Flags44*)(self + 0x44))->flag = flag;
}
}
