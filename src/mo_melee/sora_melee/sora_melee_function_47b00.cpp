#include <so/event/so_event_system.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_4088[];
extern char lbl_27_data_4190[];
extern char lbl_27_data_4118[];
extern char lbl_27_data_4120[];
extern char __RTTI__11soEventUnit[];
void* __dynamic_cast(void*, long, const void*, const void*, long);
}

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual short slot7(void*);
    virtual void slot8();
};

struct Sys {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int check(long);
};

struct Mgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int check(long);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void* get(long);
};

struct Unit {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int get();
};

struct Self {
    void* f0;
    void* f4;
    short f8;
    short fA;
    int fC;
};

inline int getResult(Self* self) {
    short id = self->fA;
    Mgr* mgr = (Mgr*)soEventSystem::getInstance()->getManager(self->f8);
    if (mgr->check(id) == 0)
        return 0;
    Unit* u = (Unit*)__dynamic_cast(mgr->get(id), 0, lbl_27_data_4118, __RTTI__11soEventUnit, 0);
    if (u == 0)
        return 0;
    return u->get();
}

extern "C" void* fn_27_47B00(Self* self, void* arg1) {
    int result = 0;
    int eid;
    Mgr* mgr;
    char* ctx;
    char* obj;

    self->f0 = lbl_27_data_4088;
    ctx = *(char**)((char*)arg1 + 0xD8);
    obj = *(char**)(ctx + 0x80);
    eid = ((Object_vptr_0*)(obj + 8))->slot7(arg1);
    self->f4 = lbl_27_data_4190;
    self->f8 = eid;
    self->fA = 15;
    self->fC = result;

    if (eid > 0 && eid > -1) {
        if (((Sys*)soEventSystem::getInstance())->check(eid) != 0) {
            mgr = (Mgr*)soEventSystem::getInstance()->getManager(self->f8);
            if (mgr->check(self->fA) == 0) {
                self->fC = 0;
            } else {
                result = getResult(self);
                self->fC = result;
            }
        }
    }

    self->f0 = lbl_27_data_4120;
    self->f4 = lbl_27_data_4120 + 0x18;
    return self;
}