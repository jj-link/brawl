#include <types.h>
#pragma force_active on

class fn27Base {
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
    virtual void v18(u32 a, u32 b, u16* out, s32 n);
};

extern "C" {
void fn_27_84910(fn27Base* self, u32 a, u32 b) {
    u16 buf = 0;
    self->v18(a, b, &buf, -1);
}
}
