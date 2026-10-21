#pragma force_active on

class Leaf {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int f4();
};

struct Node {
    Leaf* m_leaf;
};

class Inner {
public:
    virtual void f0();
    virtual Node* f1(int arg);
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual int f6();
};

struct Owner {
    char m_pad[0xc];
    Inner* m_inner;
};

extern "C" int fn_27_8EF88(Owner* self, int arg) {
    if (self->m_inner->f6() == 0) {
        return 0;
    }

    Leaf* leaf = self->m_inner->f1(arg)->m_leaf;
    if (leaf == 0) {
        return 0;
    }

    return leaf->f4();
}
