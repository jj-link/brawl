#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" void fn_80_2988(void *self, u8 a, u32 b, float c) {
    *(u8 *)((char *)self + 0x184) = a;
    *(u32 *)((char *)self + 0x188) = b;
    *(float *)((char *)self + 0x18C) = c;
}
