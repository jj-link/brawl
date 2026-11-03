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
extern nw4r::g3d::G3dObj* lbl_805A030C;
extern Outer* lbl_805A0308;
}

extern "C" void fn_800FD5D0() {
    if (lbl_805A030C != 0) {
        lbl_805A030C->Destroy();
        lbl_805A030C = 0;
    }
    if (lbl_805A0308 != 0) {
        delete lbl_805A0308;
        lbl_805A0308 = 0;
    }
}