#include <types.h>
#pragma force_active on

class MyClass {
public:
    virtual ~MyClass() {}
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
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual s32* target(s32*);
};

extern "C" void fn_54_B040(MyClass* obj, s32* a, s32* b) {
    s32* r1 = obj->target(a);
    s32* r2 = obj->target(b);
    r2[0] = r1[0];
    r2[1] = r1[1];
}
