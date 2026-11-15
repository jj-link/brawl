#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_7700[];
extern char lbl_27_data_76C0[];
extern char lbl_27_data_7608[];
extern char lbl_27_data_7610[];
extern char __RTTI__11soEventUnit[];
extern const f32 lbl_27_rodata_910[];

void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void* __dynamic_cast(void*, long, const void*, const void*, long);
}

struct I9 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual s16 get(void*);
};

struct Sys {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual s32 check(long);
};

struct Mgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 check(long);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void* s10(long);
};

struct Unit {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual s32 get();
};

struct Self {
    void* vt;
    void* p4;
    s16 f8;
    s16 fA;
    s32 fC;
    void* p10;
    s32 f14;
    s32 f18;
    s32 f1C;
    f32 f20;
    unsigned char pad24[11];
    unsigned char b2F;
    unsigned char pad30[2];
    unsigned char b32;
};

inline s32 getResult(Self* self) {
    s16 id = self->fA;
    Mgr* mgr2 = (Mgr*)getManager__13soEventSystemFl(
        getInstance__13soEventSystemFv(), self->f8);
    if (mgr2->check(id) == 0) {
        return 0;
    }
    Unit* u = (Unit*)__dynamic_cast(
        mgr2->s10(id), 0, lbl_27_data_7608, __RTTI__11soEventUnit, 0);
    if (u == 0) {
        return 0;
    }
    return u->get();
}

extern "C" Self* fn_27_65EE4(Self* self, void* arg1) {
    s32 result = 0;
    s32 eid;
    Mgr* mgr;
    char* ctx;
    char* obj;

    self->vt = lbl_27_data_7700;
    ctx = *(char**)((char*)arg1 + 0xD8);
    obj = *(char**)(ctx + 0x80);
    eid = ((I9*)(obj + 8))->get(arg1);
    self->p4 = lbl_27_data_76C0;
    self->f8 = eid;
    self->fA = 13;
    self->fC = result;

    if (eid > 0 && eid > -1) {
        if (((Sys*)getInstance__13soEventSystemFv())->check(eid) != 0) {
            mgr = (Mgr*)getManager__13soEventSystemFl(
                getInstance__13soEventSystemFv(), self->f8);
            if (mgr->check(self->fA) == 0) {
                self->fC = result;
            } else {
                result = getResult(self);
                self->fC = result;
            }
        }
    }

    const f32& f = lbl_27_rodata_910[0];
    u8 t = 1;
    s32 n = -1;
    char* v2 = lbl_27_data_7610 + 0x70;
    char* v = lbl_27_data_7610;
    u8 z = 0;
    self->vt = v;
    self->p4 = v2;
    self->p10 = arg1;
    self->f14 = n;
    self->f18 = n;
    self->f1C = n;
    self->f20 = f;
    self->b2F = t;
    self->b32 = z;
    return self;
}
