#pragma force_active on
struct Prefix {
    unsigned char pad0[0x3C];
};

struct Homerun : Prefix {
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
    virtual void setup();

    unsigned char pad40[0x110];
    unsigned char unk150;
    unsigned char pad151[3];
    float unk154;
};

extern "C" {
void __ct__10grYakumonoFPCc(Homerun*, const char*);
extern const float lbl_88_rodata_E0;
extern unsigned char lbl_88_data_870[];

Homerun* fn_88_4368(Homerun* self, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    *(void**)((char*)self + 0x3C) = lbl_88_data_870;
    self->unk150 = 0;
    self->unk154 = lbl_88_rodata_E0;
    self->setup();
    return self;
}
}
