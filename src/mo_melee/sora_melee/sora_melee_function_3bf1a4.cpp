#pragma force_active on
#pragma fp_contract off
#include <types.h>
#include <mt/mt_vector.h>

class Posture {
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
    virtual float getLr();
    virtual void reverse();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void update();
};

class Situation {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int get();
};

class Work {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void setInt(int, u32);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float getFloat(u32);
    virtual void setFloat(float, u32);
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual int isFlag(u32);
};

class Kinetic {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void* getEnergy(int);
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual Vec2f getSpeed(const u16*);
};

class Energy {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void reset(int, Vec2f*, Vec3f*, void*);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void update();
};

struct ModelBase {
    char pad[8];
};

class Model : public ModelBase {
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
    virtual Vec3f getRotation(int);
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void setRotation(int, Vec3f*);
};

class Ground {
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
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void call(int, int, int, int);
};

class Sound {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void play(int, int, int);
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
    virtual int kind();
    virtual void slot41();
    virtual void slot42();
    virtual void action();
};

struct Modules {
    char pad00[4];
    Model* model;
    char pad08[4];
    Posture* posture;
    char pad10[4];
    Situation* situation;
    char pad18[0x38];
    Sound* sound;
    char pad54[8];
    Ground* ground;
    char pad60[4];
    Work* work;
    char pad68[0x14];
    Kinetic* kinetic;
};

struct Accesser {
    char pad00[8];
    Task* task;
    char pad0c[0xcc];
    Modules* modules;
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, long);
extern char lbl_27_data_2E5F8[], lbl_27_data_2E430[], lbl_27_data_CDF8[];
extern const float lbl_27_rodata_8080[];
float fn_27_192278(void*, unsigned long);
void fn_27_89DAC(int, void*);
}

extern "C" void fn_27_3BF1A4(void* self, Accesser* a) {
    const float* c = lbl_27_rodata_8080;

    if (a->modules->work->isFlag(0x22000014)) {
        float value = a->modules->work->getFloat(0x21000011);
        a->modules->posture->reverse();
        a->modules->posture->update();
        a->task->action();
        a->modules->work->setFloat(value, 0x2100000a);
    }

    if (a->modules->situation->get() == 0) {
        Energy* e = (Energy*)__dynamic_cast(a->modules->kinetic->getEnergy(3), 0, lbl_27_data_2E5F8, lbl_27_data_CDF8, 1);
        float x;
        Vec3f zero;
        Vec2f pos;
        x = *c * a->modules->work->getFloat(0x21000011);
        zero.m_x = c[1];
        zero.m_y = c[1];
        zero.m_z = c[1];
        pos.m_x = x;
        pos.m_y = c[1];
        e->reset(0x16, &pos, &zero, a);
        Vec2f dead(x, c[1]);
        *(Vec2f*)((char*)e + 0x18) = dead;
        e->update();
        ((unsigned char*)e)[5] |= 0x80;
        Work* work = a->modules->work;
        work->setFloat(fn_27_192278(a, 0xfa2), 0x21000008);
        fn_27_89DAC(1, a);
    } else {
        Energy* stop = (Energy*)__dynamic_cast(a->modules->kinetic->getEnergy(3), 0, lbl_27_data_2E5F8, lbl_27_data_CDF8, 1);
        Energy* grav = (Energy*)__dynamic_cast(a->modules->kinetic->getEnergy(1), 0, lbl_27_data_2E430, lbl_27_data_CDF8, 1);
        u16 mask = 1;
        Vec2f speed;
        Vec2f::copy(speed, a->modules->kinetic->getSpeed(&mask));
        Vec3f zs(c[1], c[1], c[1]);
        stop->reset(6, &Vec2f(speed.m_x, c[1]), &zs, a);
        ((unsigned char*)stop)[5] |= 0x80;
        Vec3f zg(c[1], c[1], c[1]);
        grav->reset(0, &Vec2f(c[1], speed.m_y), &zg, a);
        *(float*)((char*)grav + 0x10) = -fn_27_192278(a, 0xfa0);
        *(float*)((char*)grav + 0x1c) = fn_27_192278(a, 0xfa1);
        *(float*)((char*)grav + 0x14) = fn_27_192278(a, 0xfa1);
        ((unsigned char*)grav)[5] |= 0x80;
    }

    Work* work = a->modules->work;
    work->setInt(a->modules->situation->get(), 0x20000008);

    int kind = a->task->kind();
    int joint = 4;
    if (kind == 5) {
        joint = 0x197;
    }

    Vec3f rotation = a->modules->model->getRotation(joint);
    if (c[3] == a->modules->posture->getLr()) {
        rotation.m_y = c[4];
    } else {
        rotation.m_y = c[1];
    }
    a->modules->model->setRotation(joint, &rotation);

    fn_27_89DAC(2, a);
    fn_27_89DAC(0, a);
    a->modules->ground->call(9, 0, 1, -1);

    if (a->task->kind() == 5) {
        a->modules->sound->play(0x1b17, 1, 0);
    } else {
        a->modules->sound->play(0x17a0, 1, 0);
    }
}
