#include <types.h>
#pragma force_active on

extern "C" s32 randi__Fl(s32);

struct Obj {
    u8 pad[0xCF];
    u8 cf;
    u8 d0;
    u8 d1[3];
    u8 d4;
};

extern "C" void fn_27_240488(Obj* arg0, s32 arg1) {
    arg0->cf = 0;
    int d4 = arg0->d4;
    arg0->d0 = (u8)arg1;

    if (arg1 == 4) {
        for (s32 i = 0; i < 0x20; i++) {
            s32 a = randi__Fl(4);
            s32 b = randi__Fl(4);
            u8 tmp = arg0->d1[a];
            arg0->d1[a] = arg0->d1[b];
            arg0->d1[b] = tmp;
        }
        int d1 = arg0->d1[0];
        if (d4 == d1) {
            arg0->d1[0] = arg0->d1[1];
            arg0->d1[1] = d1;
        }
    }
}
