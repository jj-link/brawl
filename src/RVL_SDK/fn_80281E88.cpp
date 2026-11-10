#include <types.h>
#pragma force_active on

class Obj {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(void* p, s32 a, s32 b);
};

extern "C" {
extern Obj* lbl_805A0EB8;
extern void* lbl_805A0EF0;
}

extern "C" void fn_80281E88(void) {
    if (lbl_805A0EF0 != 0) {
        if (lbl_805A0EF0 != 0) {
            lbl_805A0EB8->slot5(lbl_805A0EF0, 1, 0x13);
        }
        lbl_805A0EF0 = 0;
    }
}
