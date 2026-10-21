#include <types.h>
#pragma force_active on

class Leaf {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual s32 f3();
};

class Node {
public:
    Leaf* m_leaf;
};

class Inner {
public:
    virtual void f0();
    virtual Node* f1(void* arg);
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual s32 f6(void* arg);
};

class Owner {
public:
    char m_pad[0xc];
    Inner* m_inner;
};

extern "C" s32 fn_27_8EEF4(Owner* self, void* arg) {
    if (!self->m_inner->f6(arg)) {
        return 0;
    }
    Leaf* leaf = self->m_inner->f1(arg)->m_leaf;
    if (leaf == 0) {
        return 0;
    }
    return leaf->f3();
}
