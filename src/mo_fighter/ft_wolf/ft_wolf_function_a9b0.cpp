#pragma force_active on
#include <types.h>

struct FtWolfMod60;

struct FtWolfVObj {
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5(int, FtWolfMod60*) = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual float v14() = 0;
    virtual void v15(int, int, int) = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual int v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26(bool, bool, bool) = 0;
};

struct FtWolfD8 {
    u8 p0[0x8];
    FtWolfVObj* at8;
    u8 p1[0x1C];
    FtWolfVObj* at28;
    u8 p2[0x44];
    FtWolfVObj* at70;
    u8 p3[0x14];
    FtWolfVObj* at88;
};

struct FtWolfMod60 {
    u8 p0[0xD8];
    FtWolfD8* d8;
};

struct FtWolfSelf {
    u8 p0[0x60];
    FtWolfMod60* m60;
    u8 p1[0x1CC88 - 0x64];
    u8 flag0;
    u8 flag1;
};

extern "C" int fn_27_135DE8(void*);
extern float lbl_125_rodata_0;

extern "C" int fn_125_A9B0(FtWolfSelf* self) {
    if (self->flag0 == 1) {
        if (self->m60->d8->at70->v18() == 0x11b) {
            if (self->m60->d8->at8->v14() >= lbl_125_rodata_0) {
                self->m60->d8->at70->v5(0x11b, self->m60);
            }
        } else {
            self->m60->d8->at70->v5(0x11b, self->m60);
        }
        return 1;
    }
    if (self->flag1 == 1) {
        self->m60->d8->at88->v26(true, true, true);
        self->m60->d8->at28->v15(0, 0, 2);
    }
    return fn_27_135DE8(self);
}
