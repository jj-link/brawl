#pragma force_active on
struct FnTable {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual int f13();
    virtual void f14();
    virtual void f15();
};

struct WNode {
    char pad0[0x48];
    FnTable* obj;
    char pad1[0x1a4 - 0x4c];
    unsigned char flag;
};

struct ZNode {
    WNode* w;
};

struct YNode {
    char pad[0x35c];
    ZNode* z;
};

struct XNode {
    char pad[0x1d0c];
    YNode* y;
};

struct TopNode {
    char pad[0x1ac];
    XNode* x;
};

extern "C" int fn_8_474(TopNode* p) {
    WNode* w = p->x->y->z->w;
    FnTable* t = w->flag ? w->obj : 0;
    return t->f13();
}
