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
    virtual void slot9();
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
};

struct Actor {
    char pad[0xd8];
    Modules* modules;
};

struct Object {
    char pad[0x60];
    Actor* actor;
};

extern "C" void fn_27_340E54(Object* object) {
    Vec scale;
    scale.x = scale.y = scale.z = object->actor->modules->posture->slot22();
    Vec position;
    Vec rotation;
    rotation = object->actor->modules->posture->slot4();
    position = object->actor->modules->posture->slot14(0);
    position.y += object->actor->modules->posture->slot18();
    object->actor->modules->model->slot22(0, &scale, &position, &rotation);
}
