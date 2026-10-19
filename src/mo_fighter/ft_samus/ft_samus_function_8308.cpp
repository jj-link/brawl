#pragma force_active on
extern "C" void* fn_94_7E08(void*, int, int, int, int, int, int);

struct SubObject {
    char padding[8];
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
};

extern "C" void* fn_94_8308(void* self) {
    char* p = (char*)self;
    fn_94_7E08(p + 0x1C0, (int)self, 0x4D,
               (int)(p + 0x134), 0x20, (int)(p + 0x1B4), 3);
    ((SubObject*)(p + 0x1C0))->f25();
    return self;
}
