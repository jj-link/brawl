#include <types.h>
#pragma force_active on

class soVirtBase {
public:
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
    virtual void call(u32 a, u32 b, s16* c, s32 d);
};

extern "C" {
void fn_27_84AC8(soVirtBase* self, u32 a, u32 b) {
    s16 flag = 0;
    self->call(a, b, &flag, -1);
}
}
