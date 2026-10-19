#include <types.h>
#pragma force_active on

class soVirtBase {
public:
    virtual ~soVirtBase();
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
    virtual void target(s32 a, s32 b, u16* out, s32 c);
};

extern "C" {
void fn_27_10EB60(soVirtBase* obj, s32 a, s32 b) {
    u16 tmp = 0;
    obj->target(a, b, &tmp, -1);
}
}
