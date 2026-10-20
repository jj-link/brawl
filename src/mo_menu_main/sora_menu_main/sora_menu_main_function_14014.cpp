#include <types.h>
#pragma force_active on

class Inner {
public:
    void* m_0;
    void* m_4;
    void* m_8;
    void* m_C;
    void* m_10;
};

struct P {
    u8 _pad[0x58];
    Inner* m_58[7];
};

class Obj {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
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
    virtual void method(void* a) = 0;
};

class Manager {
public:
    u8 _pad[0x64c];
    P* m_base;
    u8 _pad2[4];
    Obj* m_obj;
};

extern "C" void fn_2_14014(Manager* self) {
    for (u32 i = 0; i < 7; i++) {
        self->m_obj->method(self->m_base->m_58[i]->m_10);
    }
}
