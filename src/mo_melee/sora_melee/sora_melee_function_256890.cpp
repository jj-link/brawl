#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" void fn_27_256890(u8* self) {
    int i;
    u32 off = 0;
    u8* e;
    for (i = 0; i < 7; i++) {
        e = *(u8**)(self + 0x44) + off;
        if (((e[0xb3] >> 2) & 1) == 0) {
            if (e[0x99] == 0) {
                *(u32*)(self + 0x7c + e[0x9a] * 4) = 0xb4;
            }
            e = *(u8**)(self + 0x44) + off;
            if (e[0x99] == 1) {
                *(u32*)(self + 0x7c + e[0x9a] * 4) = 0x12c;
            }
        }
        off += 0x5c;
    }
}
