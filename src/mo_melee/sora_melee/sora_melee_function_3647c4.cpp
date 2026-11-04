#pragma force_active on
#pragma scheduling off

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
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15(float, unsigned int);
    virtual int slot16();
};

struct Comp {
    char pad0[0x64];
    soNullable* m64;
    char pad1[8];
    soNullable* m70;
};

struct Fighter {
    char pad[0xD8];
    Comp* comp;
};

extern "C" int fn_27_30FACC(void*, unsigned int, int, void*, unsigned int);
extern unsigned char lbl_27_bss_7B0C[];
extern const float lbl_27_rodata_7AF4;

extern "C" void fn_27_3647C4(void*, Fighter* f) {
    int status = f->comp->m70->slot16();
    switch (fn_27_30FACC(lbl_27_bss_7B0C, 0, status, f, 1)) {
    case 0x117:
        f->comp->m64->slot15(lbl_27_rodata_7AF4, 0x21000004);
        break;
    case 0x119:
        f->comp->m64->slot15(lbl_27_rodata_7AF4, 0x21000005);
        break;
    }
}
