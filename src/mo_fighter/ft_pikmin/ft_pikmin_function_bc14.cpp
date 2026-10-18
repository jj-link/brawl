#pragma force_active on
struct PikminQueryObj {
    virtual void n00();
    virtual void n01();
    virtual void n02();
    virtual void n03();
    virtual void n04();
    virtual void n05();
    virtual void n06();
    virtual void n07();
    virtual void n08();
    virtual void n09();
    virtual void n10();
    virtual void n11();
    virtual void n12();
    virtual void n13();
    virtual void n14();
    virtual void n15();
    virtual int n16();
};

struct PikminMid {
    unsigned char pad[0x70];
    PikminQueryObj* obj;
};

struct PikminOuter {
    unsigned char pad[0xd8];
    PikminMid* mid;
};

struct PikminSelf {
    unsigned char pad[0x60];
    PikminOuter* outer;
};

extern "C" void fn_27_135EB4(void*, void*, void*, void*, void*);

extern "C" int fn_113_BC14(void* self, void* a, void* b, void* c, void* d) {
    PikminSelf* s = static_cast<PikminSelf*>(self);
    int val = s->outer->mid->obj->n16();
    switch (val) {
    case 0x39:
    case 0x3a:
    case 0x3c:
        return 0;
    default:
        fn_27_135EB4(self, a, b, c, d);
    }
}
