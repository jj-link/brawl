#pragma force_active on
extern "C" void wnemReport__FPCce(const char*, ...);
extern "C" const float lbl_41_rodata_E28;
extern "C" const char lbl_41_data_5348[];

class Inner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(int, void*, float);
    virtual void vf5();
    virtual void vf6(int, void*, int, float);
};

extern "C" void fn_41_33A3C(char* self, int arg) {
    wnemReport__FPCce(lbl_41_data_5348);
    char* a = *(char**)(self + 0x6c);
    Inner* in = *(Inner**)(*(char**)(a + 0xd8) + 0x6c);
    in->vf6(6, a, arg, lbl_41_rodata_E28);
    a = *(char**)(self + 0x6c);
    in = *(Inner**)(*(char**)(a + 0xd8) + 0x6c);
    in->vf4(6, a, lbl_41_rodata_E28);
}
