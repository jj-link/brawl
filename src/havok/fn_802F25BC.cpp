#pragma force_active on
#pragma use_lmw_stmw on

struct Inner {
    virtual void unused0();
    virtual void unused1();
    virtual void apply(void*);
};

struct Item {
    unsigned char pad0[0x60];
    Inner** unk60;
    int unk64;
};

struct Mid {
    unsigned char pad0[0x28];
    Item** unk28;
    int unk2C;
};

struct Outer {
    unsigned char pad0[8];
    Mid* unk8;
};

extern "C" void fn_802F25BC(Outer* arg0) {
    Item* r31;
    int r29;
    int r30;
    int r28;
    r28 = 0;
    r29 = 0;

    while (r28 < arg0->unk8->unk2C) {
        int r27 = 0;
        r30 = 0;
        r31 = *(Item**)((char*)arg0->unk8->unk28 + r29);
        while (r27 < r31->unk64) {
            Inner* p = *(Inner**)((char*)r31->unk60 + r30);
            p->apply((char*)arg0->unk8 + 0x170);
            r30 += 4;
            r27 += 1;
        }
        r29 += 4;
        r28 += 1;
    }
}
