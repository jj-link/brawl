#include <types.h>
#pragma force_active on

struct Rec {
    s32 f0;
    s32 f4;
    s32 f8;
};

class HeapAlloc {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Rec* slot4(s32 size, s32 align);
};

extern HeapAlloc* lbl_805A0EB8;

extern "C" {
void fn_80281D8C(s32 arg0) {
    s32 var_r31;
    Rec* temp_r3;

    var_r31 = arg0;
    if (arg0 < 0x33) {
        var_r31 = 0x33;
    }
    temp_r3 = lbl_805A0EB8->slot4(var_r31 + 0xd, 0x14);
    temp_r3->f0 = arg0;
    temp_r3->f4 = var_r31;
    temp_r3->f8 = 0;
}
}
