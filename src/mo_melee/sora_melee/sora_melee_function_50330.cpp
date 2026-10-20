#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" void fn_27_501F4(u8* self, int idx);

extern "C" void fn_27_50330(u8* self, int idx) {
    u32* entry = (u32*)(*(u8**)(self + 0xa4) + idx * 0x34);
    if ((((entry[10]) >> 16) & 0xFF) == 0) {
        fn_27_501F4(self, idx);
        return;
    }
    entry[10] |= 1;
}
