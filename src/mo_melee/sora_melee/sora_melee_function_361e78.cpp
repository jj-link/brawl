#pragma force_active on
extern "C" float fn_27_192278(void* self, unsigned long arg);
extern "C" extern const float lbl_27_rodata_7AA8;

class SoraIface {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13(unsigned long arg);
};

extern "C" {
void fn_27_361E78(void* a, void* self, int type) {
    if (type == 0x10) {
        if (fn_27_192278(self, 0xfa1) > lbl_27_rodata_7AA8) {
            char* p = *(char**)((char*)self + 0xd8);
            SoraIface* obj = *(SoraIface**)(p + 0x64);
            obj->vf13(0x11000000);
        }
    }
}
}
