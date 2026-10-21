#pragma force_active on
typedef unsigned int u32;

struct Work;
typedef void (*WorkMethod)(Work*);

extern "C" WorkMethod __vt__19soGeneralWorkSimple[];

struct VirtualBase {
    u32 prefix[2];
};

struct VirtualWork : VirtualBase {
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3();
    virtual void method4();
    virtual void method5();
    virtual void method6();
    virtual void method7();
    virtual void method8();
    virtual void method9();
    virtual void method10();
    virtual void method11();
    virtual void method12();
    virtual void method13();
    virtual void method14();
    virtual void method15();
    virtual void method16();
    virtual void method17();
    virtual void method18();
    virtual void method19();
    virtual void method20();
    virtual void method21();
    virtual void method22();
    virtual void method23();
    virtual void method24();
    virtual void reset();
};

struct Work {
    WorkMethod* secondary;
    bool isNull;
    WorkMethod* vtable;
    void* owner;
    u32 intCount;
    void* ints;
    u32 floatCount;
    void* floats;
    u32 flagCount;
};

struct Object {
    unsigned char data[0x58];
    Work work;
};

extern "C" Object* fn_27_39D3A4(Object* self) {
    Work* work = &self->work;
    work->isNull = false;
    work->owner = self;
    work->vtable = __vt__19soGeneralWorkSimple;
    work->secondary = __vt__19soGeneralWorkSimple + 2;
    work->intCount = 10;
    work->ints = self->data + 0x28;
    work->floatCount = 11;
    work->floats = self->data + 0x54;
    work->flagCount = 1;
    reinterpret_cast<VirtualWork*>(work)->reset();
    return self;
}
