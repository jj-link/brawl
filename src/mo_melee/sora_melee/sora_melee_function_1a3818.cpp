#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct SoWorkState {
    u8* ptr0;
    u8* ptr4;
    u32 flag8;
};

extern "C" u8 lbl_27_data_365A0[];

extern "C" void fn_27_1A3818(SoWorkState* s) {
    u32 flag = s->flag8;
    u8* base = lbl_27_data_365A0;
    s->ptr0 = base;
    s->ptr4 = base + 0x48;
    s->flag8 = flag & 1;
}
