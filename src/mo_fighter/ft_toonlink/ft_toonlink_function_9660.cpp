#pragma force_active on
extern "C" {
void fn_27_12DCA8(void* object);
extern const float lbl_121_rodata_C;
void fn_121_9660(void* object);
}

struct VirtTarget {
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
    virtual void f13(float value, int id);
};

extern "C" void fn_121_9660(void* object) {
    fn_27_12DCA8(object);
    unsigned char* p = *(unsigned char**)((unsigned char*)object + 0x60);
    unsigned char* q = *(unsigned char**)(p + 0xd8);
    VirtTarget* m = *(VirtTarget**)(q + 0x64);
    m->f13(lbl_121_rodata_C, 0x11000016);
}
