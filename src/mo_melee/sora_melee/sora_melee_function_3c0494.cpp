#include <mt/mt_vector.h>

#pragma force_active on
#pragma fp_contract off

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3();
    virtual int slot4(unsigned int);
    virtual void slot5(int, unsigned int);
    virtual void* slot6(int);
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(unsigned int);
    virtual void slot13(unsigned int, float);
};

class Class_5860 {
public:
    virtual void fn_27_565F0();
    virtual void fn_27_56888();
    virtual void fn_27_5680C();
    virtual void fn_27_567F8();
    virtual int fn_27_568AC(unsigned int);
    virtual void fn_27_568B4(int, unsigned int);
    virtual void fn_27_569A4();
    virtual void fn_27_56A4C();
    virtual void fn_27_56AC8();
    virtual void fn_27_56BAC();
    virtual void fn_27_57528();
    virtual void fn_27_576A4();
    virtual float fn_27_57590(unsigned int);
    virtual void fn_27_56BEC(unsigned int, float);
};

struct PostureBase {
    char pad[8];
};

class Posture : public PostureBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual Vec3f getRotation(int);
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void setRotation(int, const Vec3f*);
};

struct TaskBase {
    char pad[0x3c];
};

class Task : public TaskBase {
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
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual int slot40();
};

struct Access;

class Energy {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int, const Vec2f*, const Vec3f*, Access*);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();

    char pad4;
    unsigned char flags;
    char pad6[2];
    float x;
    float y;
    float field10;
    float field14;
    float field18;
    float field1c;
};

class Kinetic {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void* slot6(int);
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual Vec2f slot13(short*);
};

struct Modules {
    char pad0[4];
    Posture* model;
    char pad8[4];
    soNullable* posture;
    char pad10[4];
    soNullable* situation;
    char pad18[0x4c];
    Class_5860* work;
    char pad68[0x14];
    Kinetic* kinetic;
};

struct Access {
    char pad0[8];
    Task* task;
    char padc[0xcc];
    Modules* modules;
};

extern "C" {
    void* __dynamic_cast(void*, long, const void*, const void*, short);
    float fn_27_192278(void*, unsigned long);
    void fn_27_89DAC(int, void*);

    extern char lbl_27_data_2E5F8[];
    extern char lbl_27_data_2E430[];
    extern char lbl_27_data_CDF8[];
    extern const float lbl_27_rodata_8080[];
}

extern "C" void fn_27_3C0494(void*, Access* self)
{
    int joint;
    int previous;
    soNullable* situationModule = self->modules->situation;
    const float* constants = lbl_27_rodata_8080;
    int situation = situationModule->slot3();
    previous = self->modules->work->fn_27_568AC(0x20000008);

    self->modules->work->fn_27_56BEC(0x21000009, constants[1]);
    float angle = self->modules->work->fn_27_57590(0x21000006);
    float speed = self->modules->work->fn_27_57590(0x21000005);
    float adjustment = constants[5] * fn_27_192278(self, 0xfba);
    angle += speed * adjustment *
             self->modules->work->fn_27_57590(0x2100000a);

    while (angle < constants[1])
        angle += constants[6];
    while (angle > constants[6])
        angle -= constants[6];

    self->modules->work->fn_27_56BEC(0x21000006, angle);
    float rotation = self->modules->work->fn_27_57590(0x21000006);

    joint = self->task->slot40() == 5 ? 0x197 : 4;
    Vec3f rot = self->modules->model->getRotation(joint);
    rot.m_x = constants[7] * rotation;
    self->modules->model->setRotation(joint, &rot);

    joint = self->task->slot40() == 5 ? 0x197 : 4;
    Vec3f facingRot = self->modules->model->getRotation(joint);
    if (self->modules->posture->slot9() == constants[3])
        facingRot.m_y = constants[4];
    else
        facingRot.m_y = constants[1];
    self->modules->model->setRotation(joint, &facingRot);

    if (situation != previous) {
        if (situation == 0) {
            Energy* energy = static_cast<Energy*>(
                __dynamic_cast(self->modules->kinetic->slot6(3), 0,
                               lbl_27_data_2E5F8, lbl_27_data_CDF8, 1));
            float value = constants[0] *
                          self->modules->work->fn_27_57590(0x21000011);
            Vec3f zero;
            zero.m_x = constants[1];
            zero.m_y = constants[1];
            zero.m_z = constants[1];
            Vec2f velocity(value, constants[1]);
            energy->slot5(0x16, &velocity, &zero, self);
            Vec2f groundSpeed(value, constants[1]);
            *(Vec2f*)((char*)energy + 0x18) = groundSpeed;
            energy->slot12();
            energy->flags |= 0x80;

            Class_5860* work = self->modules->work;
            float parameter = fn_27_192278(self, 0xfa2);
            work->fn_27_56BEC(0x21000008, parameter);
            fn_27_89DAC(1, self);
        } else {
            Energy* energy = static_cast<Energy*>(
                __dynamic_cast(self->modules->kinetic->slot6(3), 0,
                               lbl_27_data_2E5F8, lbl_27_data_CDF8, 1));
            Energy* gravity = static_cast<Energy*>(
                __dynamic_cast(self->modules->kinetic->slot6(1), 0,
                               lbl_27_data_2E430, lbl_27_data_CDF8, 1));

            short flag = 1;
            Vec2f velocity;
            Vec2f::copy(velocity, self->modules->kinetic->slot13(&flag));
            Vec3f zero(constants[1], constants[1], constants[1]);
            energy->slot5(6, &Vec2f(velocity.m_x, constants[1]), &zero, self);
            energy->flags |= 0x80;

            Vec3f zero2(constants[1], constants[1], constants[1]);
            gravity->slot5(0, &Vec2f(constants[1], velocity.m_y), &zero2, self);
            gravity->field10 = -fn_27_192278(self, 0xfa0);
            gravity->field1c = fn_27_192278(self, 0xfa1);
            gravity->field14 = fn_27_192278(self, 0xfa1);
            gravity->flags |= 0x80;
        }
    }

    self->modules->work->fn_27_568B4(situation, 0x20000008);
}
