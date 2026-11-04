#include <sr/sr_common.h>
#include <mt/mt_vector.h>
#pragma force_active on

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3();
    virtual Vec3f slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11(float, float, float);
    virtual void slot12(float, float);
    virtual void slot13(float, float, float);
    virtual Vec3f slot14(short*);
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual float slot22();
    virtual void slot23(float, int, float, float);
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
    virtual void slot55(Vec2f*, int, Vec2f*, float, float);
};

struct Modules {
    char pad[0xC];
    soNullable* posture;
    void* ground;
    soNullable* situation;
    void* team;
    soNullable* attack;
    soNullable* hit;
    soNullable* shield;
    soNullable* reflector;
    soNullable* absorber;
    soNullable* catchModule;
    soNullable* searchModule;
    char pad38[0x44];
    soNullable* kinetic;
};
struct Accesser {
    char pad[0xD8];
    Modules* modules;
};
struct gfTask_base { char pad[0x3C]; };
class gfTask : public gfTask_base {
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
    virtual void processCamera();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void init();
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
    virtual float slot38(Accesser*);
    char pad40[0x20];
    Accesser* accesser;
};

extern "C" {
extern void* lbl_27_bss_F0;
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BEA8(void*);
}

extern "C" void fn_27_581C(gfTask* object) {
    Accesser* accesser = object->accesser;
    if (lbl_27_bss_F0 == 0) {
        void* singleton = operator new(0x4C, Heaps::System);
        if (singleton != 0) {
            singleton = fn_27_5BCD0(singleton);
        }
        lbl_27_bss_F0 = singleton;
    }
    if (fn_27_5BEA8(lbl_27_bss_F0) == 1U) {
        Vec3f pos = accesser->modules->posture->slot4();
        float scale = accesser->modules->posture->slot22();
        int situation = accesser->modules->situation->slot3();
        float adjustment = object->slot38(accesser);
        Vec2f position(pos.m_x, pos.m_y);
        short kind = -1;
        Vec3f speed = accesser->modules->kinetic->slot14(&kind);
        accesser->modules->hit->slot23(pos.m_x, situation, scale, adjustment);
        Vec2f velocity(speed.m_x, speed.m_y);
        accesser->modules->attack->slot55(&position, situation, &velocity, scale, adjustment);
        accesser->modules->shield->slot11(pos.m_x, scale, adjustment);
        accesser->modules->reflector->slot11(pos.m_x, scale, adjustment);
        accesser->modules->absorber->slot11(pos.m_x, scale, adjustment);
        accesser->modules->catchModule->slot13(pos.m_x, scale, adjustment);
        accesser->modules->searchModule->slot12(pos.m_x, scale);
    }
}
