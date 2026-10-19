#pragma force_active on
extern "C" {
void fn_27_12BAF8(void* object, int param);
extern const float lbl_121_rodata_C;
}

struct VirtTarget2 {
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

extern "C" void fn_121_95FC(void* self, int param) {
    fn_27_12BAF8(self, param);
    unsigned char* p = static_cast<unsigned char*>(self);
    unsigned char* a = *reinterpret_cast<unsigned char**>(p + 0x60);
    unsigned char* b = *reinterpret_cast<unsigned char**>(a + 0xd8);
    VirtTarget2* m = *reinterpret_cast<VirtTarget2**>(b + 0x64);
    m->f13(lbl_121_rodata_C, 0x11000016);
    p[0x1A384] = 0;
}
