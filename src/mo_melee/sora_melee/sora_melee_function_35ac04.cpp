#pragma force_active on

typedef unsigned int u32;

class Status {
public:
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
    virtual int getKind();
};

class Flags {
public:
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
    virtual unsigned char first();
    virtual void unused24();
    virtual unsigned char second();
};

struct Modules {
    char pad[0x5C];
    Flags* flags;
    char pad60[0x1C];
    Status* status;
};

struct Accesser {
    char pad[0xD8];
    Modules* modules;
};

class Self {
public:
    virtual void unused0();
    virtual void process(Accesser*);
    char pad[0x3C];
    float first;
    float unused44;
    float second;
};

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    Accesser*, u32, u32);
extern "C" float lbl_27_rodata_79FC;

extern "C" void fn_27_35AC04(Self* self, Accesser* accesser) {
    switch (accesser->modules->status->getKind()) {
    case 0x67:
        float first;
        float second;
        if (accesser->modules->flags->first() == 0) {
            first = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                accesser, 0xFB2, 0);
        } else {
            first = lbl_27_rodata_79FC;
        }
        if (accesser->modules->flags->second() == 0) {
            second = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                accesser, 0xFB2, 0);
        } else {
            second = lbl_27_rodata_79FC;
        }
        self->first = first;
        self->second = second;
        break;
    }
    self->process(accesser);
}
