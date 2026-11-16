#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_27078[];
extern char lbl_27_data_27038[];
extern char lbl_27_data_93878[];
extern char __RTTI__11soEventUnit[];
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void* __dynamic_cast(void*, long, const void*, const void*, long);
}

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void* slot4(long);
    virtual void slot5();
    virtual void* slot6(long);
    virtual long slot7();
    virtual void* slot8(long);
};

struct Self {
    void* vt;
    short id;
    short kind;
    long value;
    long a2;
    long a1;
    long a3;
    void* vt2;
};

extern "C" Self* fn_27_376848(Self* self, long a1, long a2, long a3) {
    long value;
    self->vt = lbl_27_data_27078;
    self->id = -1;
    self->kind = 2;
    value = 0;
    self->value = value;
    if (self->id > 0 && self->id > -1) {
        void* sys = ((Object_vptr_0*)getInstance__13soEventSystemFv())->slot6(-1);
        if (sys != 0) {
            Object_vptr_0* mgr = (Object_vptr_0*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->id);
            if (mgr->slot4(self->kind) == 0) {
                self->value = value;
            } else {
                Object_vptr_0* m2;
                short k = self->kind;
                m2 = (Object_vptr_0*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->id);
                if (m2->slot4(k) == 0) {
                    value = 0;
                } else {
                    void* obj = m2->slot8(k);
                    Object_vptr_0* u = (Object_vptr_0*)__dynamic_cast(obj, 0, lbl_27_data_27038, __RTTI__11soEventUnit, 0);
                    if (u == 0) {
                        value = 0;
                    } else {
                        value = u->slot7();
                    }
                }
                self->value = value;
            }
        }
    }
    self->a2 = a2;
    self->vt2 = lbl_27_data_93878;
    self->vt = lbl_27_data_93878 + 8;
    self->a1 = a1;
    self->a3 = a3;
    return self;
}
