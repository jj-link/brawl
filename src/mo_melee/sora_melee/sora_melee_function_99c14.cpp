#include <types.h>
#pragma force_active on

struct Item {
    s32 a;
    s32 b;
};

class Obj {
public:
    virtual void v0();
    virtual Item* v1(int i);
    virtual void v2();
    virtual int v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12(int i);
};

class Owner {
public:
    u8 pad[0x5C];
    Obj* m_obj;
};

extern "C" void fn_27_9FBD8(Item* work);

extern "C" void fn_27_99C14(Owner* self, s32 arg1) {
    int count = self->m_obj->v3();
    for (int i = count - 1; i >= 0; i--) {
        if (self->m_obj->v1(i)->a == arg1) {
            fn_27_9FBD8(self->m_obj->v1(i));
            self->m_obj->v12(i);
        }
    }
}
