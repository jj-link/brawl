#pragma force_active on
extern "C" float fn_27_192278(void* self, unsigned long arg);
extern "C" const float lbl_27_rodata_75F8;

class SoVirt {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void call(unsigned long arg);
};

extern "C" void fn_27_32A1EC(void* unused, void* self, int mode) {
    if (mode == 0x10) {
        if (fn_27_192278(self, 0xfa1) > lbl_27_rodata_75F8) {
            SoVirt* b = *(SoVirt**)(*(unsigned char**)((unsigned char*)self + 0xd8) + 0x64);
            b->call(0x11000000);
        }
    }
}
