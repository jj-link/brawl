#include <types.h>
#pragma force_active on

struct Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};

struct Node {
    char pad[0xc];
    Base* obj;
};

struct Owner {
    char pad[0x48];
    Node** table;
};

extern "C" void fn_54_3310(Owner* self, u32 idx) {
    Node* n = self->table[idx];
    if (n == 0) {
        return;
    }
    n->obj->v5();
}
