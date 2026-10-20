#include <types.h>
#pragma force_active on

class fnBase {
public:
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20(s32) = 0;
    virtual void v21(s32) = 0;
};

extern "C" {
void fn_27_A3494(fnBase* self, u32 type, s32 arg) {
    if (type == 1) {
        self->v20(arg);
    } else {
        self->v21(arg);
    }
}
}
