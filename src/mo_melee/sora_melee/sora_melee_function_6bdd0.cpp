#include <types.h>
#pragma force_active on

struct utList {
    void* getNode(u32 index);
};

struct Node {
    Node* next;
    u8 pad[8];
    void* target;
};

struct Target {
    u8 pad[0x30];
    u32 bits;
};

struct DataInfo {
    u8 pad[0xD8];
    void* inner;
};

struct InnerObj {
    u8 pad[0x44];
    void* obj;
};

struct Accessor {
    u8 pad[0x44];
    DataInfo* data;
};

class Obj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void* call();
};

class Owner {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void* getContainer(s32);
    u8 pad[0x1C];
    utList list;
};

extern "C" void* getNode__6utListFUl(void*, u32);
extern "C" Accessor* fn_27_6F30C(void*);

extern "C" void* fn_27_6BDD0(Owner* self) {
    void* container = self->getContainer(-1);
    if (container) {
        Node* node = (Node*)self->list.getNode(0);
        while (node != 0) {
            Target* target = (Target*)node->target;
            if ((target->bits >> 8) & 1) {
                Accessor* acc = fn_27_6F30C(node);
                DataInfo* data = acc->data;
                InnerObj* inner = (InnerObj*)data->inner;
                Obj* obj = (Obj*)inner->obj;
                return obj->call();
            }
            node = node->next;
        }
    }
    return 0;
}
