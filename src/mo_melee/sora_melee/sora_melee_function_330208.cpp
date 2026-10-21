#pragma force_active on
typedef void (*WorkFunction)(void*);

extern "C" unsigned char __vt__19soGeneralWorkSimple[];

struct Work {
    void* vtable0;
    unsigned char nullable;
    unsigned char padding[3];
    WorkFunction* vtable8;
    void* owner;
    int intCount;
    void* ints;
    int floatCount;
    void* floats;
    int flagCount;
};

struct CallData {
    void* vtable0;
    unsigned char nullable;
    unsigned char padding[3];
};

struct VirtualCall : CallData {
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
    virtual void call();
};

struct Object {
    unsigned char data[0x20];
    int ints[2];
    float floats[1];
    Work work;
};

extern "C" Object* fn_27_330208(Object* self) {
    Work* work = &self->work;
    work->nullable = 0;
    work->owner = self;
    work->vtable8 = (WorkFunction*)__vt__19soGeneralWorkSimple;
    work->vtable0 = __vt__19soGeneralWorkSimple + 8;
    work->intCount = 8;
    work->ints = self->ints;
    work->floatCount = 2;
    work->floats = self->floats;
    work->flagCount = 1;
    ((VirtualCall*)work)->call();
    return self;
}
