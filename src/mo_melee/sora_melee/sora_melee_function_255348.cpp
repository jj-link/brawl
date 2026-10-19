#pragma force_active on
extern "C" unsigned char lbl_8059E742;

typedef unsigned char u8;
typedef unsigned int u32;

extern "C" void fn_27_255348(u8* self, u32 p4, u32 p5) {
    if (self[0x49] == 0) {
        return;
    }
    if (self[0x4B] != 0) {
        return;
    }
    if (p4 != lbl_8059E742) {
        return;
    }
    *(u32*)(self + 0x60) = p5;
    self[0x4B] = 1;
}
