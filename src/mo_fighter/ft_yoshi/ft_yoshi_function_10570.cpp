#include <string.h>
#pragma force_active on

struct Vec2f {
    float x, y;

    static void copy(Vec2f& dst, const Vec2f& src) {
        __memcpy(&dst, &src, sizeof(Vec2f));
    }
};

struct Vec3f {
    float x, y, z;
};

struct GroundBase {
    unsigned char pad[8];
};

struct Ground : GroundBase {
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
    virtual void slot55();
    virtual void slot56();
    virtual Vec2f getTouchNormal(int, int);
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual Vec2f getTouchPos(int, int);
};

struct Effect {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual unsigned int req(int, Vec3f*, Vec3f*, float, unsigned int, int);
};

struct Modules {
    unsigned char pad0[0x10];
    Ground* ground;
    unsigned char pad14[0x74];
    Effect* effect;
};

struct Accesser {
    unsigned char pad[0xD8];
    Modules* modules;
};

extern "C" {
double atan2(double, double);
extern const float lbl_95_rodata_68;
extern const float lbl_95_rodata_6C;
Vec3f* fn_95_ABB4(Vec3f*, float, float, float);
}

inline float angle2(float x, float y) {
    return atan2(x, y);
}

extern "C" void fn_95_10570(Accesser* accesser, int mask) {
    Vec2f normal;
    Ground* ground = accesser->modules->ground;
    Vec2f::copy(normal, ground->getTouchNormal(mask, 0));

    Vec2f pos;
    ground = accesser->modules->ground;
    Vec2f::copy(pos, ground->getTouchPos(mask, 0));

    float angle = angle2(-normal.x, normal.y);
    Vec3f position, rotation;
    Effect* effect = accesser->modules->effect;
    effect->req(
        9,
        fn_95_ABB4(&position, pos.x, pos.y, lbl_95_rodata_6C),
        fn_95_ABB4(&rotation, lbl_95_rodata_6C, lbl_95_rodata_6C, angle),
        lbl_95_rodata_68, 0, -1);
}
