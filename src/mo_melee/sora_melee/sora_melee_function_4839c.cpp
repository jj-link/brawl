#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_4088[];
extern char lbl_27_data_42A0[];
extern char lbl_27_data_4228[];
extern char lbl_27_data_4230[];
extern char __RTTI__11soEventUnit[];

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
    void* f0;
    void* f4;
    s16 f8;
    s16 fA;
    s32 fC;
};

extern "C" void* fn_27_4839C(Self* self, void* arg1) {
    s32 result = 0;
    Mgr* mgr2;
    s16 temp;
    s32 eid;
    char* ctx;
    char* obj;

    self->f0 = lbl_27_data_4088;
    ctx = *(char**)((char*)arg1 + 0xD8);
    obj = *(char**)(ctx + 0x80);
    eid = ((I9*)(obj + 8))->get(arg1);
    self->f4 = lbl_27_data_42A0;
    self->f8 = eid;
    self->fA = 16;
    self->fC = result;

    if (eid > 0 && eid > -1) {
        if (((Sys*)getInstance__13soEventSystemFv())->check(eid) != 0) {
            Mgr* mgr = (Mgr*)getManager__13soEventSystemFl(
                getInstance__13soEventSystemFv(), self->f8);
            if (mgr->check(self->fA) == 0) {
                result = 0;
                self->fC = result;
            } else {
                temp = self->fA;
                mgr2 = (Mgr*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), self->f8);
                if (mgr2->check(temp) == 0) {
                    result = 0;
                } else {
                    Unit* u = (Unit*)__dynamic_cast(
                        mgr2->s10(temp), 0, lbl_27_data_4228, __RTTI__11soEventUnit, 0);
                    if (u == 0) {
                        result = 0;
                    } else {
                        result = u->get();
                    }
                }
                self->fC = result;
            }
        }
    }

    self->f0 = lbl_27_data_4230;
    self->f4 = lbl_27_data_4230 + 0x18;
    return self;
}
