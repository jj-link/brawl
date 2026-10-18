#include <types.h>
#pragma force_active on

class fn27VBase {
public:
    virtual void* vf0();
    virtual void* vf1();
    virtual void* vf2();
    virtual void* vf3();
    virtual void* vf4();
    virtual void* vf5();
    virtual void* vf6();
    virtual void* vf7();
    virtual void* vf8();
    virtual void* vf9();
    virtual void* vf10();
    virtual void* vf11();
    virtual void* vf12();
    virtual void* vf13(void* p);
    virtual void* vf14();
    virtual void* vf15();
};

struct fn27Mid {
    char pad[0x3c];
    fn27VBase* m_3c;
};

struct fn27Outer {
    char pad[0xd8];
    fn27Mid* m_d8;
};

extern "C" {
void* fn_27_178B84(void* unused, fn27Outer* o) {
    return o->m_d8->m_3c->vf13(o);
}
}
