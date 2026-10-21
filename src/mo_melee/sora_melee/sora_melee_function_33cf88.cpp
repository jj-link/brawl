#pragma force_active on
extern "C" float fn_27_192278(void*, unsigned long);
extern "C" const float lbl_27_rodata_7738;

class SoVirt {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void setInt(int, unsigned long);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void call(unsigned long);
};

extern "C" void fn_27_33CF88(void* unused, void* self, int mode) {
    if (mode == 0x10) {
        if (fn_27_192278(self, 0xfa4) > lbl_27_rodata_7738) {
            SoVirt* work = *(SoVirt**)(*(unsigned char**)((unsigned char*)self + 0xd8) + 0x64);
            work->call(0x11000000);
        }
    }
    SoVirt* work = *(SoVirt**)(*(unsigned char**)((unsigned char*)self + 0xd8) + 0x64);
    work->setInt(0, 0x10000040);
}
