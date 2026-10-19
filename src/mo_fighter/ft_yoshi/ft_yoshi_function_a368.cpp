#pragma force_active on
extern "C" void fn_95_10378(void* self);

struct Obj {
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
    virtual int f6();
    virtual int f7();
    virtual int f8();
    virtual int f9();
    virtual int f10();
    virtual int f11();
    virtual int f12();
    virtual int f13();
    virtual int f14();
    virtual int f15();
    virtual int f16();
};

extern "C" void fn_95_A368(void* p0, void* p1, unsigned char* self) {
    void* a = *(void**)(self + 0xd8);
    Obj* b = *(Obj**)((unsigned char*)a + 0x70);
    int x = b->f16();
    if (x == 0x113 || (unsigned int)(x - 0x119) <= 3) {
        fn_95_10378(self);
    }
}
