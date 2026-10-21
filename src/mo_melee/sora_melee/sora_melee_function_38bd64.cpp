#pragma force_active on
typedef void (*WorkFunction)();

extern "C" WorkFunction __vt__19soGeneralWorkSimple[];

struct Nullable {
    WorkFunction* secondary;
    bool isNull;
};

class Work : public Nullable {
public:
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void clear();

    void* owner;
    int intCount;
    int* ints;
    int floatCount;
    float* floats;
    int flagCount;
};

struct Object {
    char pad[0x2C];
    int ints[1];
    float floats[1];
    Work work;
};

extern "C" Object* fn_27_38BD64(Object* p) {
    Work* w = &p->work;
    w->isNull = false;
    w->owner = p;
    *(WorkFunction**)((char*)w + 8) = __vt__19soGeneralWorkSimple;
    w->secondary = __vt__19soGeneralWorkSimple + 2;
    w->intCount = 11;
    w->ints = p->ints;
    w->floatCount = 1;
    w->floats = p->floats;
    w->flagCount = 1;
    w->clear();
    return p;
}
