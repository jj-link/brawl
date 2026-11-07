#include <types.h>
#pragma force_active on

extern "C" unsigned char lbl_27_bss_1CC[];

class Obj {
public:
    virtual void v0() = 0;
    virtual Obj* at(s32 a, s32 b) = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual s32 size() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void notify(s32 a) = 0;
};

struct Container {
    char pad[0x28];
    s32 field_28;
    s32 field_2c;
    Obj* inner;
    s32 field_34;
    Obj* other;
};

extern "C" Obj* fn_27_93778(Container* self, s32 arg1, s32 arg2, s32 arg3) {
    s32 val = arg2;
    if (arg2 == 0) {
        val = self->field_28;
    }

    Obj* result;
    s32 sz = self->inner->size();
    if (arg1 < sz) {
        result = self->inner->at(arg1, val);
    } else {
        if (self->other == 0) {
            return (Obj*)lbl_27_bss_1CC;
        }
        result = self->other->at(arg1, val);
    }

    result->notify(arg3);
    return result;
}