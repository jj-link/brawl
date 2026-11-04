#include <types.h>
#pragma force_active on

struct Vec {
    float x, y, z;
};

struct Posture {
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual Vec slot14(int);
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual float slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual float slot22();
};

struct Other {
    virtual void isNull();
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
    virtual float slot12(int);
};

struct Pad {
    int a, b;
};

struct Model : Pad {
    virtual void isNull();
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
    virtual void slot22(int, Vec*, Vec*, Vec*);
};

struct Modules {
    char pad0[4];
    Model* model;
    char pad8[4];
    Posture* posture;
    char pad10[0x54];
    Other* other;
};

struct Actor {
    char pad[0xd8];
    Modules* modules;
};

struct Object {
    char pad[0x60];
    Actor* actor;
};

extern "C" float lbl_27_rodata_7C14;
extern "C" float lbl_27_rodata_7C28;

extern "C" void fn_27_3816BC(Object* object) {
    Actor* actor = object->actor;
    Vec scale;
    scale.x = scale.y = scale.z = actor->modules->posture->slot22();
    Vec position;
    Vec rotation;
    rotation = actor->modules->posture->slot4();
    position = actor->modules->posture->slot14(0);
    if (lbl_27_rodata_7C14 == actor->modules->posture->slot9()) {
        position.y = position.y + lbl_27_rodata_7C28;
        position.y = position.y + actor->modules->other->slot12(0x11000018);
    } else {
        position.y = position.y + actor->modules->posture->slot18();
    }
    actor->modules->model->slot22(0, &scale, &position, &rotation);
}
