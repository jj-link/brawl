#pragma force_active on

struct GroundBase {
    char pad[0x3C];
};

struct Ground : GroundBase {
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
    virtual void enable(bool);
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
    virtual void unused39();
    virtual void unused40();
    virtual void unused41();
    virtual void unused42();
    virtual void unused43();
    virtual void unused44();
    virtual void unused45();
    virtual void unused46();
    virtual void unused47();
    virtual void unused48();
    virtual void unused49();
    virtual void unused50();
    virtual void unused51();
    virtual void unused52();
    virtual void unused53();
    virtual void unused54();
    virtual void unused55();
    virtual void unused56();
    virtual void unused57();
    virtual void unused58();
    virtual void unused59();
    virtual void unused60();
    virtual void unused61();
    virtual void unused62();
    virtual void unused63();
    virtual void unused64();
    virtual void unused65();
    virtual void unused66();
    virtual void unused67();
    virtual void unused68();
    virtual void unused69();
    virtual void unused70();
    virtual void unused71();
    virtual void unused72();
    virtual void unused73();
    virtual void unused74();
    virtual void unused75();
    virtual void unused76();
    virtual void unused77();
    virtual void unused78();
    virtual void unused79();
    virtual void unused80();
    virtual void unused81();
    virtual void unused82();
    virtual void unused83();
    virtual void unused84();
    virtual void unused85();
    virtual void unused86();
    virtual void unused87();
    virtual void unused88();
    virtual void unused89();
    virtual void unused90();
    virtual void unused91();
    virtual void unused92();
    virtual void unused93();
    virtual void unused94();
    virtual void unused95();
    virtual void setState(int, int);
};

extern "C" {
    extern const float lbl_67_rodata_10;
    extern const float lbl_67_rodata_14;
    void setEnableCollisionStatus__6GroundFb(Ground*, bool);
}

#define FIELD(type, off) (*(type*)((char*)self + (off)))

extern "C" void fn_67_3778(Ground* self) {
    if (FIELD(unsigned char, 0x150) == 1) {
        if (((FIELD(unsigned char, 0x6C) >> 5) & 1) == 0) {
            setEnableCollisionStatus__6GroundFb(self, true);
        }
        self->enable(true);
        self->setState(0, 0);
        FIELD(float, 0x18C) = lbl_67_rodata_14;
        FIELD(float, 0x190) = lbl_67_rodata_14;
        FIELD(float, 0x194) = lbl_67_rodata_14;
        FIELD(float, 0x180) = lbl_67_rodata_10;
        FIELD(float, 0x184) = lbl_67_rodata_10;
        FIELD(float, 0x188) = lbl_67_rodata_10;
    }
}
