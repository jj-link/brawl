#include <ft/ft_common_data_accesser.h>
#include <gf/gf_task_scheduler.h>
#include <so/so_external_value_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, long);
extern const char lbl_27_data_248[];
extern const char __RTTI__6gfTask[];
extern const float lbl_27_rodata_64DC;
}

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2(Vec3f*, float);
    virtual void slot3();
    virtual unsigned long slot4(unsigned long);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(unsigned long);
    virtual void slot13(float, unsigned long);
    virtual void slot14();
    virtual void slot15(Vec3f*, int);
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual float slot22();
};

class Kinetic {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22(int, Vec3f*);
};

class ModelBase {
public:
    char pad[8];
};

class Model : public ModelBase {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual Vec3f s36(int, int);
};

struct Modules {
    char pad0[4];
    Model* model;
    char pad8[4];
    Object_vptr_0* posture;
    char pad10[12];
    Kinetic* kinetic;
    char pad20[0x44];
    Object_vptr_0* work;
    char pad68[8];
    Object_vptr_0* status;
};

struct Access {
    char pad[0xd8];
    Modules* modules;
};

struct Param {
    char pad[0x14];
    float value;
};

struct Data {
    char pad[0x8c];
    Param* param;
};

extern "C" void fn_27_2F3E28(void*, Access* a) {
    a->modules->status->slot16();

    Object_vptr_0* work = a->modules->work;
        Object_vptr_0* ownWork;
    float angle = work->slot12(0x11000002);
    float result =
        angle + ((Data*)g_ftCommonDataAccesser.getData((ftKind)3))->param->value;
    work->slot13(result, 0x11000002);

    int id = a->modules->work->slot4(0x10000000);
    StageObject* obj = (StageObject*)__dynamic_cast(
        gfTaskScheduler::getInstance()->getTaskById((gfTask::Category)10, id),
        0x3c, lbl_27_data_248, __RTTI__6gfTask, 0);

    if (obj) {
        Access* other = (Access*)soExternalValueAccesser::getModuleAccesser(obj);
        ownWork = a->modules->work;
        float otherAngle = other->modules->work->slot12(0x11000014);
        Vec3f pos = other->modules->model->s36(0x2b, 0);
        float lr = a->modules->posture->slot22();
        float offset = ownWork->slot12(0x11000001);
        pos.m_y += offset * lr;

        Object_vptr_0* ownPosture = a->modules->posture;
        float otherLr = other->modules->posture->slot9();
        ownPosture->slot2(&pos, otherLr);

        Vec3f v(lbl_27_rodata_64DC, lbl_27_rodata_64DC, result);
        a->modules->kinetic->s22(0, &v);

        Vec3f v2(lbl_27_rodata_64DC, lbl_27_rodata_64DC, otherAngle);
        a->modules->posture->slot15(&v2, 0);
    }
}
