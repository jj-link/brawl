#include <so/so_external_value_accesser.h>
#pragma force_active on

struct RawVec { int x, y, z; };
struct Event {
    int kind;
    unsigned char flag;
    Vec3f pos;
    Event(int k, const Vec3f& p) : kind(k), flag(0), pos(p) {}
};
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(int);
    virtual int slot4(int);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual unsigned int slot9(int);
    virtual void slot10();
    virtual StageObject* slot11(int);
    virtual float slot12(int);
    virtual void slot13();
    virtual void slot14();
    virtual void slot15(int, Event*);
    virtual void slot16();
    virtual unsigned int slot17(int);
};
struct BoneBase { char pad[8]; };
class Bone : public BoneBase {
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
    virtual Vec3f position(int, int);
};
struct Modules {
    char pad0[4];
    Bone* bone;
    char pad1[0x54-8];
    Object_vptr_0* link;
    char pad2[0x64-0x58];
    Object_vptr_0* work;
    char pad3[0x70-0x68];
    Object_vptr_0* status;
};
struct Actor { char pad[0xd8]; Modules* modules; };
struct Self { char pad[0x10c]; int entry; char pad2[0x7fac-0x110]; };
extern "C" void* g_ftManager;
extern "C" float lbl_27_rodata_7C14;
extern "C" void fn_27_10C134(void*, int, Vec3f*, int, float);
extern "C" Vec3f fn_27_388A44(void*, Actor*);
extern "C" void fn_27_1324D4(Self*, Event*, Actor*, StageObject*, int);

extern "C" void fn_27_382020(Self* self, Event* event, Actor* actor, StageObject* object, int value) {
    switch (event->kind) {
    case 0x455: {
        Vec3f pos = soExternalValueAccesser::getPos(object);
        pos.m_z = lbl_27_rodata_7C14;
        int a;
        int entry;
        void* manager;
        Object_vptr_0* work;
        manager = g_ftManager;
        entry = self->entry;
        work = actor->modules->work;
        a = work->slot4(0x10000040);
        fn_27_10C134(manager, entry, &pos, a, work->slot12(0x11000015));
        break;
    }
    case 0x456:
        if (actor->modules->work->slot17(0x1200003f) == 1U) {
            event->pos = fn_27_388A44((char*)self + 0x7fac, actor);
        } else {
            event->pos = actor->modules->bone->position(0x27, 0);
        }
        break;
    case 0x457:
        if (actor->modules->work->slot17(0x1200003f) == 1U) {
            event->pos = fn_27_388A44((char*)self + 0x7fac, actor);
        } else {
            event->pos = actor->modules->bone->position(0x17, 0);
        }
        break;
    case 0x458: {
        Event e(0x455, event->pos);
        actor->modules->link->slot15(6, &e);
        break;
    }
    case 0x459:
        if (actor->modules->link->slot9(6) == 1U) {
            event->pos = soExternalValueAccesser::getPos(actor->modules->link->slot11(6));
            event->flag = 1;
        }
        break;
    case 0x45a:
        actor->modules->status->slot3(0x116);
        break;
    }
    fn_27_1324D4(self, event, actor, object, value);
}