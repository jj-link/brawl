#pragma force_active on
extern "C" {
extern unsigned char __vt__19soGeneralWorkSimple[];
}

struct Header {
    void* vtable0;
    unsigned char flag;
    unsigned char pad[3];
};

struct Work : Header {
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
    virtual void f25();

    void* owner;
    int count1;
    void* data1;
    int count2;
    void* data2;
    int count3;
};

struct Object {
    unsigned char pad[0x50];
    Work work;
};

extern "C" Object* fn_27_2FDCB4(Object* self) {
    Work* work = &self->work;
    work->flag = 0;
    work->owner = self;
    *(void**)((unsigned char*)work + 8) = __vt__19soGeneralWorkSimple;
    work->vtable0 = __vt__19soGeneralWorkSimple + 8;
    work->count1 = 11;
    work->data1 = (unsigned char*)self + 0x2c;
    work->count2 = 8;
    work->data2 = (unsigned char*)self + 0x4c;
    work->count3 = 1;
    work->f25();
    return self;
}
