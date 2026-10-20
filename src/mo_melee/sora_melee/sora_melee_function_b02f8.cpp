#include <types.h>
#pragma force_active on

class fn27Obj {
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
    virtual void v18();
    virtual u32 v19();
};

class fn27Holder {
public:
    u32 pad0;
    u32 pad4;
    fn27Obj* obj;
};

extern "C" u32 fn_27_B02F8(fn27Holder* h) {
    return h->obj->v19();
}
