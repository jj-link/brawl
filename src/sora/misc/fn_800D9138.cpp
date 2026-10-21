#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;

struct Obj {
    u8 pad[0xFEF];
    u8 ids[4];
    u8 padFF3;
    s16 values[4];
};

extern "C" void fn_800D9138(Obj* arg0, u32 arg1, s16 arg2) {
    for (int i = 0; i < 4; ++i) {
        if (arg1 == arg0->ids[i]) {
            arg0->ids[i] = 0xFF;
            arg0->values[i] = arg2;
        }
    }
}
