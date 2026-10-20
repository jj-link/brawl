#include <types.h>
#pragma force_active on

class fn_27_DA178_Obj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

struct fn_27_DA178_Arg {
    u32 unk0;
    u32 unk4;
    fn_27_DA178_Obj* obj;
};

extern "C" void fn_27_DA178(fn_27_DA178_Arg* arg) {
    arg->obj->vf4();
}
