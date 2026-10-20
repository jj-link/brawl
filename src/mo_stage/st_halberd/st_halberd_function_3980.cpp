#pragma force_active on
extern "C" void __ct__10grYakumonoFPCc(void*, const char*);
extern "C" const float lbl_57_rodata_110[];
extern "C" void* lbl_57_data_5C0[];

struct Base {
    char pad[0x3C];
};

struct Halberd : Base {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void dummy5();
    virtual void dummy6();
    virtual void dummy7();
    virtual void dummy8();
    virtual void dummy9();
    virtual void dummy10();
    virtual void dummy11();
    virtual void dummy12();
    virtual void dummy13();
    virtual void dummy14();
    virtual void dummy15();
    virtual void dummy16();
    virtual void dummy17();
    virtual void dummy18();
    virtual void dummy19();
    virtual void dummy20();
    virtual void dummy21();
    virtual void dummy22();
    virtual void dummy23();
    virtual void dummy24();
    virtual void dummy25();
    virtual void setup();

    char pad40[0x110];
    unsigned char unk150;
    float unk154;
    unsigned int unk158;
    unsigned int unk15C;
};

extern "C" Halberd* fn_57_3980(Halberd* self, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    *(void***)((char*)self + 0x3C) = lbl_57_data_5C0;
    self->unk150 = 0;
    self->unk154 = lbl_57_rodata_110[0];
    self->unk158 = 0;
    self->unk15C = 0;
    self->setup();
    return self;
}
