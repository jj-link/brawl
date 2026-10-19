#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_40_23E04(void*, const char*, const char*);
extern "C" char lbl_40_data_EF3C[];

struct Base {
    char pad[0x3c];
};

struct Object : Base {
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
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void method(int);

    char pad2[0x164];
    unsigned char flag;
};

extern "C" Object* fn_40_32308(int arg, const char* a, const char* b) {
    Object* p = (Object*)__nw__FUlQ25Heaps8HeapType(0x1a8, 15);
    if (p) {
        fn_40_23E04(p, a, b);
        *(void**)((char*)p + 0x3c) = lbl_40_data_EF3C;
        *(unsigned char*)((char*)p + 0x1a4) = 0;
    }
    p->method(arg);
    return p;
}
