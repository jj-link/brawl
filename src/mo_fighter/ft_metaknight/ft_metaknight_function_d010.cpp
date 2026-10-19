#pragma force_active on
struct Vec3 {
    float x, y, z;
};

class HitView {
public:
    virtual void slot8() = 0;
    virtual void slotc() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1c() = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual void slot28() = 0;
    virtual void slot2c() = 0;
    virtual void slot30() = 0;
    virtual void slot34() = 0;
    virtual void slot38() = 0;
    virtual void slot3c() = 0;
    virtual void slot40() = 0;
    virtual void slot44() = 0;
    virtual void slot48() = 0;
    virtual void slot4c() = 0;
    virtual void slot50() = 0;
    virtual void slot54() = 0;
    virtual int test58(int) = 0;
    virtual void slot5c() = 0;
    virtual void slot60() = 0;
    virtual void slot64() = 0;
    virtual void slot68() = 0;
    virtual void slot6c() = 0;
    virtual void slot70() = 0;
    virtual void slot74() = 0;
    virtual void slot78() = 0;
    virtual void slot7c() = 0;
    virtual void slot80() = 0;
    virtual void slot84() = 0;
    virtual int test88(int) = 0;
    virtual void slot8c() = 0;
    virtual void slot90() = 0;
    virtual void slot94() = 0;
    virtual void slot98() = 0;
    virtual void slot9c() = 0;
    virtual void slota0() = 0;
    virtual void slota4() = 0;
    virtual void slota8() = 0;
    virtual void slotac() = 0;
    virtual void slotb0() = 0;
    virtual void slotb4() = 0;
    virtual void slotb8() = 0;
    virtual int count() = 0;
};

class PositionView {
public:
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual Vec3 position() = 0;
};

class ActionView {
public:
    virtual void slot8() = 0;
    virtual void slotc() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1c() = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual void slot28() = 0;
    virtual void slot2c() = 0;
    virtual void action(int, const Vec3&, unsigned int, int, int) = 0;
};

class EffectView {
public:
    virtual void slot8() = 0;
    virtual void slotc() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1c() = 0;
    virtual void effect(int, const Vec3&, const Vec3&, float, int, int) = 0;
};

struct Modules {
    char pad0[0xC];
    PositionView* position;
    char pad10[0xC];
    ActionView* action;
    char pad20[0x68];
    EffectView* effect;
};

struct Accesser {
    char pad[0xD8];
    Modules* modules;
};

struct Object {
    char pad[0x28];
    unsigned int id;
};

extern "C" {
extern const float lbl_111_rodata_30[];
HitView* fn_27_8CD54(void*);
int fn_27_14D680(void*, int);
Vec3 fn_27_8CA78(void*);
float randf__Fv();

void fn_111_D010(Object* object, int arg, Accesser* accesser) {
    ActionView* action;
    const float* constants = lbl_111_rodata_30;
    HitView* hit = fn_27_8CD54(object);
    unsigned int clear = 1;
    int count = hit->count();

    for (int i = 0; i < count; ++i) {
        if (hit->test58(0) != 0 || hit->test88(0) != 0) {
            clear = 0;
            break;
        }
    }

    if (clear == 1) {
        int value = fn_27_14D680(object, 1);
        action = accesser->modules->action;
        action->action(arg, accesser->modules->position->position(),
                       object->id, 0, value);
    }

    const Vec3& position = fn_27_8CA78(object);
    float angle = constants[1] * randf__Fv();
    Vec3 rotation = { constants[2], constants[2], angle };
    accesser->modules->effect->effect(
        5, position, rotation, constants[0], 0, -1);
}
}
