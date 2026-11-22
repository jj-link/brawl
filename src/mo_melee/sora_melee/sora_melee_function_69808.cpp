#include <types.h>
#include <so/event/so_event_system.h>
#include <nw4r/math/math_arithmetic.h>
#include <so/posture/so_posture_module_simple.h>
#include <mt/mt_vector.h>

#pragma force_active on

extern "C" {
extern char lbl_27_bss_D40[];
extern char lbl_27_data_7A08[];
extern char __RTTI__11soEventUnit[];
extern const float lbl_27_rodata_930[];

void* __dynamic_cast(void*, long, const void*, const void*, long);
}

struct Access;

struct Observer {
    virtual void v0();
    virtual void notify(float, float, Access*);
};

struct List {
    virtual void l0();
    virtual void l1();
    virtual Observer** at(int);
    virtual void l3();
    virtual int size();
};

struct Unit {
    virtual void u0();
    virtual void u1();
    virtual void u2();
    virtual void u3();
    virtual void u4();
    virtual void u5();
    virtual void u6();
    virtual List* list();
};

struct OtherBase {
    char pad[8];
};

struct Other : OtherBase {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    virtual void a25();
    virtual void a26();
    virtual void a27();
    virtual void a28();
    virtual void a29();
    virtual void a30();
    virtual void a31();
};

struct Modules {
    char pad[12];
    soPostureModule* posture;
    char pad2[0x28];
    Other* other;
};

struct Access {
    char pad[0xd8];
    Modules* modules;
};

struct Array {
    float* data;
    int count;
};

struct Self {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual int active();

    char pad[0x10];
    short id;
    short unit;
    List* cache;
    Access* access;
    Array* array;
    int index;
    float angle;
    float current;
    float previous;
    unsigned char phase : 3;
    unsigned char fl4 : 1;
    unsigned char fl3 : 1;
    unsigned char fl2 : 1;
    unsigned char fl1 : 1;
    unsigned char fl0 : 1;
};

struct ListImpl : List {};

inline ListImpl* selectList(Self* self) {
    short id = self->id;
    short id2;
    soEventManager* mgr;
    ListImpl* cur;
    Unit* unit;
    int flag;

    if (id <= -1)
        return (ListImpl*)lbl_27_bss_D40;

    if (self->cache != 0)
        goto C;

    if (id <= -1 ||
        soEventSystem::getInstance()->getInstanceManager().isContain(id) == 0) {
        flag = 0;
        goto CHECK;
    }

    if (soEventSystem::getInstance()->getManager(self->id)
            ->getObserverCapacity(self->unit) == 0) {
        self->cache = 0;
        flag = 0;
        goto CHECK;
    }

    id2 = self->unit;
    mgr = soEventSystem::getInstance()->getManager(self->id);
    if (mgr->getObserverCapacity(id2) == 0) {
        cur = 0;
    } else {
        unit = (Unit*)__dynamic_cast(
            mgr->getEventUnit(id2), 0, lbl_27_data_7A08,
            __RTTI__11soEventUnit, 0);
        if (unit == 0)
            cur = 0;
        else
            cur = (ListImpl*)unit->list();
    }

    self->cache = cur;
    flag = (cur != 0);

CHECK:
    if (flag == 0)
        return (ListImpl*)lbl_27_bss_D40;

C:
    mgr = soEventSystem::getInstance()->getManager(self->id);
    if (mgr->getObserverCapacity(self->unit) == 0) {
        self->cache = 0;
        return (ListImpl*)lbl_27_bss_D40;
    }
    return (ListImpl*)self->cache;
}

inline ListImpl* selectListA(Self* self) {
    short id1 = self->id;
    soEventManager* mgr;
    ListImpl* cur;
    Unit* unit;
    int flag;
    short id2;

    if (id1 <= -1)
        return (ListImpl*)lbl_27_bss_D40;

    if (self->cache != 0)
        goto C;

    if (id1 <= -1 ||
        soEventSystem::getInstance()->getInstanceManager().isContain(id1) == 0) {
        flag = 0;
        goto CHECK;
    }

    if (soEventSystem::getInstance()->getManager(self->id)
            ->getObserverCapacity(self->unit) == 0) {
        self->cache = 0;
        flag = 0;
        goto CHECK;
    }

    id2 = self->unit;
    mgr = soEventSystem::getInstance()->getManager(self->id);
    if (mgr->getObserverCapacity(id2) == 0) {
        cur = 0;
    } else {
        unit = (Unit*)__dynamic_cast(
            mgr->getEventUnit(id2), 0, lbl_27_data_7A08,
            __RTTI__11soEventUnit, 0);
        if (unit == 0)
            cur = 0;
        else
            cur = (ListImpl*)unit->list();
    }

    self->cache = cur;
    flag = (cur != 0);

CHECK:
    if (flag == 0)
        return (ListImpl*)lbl_27_bss_D40;

C:
    mgr = soEventSystem::getInstance()->getManager(self->id);
    if (mgr->getObserverCapacity(self->unit) == 0) {
        self->cache = 0;
        return (ListImpl*)lbl_27_bss_D40;
    }
    return (ListImpl*)self->cache;
}

extern "C" void fn_27_69808(Self* self, unsigned mode) {
    const float* constants = lbl_27_rodata_930;

    if (!self->active())
        return;

    Vec3f result = self->access->modules->posture->getRot(0);

    if (mode == 1) {
        float lr = self->access->modules->posture->getLr();
        self->current = self->array->data[self->index];
        self->index = self->index + 1;

        if (self->phase == 1 &&
            (float)(double)nw4r::math::FAbs(self->current) >= constants[1]) {
            self->phase = 2;

            if (self->fl4 == 1 &&
                !self->access->modules->posture->isRotYLrDifferentInnerLr()) {
                self->access->modules->posture->setLr(-lr);
                self->fl3 = 1;

                List* list = selectList(self);
                int count = list->size();
                for (int i = 0; i < count; ++i)
                    (*list->at(i))->notify(self->angle, -lr, self->access);
            }
        }

        if (self->index >= self->array->count) {
            self->phase = 0;
            self->current = constants[0];
            self->access->modules->posture->updateRotYLr();

            if (self->fl4 == 1 && !self->fl3) {
                self->access->modules->posture->setLr(-lr);

                List* list = selectListA(self);
                int count = list->size();
                for (int i = 0; i < count; ++i)
                    (*list->at(i))->notify(self->angle, -lr, self->access);
            }

            self->access->modules->other->a31();
        }

        float value = self->current;
        if (self->fl1 == 1) {
            if (self->phase == 1)
                value = constants[0];
            else if (self->phase == 2)
                value = constants[2];
        }

        result.m_y = value;
        self->previous = self->current;
        self->access->modules->posture->setRot(&result, 0);

        if (!self->phase)
            self->access->modules->posture->fixRot();
    } else {
        float value = self->previous;
        if (self->fl1 == 1) {
            if (self->phase == 1)
                value = constants[0];
            else if (self->phase == 2)
                value = constants[2];
        }

        result.m_y = value;
        self->access->modules->posture->setRot(&result, 0);
    }
}
