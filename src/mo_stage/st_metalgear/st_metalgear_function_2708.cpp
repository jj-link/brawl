#pragma force_active on
extern "C" void __ct__10grYakumonoFPCc(void*, const char*);
extern "C" const float lbl_71_rodata_50;
extern "C" unsigned char lbl_71_data_980[];

struct Task {
    unsigned char data[0x3C];
};

struct Object : Task {
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
    virtual void setupMelee();

    unsigned char pad40[0x110];
    unsigned char unk150;
    unsigned char pad151[3];
    float unk154;
};

extern "C" Object* fn_71_2708(Object* self, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    *(void**)((unsigned char*)self + 0x3C) = lbl_71_data_980;
    self->unk150 = 0;
    self->unk154 = lbl_71_rodata_50;
    self->setupMelee();
    return self;
}
