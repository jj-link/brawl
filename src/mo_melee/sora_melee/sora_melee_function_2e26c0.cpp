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

    void init(void* p, int* i, float* f) {
        isNull = false;
        owner = p;
        *(WorkFunction**)((char*)this + 8) = __vt__19soGeneralWorkSimple;
        secondary = __vt__19soGeneralWorkSimple + 2;
        intCount = 5;
        ints = i;
        floatCount = 3;
        floats = f;
        flagCount = 1;
        clear();
    }
};

struct Object {
    char pad[0x14];
    int ints[3];
    float floats[1];
    Work work;
};

extern "C" Object* fn_27_2E26C0(Object* p) {
    ((Work*)((unsigned int)p + 0x24))->init(p, p->ints, p->floats);
    return p;
}
