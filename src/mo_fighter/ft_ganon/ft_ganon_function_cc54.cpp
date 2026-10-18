#pragma force_active on
extern "C" void fn_109_CA24(void*, int, int, int);

struct Obj1 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(int);
};

struct Obj2 {
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
    virtual void f16(int, void*, int);
};

struct Obj3 {
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
    virtual void f21(int, void*);
};

extern "C" void fn_109_CC54(void*, void* arg1) {
    unsigned char event[0x20];
    void* module = *(void**)((char*)arg1 + 0xD8);
    Obj1* obj1 = (Obj1*)*(void**)((char*)module + 0x3C);
    obj1->f5(-1);
    fn_109_CA24(event, 0x21, 0x1B2, 1);
    module = *(void**)((char*)arg1 + 0xD8);
    Obj2* obj2 = (Obj2*)*(void**)((char*)module + 0x54);
    obj2->f16(0, event, 0);
    module = *(void**)((char*)arg1 + 0xD8);
    Obj3* obj3 = (Obj3*)*(void**)((char*)module + 0x7C);
    obj3->f21(0, arg1);
}
