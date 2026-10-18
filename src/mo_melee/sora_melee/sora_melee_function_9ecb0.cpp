#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Flags {
    u8 pad0 : 5;
    u8 flag : 1;
    u8 pad1 : 2;
};

extern "C" u32 fn_27_9ECB0(void* self) {
    return ((Flags*)((u8*)self + 0x135))->flag != 0;
}
