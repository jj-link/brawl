#include <revolution/types.h>
#include <nw4r/g3d/g3d_obj.h>
#pragma force_active on

struct Base {
    char pad[0x5c];
};

struct Outer : Base {
    virtual ~Outer();
};

extern "C" {
extern nw4r::g3d::G3dObj* lbl_805A0334;
extern Outer* lbl_805A0330;
}

extern "C" void fn_80108DE4() {
    if (lbl_805A0334 != 0) {
        lbl_805A0334->Destroy();
        lbl_805A0334 = 0;
    }
    if (lbl_805A0330 != 0) {
        delete lbl_805A0330;
        lbl_805A0330 = 0;
    }
}