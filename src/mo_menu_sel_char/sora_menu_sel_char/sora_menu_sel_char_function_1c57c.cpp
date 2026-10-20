#include <types.h>
#pragma force_active on

struct SelCharHandler {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11(void* x, void* y);
    virtual void vf12();
    virtual void vf13(void* x);
    u8 pad[0xe0];
    void* f_e4;
};

struct SelCharAux {
    u8 pad[0x10];
    void* val;
};

struct SelCharObj {
    SelCharHandler* a;
    SelCharAux* b;
    u8 pad[0x14];
    u8 flagA;
    u8 flagB;
};

extern "C" void fn_10_1C57C(SelCharObj* obj, u8 value) {
    obj->flagB = value;
    u8 cur = obj->flagA;
    obj->a->vf13(obj->b->val);
    if (cur != 0 && obj->flagB == 0) {
        obj->a->vf11(obj->a->f_e4, obj->b->val);
    }
    obj->flagA = cur;
}
