#pragma force_active on
extern "C" int fn_8005136C(int);
extern "C" float randf__Fv();
extern "C" const float lbl_56_rodata_80;
extern "C" const float lbl_56_rodata_A4;

struct Sub {
    unsigned char pad0[8];
    unsigned char flags;
    unsigned char pad1[13];
    signed char b16;
};

struct Global {
    unsigned char pad0[8];
    Sub* sub;
};

extern "C" Global* g_GameGlobal;

struct Data {
    unsigned char padding[0x3C];
};

struct Self : Data {
    virtual void slot0();
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
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot29(int);
    unsigned char pad2[0x160 - 0x40];
    int i160;
    unsigned char pad3[0x18C - 0x164];
    float f18C;
    unsigned char pad4[0x1B0 - 0x190];
    unsigned char flag0;
    unsigned char flag1;
};

extern "C" void fn_56_46BC(Self* self) {
    self->i160 = 10;
    self->f18C = lbl_56_rodata_80;
    self->slot29(1);
    if (self->flag0 == 0) {
        self->flag0 = 1;
        Sub* s = g_GameGlobal->sub;
        if (s != 0 && (unsigned)((s->flags >> 2) & 0x3F) != 4u && s->b16 != 0 && fn_8005136C(0x40) != 0 && !(randf__Fv() < lbl_56_rodata_A4)) {
            self->flag1 = 1;
        }
    }
}
