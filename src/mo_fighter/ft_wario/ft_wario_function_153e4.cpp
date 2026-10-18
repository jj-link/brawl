#pragma force_active on
extern "C" void fn_27_63098();

struct Tmp {
    int a;
    unsigned char b;
    void* c;
    unsigned char d;
};

class ObjA {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void* f17();
};

class ObjB {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void f17(int, Tmp*);
};

extern "C" void fn_110_153E4(void*, char* self) {
    fn_27_63098();
    ObjA* a = *(ObjA**)(*(char**)(self + 0xd8) + 0x44);
    void* res = a->f17();
    Tmp t;
    t.a = 0x843;
    t.b = 0;
    t.c = res;
    t.d = 1;
    ObjB* b = *(ObjB**)(*(char**)(self + 0xd8) + 0x54);
    b->f17(3, &t);
}
