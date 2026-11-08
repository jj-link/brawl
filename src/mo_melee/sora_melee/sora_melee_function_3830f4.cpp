#include <gf/gf_task_scheduler.h>
#include <mt/mt_vector.h>

#pragma force_active on

struct Bits {
    int x, y, z;
};

struct EffectArg {
    int id;
    bool flag;
    Vec3f pos;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(unsigned int);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(unsigned int);
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual int slot16(int = 0, EffectArg* = 0, int = 0);
    virtual void slot17();
    virtual void slot18();
    virtual void slot19(unsigned int);
};

class Status {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual int slot16();
};

struct Mid {
    char pad[0x54];
    Object_vptr_0* effect;
    char pad58[0xc];
    Object_vptr_0* work;
    char pad68[8];
    Status* status;
};

struct Obj {
    char pad[0xd8];
    Mid* mid;
};

struct Top {
    char pad[0x60];
    Obj* obj;
};

extern "C" {
extern char lbl_27_data_94D38[];
extern char __RTTI__6gfTask[];
extern float lbl_27_rodata_7C14;

void* __dynamic_cast(void*, long, const void*, const void*, long);
void fn_27_394E64(Vec3f*, void*, int);
void fn_27_383A44(void*, int);
}

extern "C" void fn_27_3830F4(Top* self) {
    Vec3f fallback;
    EffectArg fallbackEffect;

    self->obj->mid->work->slot19(0x1200003e);
    Obj* obj = self->obj;

    if (obj->mid->status->slot16() == 0x116) {
        void* p = (void*)obj->mid->work->slot4(0x10000043);
        gfTask* task = gfTaskScheduler::getInstance()->getTaskById(
            (gfTask::Category)12, (unsigned int)p);

        if (task) {
            p = __dynamic_cast(
                task, 0x3c, lbl_27_data_94D38, __RTTI__6gfTask, 1);
            EffectArg e2;
            Vec3f b;
            Vec3f a;
            fn_27_394E64(&a, p, 0);
            EffectArg e1;
            e1.id = 0x839;
            e1.flag = false;
            *(Bits*)&e1.pos = *(Bits*)&a;
            obj->mid->effect->slot16(-1, &e1, 0);

            fn_27_394E64(&b, p, 1);
            e2.id = 0x839;
            e2.flag = false;
            *(Bits*)&e2.pos = *(Bits*)&b;
            obj->mid->effect->slot16(-1, &e2, 0);
        }
    } else {
        float y = obj->mid->work->slot12(0x11000014);
        float x = obj->mid->work->slot12(0x11000013);
        fallback.m_x = x;
        fallback.m_y = y;
        fallback.m_z = lbl_27_rodata_7C14;
        fallbackEffect.id = 0x839;
        fallbackEffect.flag = false;
        *(Bits*)&fallbackEffect.pos = *(Bits*)&fallback;
        obj->mid->effect->slot16(-1, &fallbackEffect, 0);
    }

    fn_27_383A44(self, 0);
}
