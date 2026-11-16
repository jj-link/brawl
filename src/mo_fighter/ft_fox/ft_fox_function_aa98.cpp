#pragma force_active on
typedef unsigned char u8;

struct FoxMod;

struct FoxVt {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void slot5(int, FoxMod*) = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual float slot14() = 0;
    virtual void slot15(int, int, int) = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual int slot18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void slot26(bool, bool, bool) = 0;
};

struct FoxD8 {
    u8 p0[0x8];
    FoxVt* at8;
    u8 p1[0x1C];
    FoxVt* at28;
    u8 p2[0x44];
    FoxVt* at70;
    u8 p3[0x14];
    FoxVt* at88;
};

struct FoxMod {
    u8 p0[0xD8];
    FoxD8* d8;
};

struct FoxSelf {
    u8 p0[0x60];
    FoxMod* mod;
    u8 p1[0x1CD44 - 0x64];
    u8 state0;
    u8 state1;
};

extern "C" int fn_27_135DE8(void*);
extern float lbl_97_rodata_0;

extern "C" int fn_97_AA98(FoxSelf* self) {
    int one = 1;
    if (self->state0 == 1) {
        if (self->mod->d8->at70->slot18() == 0x11B) {
            if (self->mod->d8->at8->slot14() >= lbl_97_rodata_0) {
                self->mod->d8->at70->slot5(0x11B, self->mod);
            }
        } else {
            self->mod->d8->at70->slot5(0x11B, self->mod);
        }
        return 1;
    }
    if (self->state1 == 1) {
        self->mod->d8->at88->slot26(one, one, one);
        self->mod->d8->at28->slot15(0, 0, 2);
    }
    return fn_27_135DE8(self);
}
