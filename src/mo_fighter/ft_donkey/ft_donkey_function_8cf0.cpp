#pragma force_active on

struct ModA {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int f4(int);
    virtual void f5(int, int);
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
    virtual int f17(int);
    virtual void f18();
    virtual void f19(int);
};

struct ModB {
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
    virtual void f20(int);
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
    virtual void f39(int);
};

extern "C" void fn_27_12BAF8(void*, int);

extern "C" void fn_92_8CF0(void* self, int arg1) {
    if (arg1 == 8) {
        ModA* a = *(ModA**)((unsigned char*)*(void**)((unsigned char*)*(void**)((unsigned char*)self + 0x60) + 0xd8) + 0x64);
        if (a->f17(0x1200003d) != 0) {
            int r2 = (*(ModA**)((unsigned char*)*(void**)((unsigned char*)*(void**)((unsigned char*)self + 0x60) + 0xd8) + 0x64))->f4(0x10000041);
            (*(ModB**)((unsigned char*)*(void**)((unsigned char*)*(void**)((unsigned char*)self + 0x60) + 0xd8) + 0x88))->f20(r2);
        }
    }
    (*(ModA**)((unsigned char*)*(void**)((unsigned char*)*(void**)((unsigned char*)self + 0x60) + 0xd8) + 0x64))->f5(0, 0x10000040);
    (*(ModA**)((unsigned char*)*(void**)((unsigned char*)*(void**)((unsigned char*)self + 0x60) + 0xd8) + 0x64))->f5(0, 0x10000041);
    (*(ModA**)((unsigned char*)*(void**)((unsigned char*)*(void**)((unsigned char*)self + 0x60) + 0xd8) + 0x64))->f19(0x1200003d);
    (*(ModB**)((unsigned char*)*(void**)((unsigned char*)*(void**)((unsigned char*)self + 0x60) + 0xd8) + 0x88))->f39(0x1a);
    (*(ModA**)((unsigned char*)*(void**)((unsigned char*)*(void**)((unsigned char*)self + 0x60) + 0xd8) + 0x64))->f5(-1, 0x10000042);
    fn_27_12BAF8(self, arg1);
}