#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" void fn_27_41654(u8* self, u8* out) {
    u8* p = self + 0x28;
    *(u8**)(out + 0x1c) = p;
    u32 w = *(u32*)(self + 0x24);
    *(self + 0x65) = 0;
    u32 v = (w >> 17) & 3;
    *(u32*)(self + 0x4) = v;
    *(u32*)(self + 0x0) = v;
}
