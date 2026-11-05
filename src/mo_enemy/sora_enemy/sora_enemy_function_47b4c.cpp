#pragma force_active on
extern unsigned char lbl_41_bss_504[];
extern float lbl_41_rodata_101C;
extern float lbl_41_rodata_102C;

extern "C" float fn_41_6AD8(void* self, void* acc);
extern "C" void mtSinCosf__FfPfPf(float, float*, float*);

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual int slot17(unsigned long);
};

struct Holder {
    char pad0[0xc];
    soNullable* p0c;
    char pad1[0x64 - 0x10];
    soNullable* p64;
};

struct Accesser {
    char pad[0xd8];
    Holder* holder;
};

extern "C" void fn_41_47B4C(char* arg0, Accesser* arg1, int arg2, float farg0) {
    float sc[2];
    float var_f31;

    mtSinCosf__FfPfPf(lbl_41_rodata_102C * farg0, &sc[1], &sc[0]);
    float t = fn_41_6AD8(arg0 + 0x38, arg1);
    *(float*)(lbl_41_bss_504 + 0x18) = sc[0] * t;
    *(float*)(lbl_41_bss_504 + 0x1c) = sc[1] * t;
    *(float*)(lbl_41_bss_504 + 0x20) = sc[0] * *(float*)(arg0 + 0x58);
    *(float*)(lbl_41_bss_504 + 0x24) = sc[1] * *(float*)(arg0 + 0x58);
    var_f31 = lbl_41_rodata_101C;
    if (arg1->holder->p64->slot17(0x12000003) == 0 && arg2 != 0) {
        var_f31 = arg1->holder->p0c->slot9();
    }
    *(float*)(lbl_41_bss_504 + 0x18) *= var_f31;
    *(float*)(lbl_41_bss_504 + 0x20) *= var_f31;
}
