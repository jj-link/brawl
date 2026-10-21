#include <types.h>
#pragma force_active on

struct Frame {
    void* p;
    short a;
    short s;
    char data[0xF8];
};

extern "C" u8 lbl_80487D38[];

extern "C" void* fn_802E6120() {
    Frame f __attribute__((aligned(16)));
    if (&f != 0) {
        f.s = 1;
        f.p = lbl_80487D38;
    }
    return f.p;
}
