#include <types.h>
#pragma force_active on

struct FnBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v20(void* a, void* b, s16* out, s32 idx);
};

extern "C" void fn_27_846FC(FnBase* self, void* a, void* b) {
    s16 tmp = 0;
    self->v20(a, b, &tmp, -1);
}
