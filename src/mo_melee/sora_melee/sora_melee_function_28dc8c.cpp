#include <types.h>
#pragma force_active on

class A {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

class B {
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
    virtual int v13(int arg);
};

extern "C" int fn_27_28DC8C(u8* self) {
    if (*(self + 0x3C68) != 0) {
        if (reinterpret_cast<A*>(self + 0x3AB4)->v3() > 2) {
            return reinterpret_cast<B*>(self + 0x3A68)->v13(2);
        }
    }
    return 0;
}
