#include <types.h>
#pragma force_active on

class Ifc {
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
    virtual s32 call(s32* p, s32 a, u16* q, s8 b);
};

extern "C" {
s16 fn_27_B0288(void* self, s32 val, s32 flag) {
    u16 z = 0;
    Ifc* obj = *(Ifc**)((u8*)self + 8);
    return (s16)obj->call(&val, -1, &z, (s8)flag);
}
}
