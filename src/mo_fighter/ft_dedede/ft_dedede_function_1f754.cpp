#pragma force_active on
extern const float lbl_117_rodata_110;
extern "C" void fn_27_1D9FF8(void*);

namespace {
struct Target {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void call(float, int);
};

struct Third {
    unsigned char pad[0x64];
    Target* target;
};

struct Second {
    unsigned char pad[0xD8];
    Third* third;
};

struct First {
    unsigned char pad[0x60];
    Second* second;
};
}

extern "C" void fn_117_1F754(First* self) {
    self->second->third->target->call(lbl_117_rodata_110, 0x11000001);
    fn_27_1D9FF8(self);
}
