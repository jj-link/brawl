#include <types.h>
#pragma force_active on

struct fn_27_779B4_Ptr {
    s32 unk0;
    s32 val;
};

struct fn_27_779B4_Src {
    fn_27_779B4_Ptr* ptr;
    u8 flag;
};

struct fn_27_Obj {
    virtual void f0();
    virtual void f1();
    virtual fn_27_779B4_Ptr* f2(s32 idx);
};

extern "C" {
void fn_27_779B4(s32* out, fn_27_779B4_Src* src);
}

static inline fn_27_779B4_Src fn_27_make(fn_27_Obj* obj) {
    fn_27_779B4_Src s;
    s.ptr = obj->f2(0);
    s.flag = 0;
    return s;
}

extern "C" void fn_27_77950(s32* out, fn_27_Obj* obj) {
    fn_27_779B4(out, &(fn_27_779B4_Src&)fn_27_make(obj));
}
