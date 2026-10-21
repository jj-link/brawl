#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void __ct__10grYakumonoFPCc(void*, const char*);
extern unsigned char lbl_60_data_DD0[];
extern const float lbl_60_rodata_F8;
}

struct Base {
    unsigned char pad0[0x3C];
};

struct Work : Base {
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
    virtual void setup();
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
    virtual void setIndex(int);
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
    virtual void setNode(const char*);

    unsigned char pad40[0x150 - 0x40];
    float x, y, z;
    unsigned char field15C;
    float field160;
    int field164;
    int field168;
    unsigned char field16C, field16D;
    float field170;
    unsigned char field174;
    float field178;
};

extern "C" Work* fn_60_67EC(int index, const char* node, const char* name) {
    Work* p = (Work*)__nw__FUlQ25Heaps8HeapType(0x17C, 15);
    if (p) {
        __ct__10grYakumonoFPCc(p, name);
        *(void**)((char*)p + 0x3C) = lbl_60_data_DD0;
        p->field15C = 0;
        p->field160 = lbl_60_rodata_F8;
        p->field164 = 0;
        p->field168 = 0;
        p->field16C = 0;
        p->field16D = 0;
        p->field170 = lbl_60_rodata_F8;
        p->field174 = 2;
        p->field178 = lbl_60_rodata_F8;
        p->x = lbl_60_rodata_F8;
        p->y = lbl_60_rodata_F8;
        p->z = lbl_60_rodata_F8;
    }
    if (p) {
        p->setIndex(index);
        p->setNode(node);
    }
    p->setup();
    return p;
}
