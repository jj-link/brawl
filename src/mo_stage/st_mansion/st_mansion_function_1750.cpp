#pragma force_active on
extern "C" {
void __ct__10grYakumonoFPCc(void*, const char*);
extern const float lbl_47_rodata_40;
extern unsigned char lbl_47_data_868[];
}

struct Base {
    unsigned char pad[0x3C];
};

struct MansionGround : Base {
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
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void setupMelee();

    unsigned char pad40[0x110];
    unsigned char unk150;
    unsigned char pad151[3];
    float unk154;
};

extern "C" MansionGround* fn_47_1750(MansionGround* self, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    *(void**)((char*)self + 0x3C) = lbl_47_data_868;
    self->unk150 = 0;
    self->unk154 = lbl_47_rodata_40;
    self->setupMelee();
    return self;
}
