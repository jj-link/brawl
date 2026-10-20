#include <types.h>
#pragma force_active on

class Obj {
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
    virtual s16 v20(s32* a, s32 neg, s16* b, s8 c);
};

extern "C" s32 fn_27_C513C(void* self, s32 value, s32 c) {
    s16 b = 0;
    Obj* obj = *(Obj**)((u8*)self + 8);
    return (s16)obj->v20(&value, -1, &b, (s8)c);
}
