#pragma force_active on
typedef unsigned long u32;

struct soModuleAccesser;

struct Module {
    unsigned char pad[0x3C];

    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual int getKind();
};

struct soModuleAccesser {
    unsigned char pad[8];
    Module* module;
};

struct Value {
    unsigned char pad[4];

    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual int getVariableInt(soModuleAccesser*, u32, u32);
};

extern "C" Value* lbl_27_bss_1B00[5];

extern "C" int getVariableInt__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser* accessor, u32 a, u32 b)
{
    int kind = accessor->module->getKind();
    return lbl_27_bss_1B00[kind]->getVariableInt(accessor, a, b);
}
