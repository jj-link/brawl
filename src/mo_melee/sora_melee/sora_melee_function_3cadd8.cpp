#include <math.h>
#include <so/so_value_accesser.h>
#include <nw4r/math/math_arithmetic.h>

#pragma force_active on
#pragma fp_contract off

struct Vec2 {
    float x, y;
};

struct Vec3 {
    float x, y, z;
};

struct InitializeFlags {
    unsigned char first : 1;
    unsigned char second : 1;
    unsigned char third : 1;
    unsigned char fourth : 1;
    unsigned char fifth : 1;
    unsigned char sixth : 1;
    unsigned char seventh : 1;
    unsigned char eighth : 1;
    unsigned char ninth : 1;
    unsigned char tenth : 1;
    unsigned char remaining : 6;
};

struct Initialize {
    int resource;
    int team;
    int teamOwner;
    int teamAnother;
    int index;
    int owner;
    int reserved0;
    int reserved1;
    Vec3 position;
    float facing;
    int parameter;
    int variant;
    int situation;
    int status;
    int reserved2;
    int motion;
    int reserved3;
    InitializeFlags flags;
};

struct StatusParam {
    int situation;
    float startFrame;
    float rate;
    unsigned char flags[4];
};

struct Accesser;

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int, int);
    virtual void* slot6(int);
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual int slot11(int, int, Vec3*, Vec3*, int, int, int, float, int);
    virtual float slot12(int);
    virtual void slot13(int, float);
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
    virtual void slot30(StatusParam*);
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34(int, Accesser*);
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41(Vec2*);
};

class VectorModule {
public:
    virtual void slot0();
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
    virtual unsigned long long slot13(short*);
};

struct GroundBase {
    char pad[8];
};

class GroundModule : public GroundBase {
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
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103(float, int);
    virtual void slot104();
    virtual void slot105(int, int, int);
};

struct Object_vptr_3c_base {
    char pad[0x3c];
};

class Object_vptr_3c : public Object_vptr_3c_base {
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
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
};

struct Modules {
    char pad0[8];
    Object_vptr_0* status;
    char pad1[4];
    GroundModule* ground;
    char pad2[8];
    Object_vptr_0* posture;
    char pad3[0x44];
    Object_vptr_0* work;
    char pad4[8];
    Object_vptr_0* other;
    char pad5[8];
    VectorModule* kinetic;
    char pad6[8];
    Object_vptr_0* motion;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

struct Object : Object_vptr_3c {
    char pad40[0x20];
    Accesser* accesser;
    char pad64[0x20d8];
    int* variant;
};

extern "C" {
    extern char lbl_27_data_457C0[];
    extern char lbl_27_data_CDF8[];
    extern const float lbl_27_rodata_80D8[];

    void fn_27_1D8370(void*, const Initialize*);
    void* __dynamic_cast(void*, long, const void*, const void*, long);
    float rsqrtf__Ff(float);
}

extern "C" void fn_27_3CADD8(
    Object* object, int resource, int unused, int parameter,
    const Vec3* position, int special, int motion,
    float facing, float power, float angle)
{
    const float* c = lbl_27_rodata_80D8;
    int variant = *object->variant;
    Initialize initialize;
    initialize.resource = resource;
    initialize.team = 0xffff;
    initialize.teamOwner = 0xffff;
    initialize.teamAnother = 0xffff;
    initialize.index = -1;
    initialize.owner = -1;
    initialize.reserved0 = 0;
    initialize.reserved1 = 0;
    __memcpy(&initialize.position, position, sizeof(Vec3));
    initialize.facing = -facing;
    initialize.parameter = parameter;
    initialize.variant = variant;
    initialize.situation = 2;
    initialize.status = 0x80;
    initialize.reserved2 = 0;
    initialize.motion = 0x35f;
    initialize.reserved3 = 0;
    initialize.flags.first = 1;
    initialize.flags.second = 0;
    initialize.flags.third = 0;
    initialize.flags.fourth = 0;
    initialize.flags.fifth = 1;
    initialize.flags.sixth = 0;
    initialize.flags.seventh = 0;
    initialize.flags.eighth = 0;
    initialize.flags.ninth = 0;
    initialize.flags.tenth = 0;

    fn_27_1D8370(object, &initialize);

    object->accesser->modules->work->slot13(0x11000001, c[6]);
    object->accesser->modules->other->slot34(0, object->accesser);

    Vec3 translation;
    Vec3 rotation;
    rotation.x = c[3];
    rotation.y = c[3];
    rotation.z = c[3];
    translation.x = c[3];
    translation.y = c[3];
    translation.z = c[3];
    int result = object->accesser->modules->motion->slot11(
        motion, 0, &translation, &rotation, 0, 0, 0, c[4], -1);
    object->accesser->modules->work->slot5(result, 0x10000005);

    void* energy = object->accesser->modules->kinetic->slot6(0);
    char* castEnergy = static_cast<char*>(
        __dynamic_cast(energy, 0, lbl_27_data_457C0, lbl_27_data_CDF8, 1));

    float vy = power * (float)sin(angle);
    float vx = facing * (power * (float)cos(angle));
    Vec2 velocity = { vx, vy };
    *reinterpret_cast<Vec2*>(castEnergy + 8) = velocity;
    object->accesser->modules->posture->slot41(&velocity);
    object->accesser->modules->work->slot13(0x11000001, c[3]);

    if (special == 0) {
        if (c[4] == facing) {
            object->accesser->modules->ground->slot103(c[7], 0);
            object->accesser->modules->ground->slot105(4, 1, 0);
        } else {
            object->accesser->modules->ground->slot103(c[8], 0);
            object->accesser->modules->ground->slot105(3, 1, 0);
        }

        StatusParam status;
        status.situation = 0;
        status.startFrame = c[3];
        status.rate = c[4];
        status.flags[0] = 0;
        status.flags[1] = 0;
        status.flags[2] = 0;
        status.flags[3] = 0;
        object->accesser->modules->status->slot30(&status);
    } else {
        object->accesser->modules->ground->slot105(4, 1, 0);
        object->accesser->modules->ground->slot105(3, 1, 0);

        StatusParam status;
        status.situation = 1;
        status.startFrame = c[3];
        status.rate = c[4];
        status.flags[0] = 0;
        status.flags[1] = 0;
        status.flags[2] = 0;
        status.flags[3] = 0;
        object->accesser->modules->status->slot30(&status);
    }

    short flag = 1;
    unsigned long long bits =
        object->accesser->modules->kinetic->slot13(&flag);
    Vec2 vector = *reinterpret_cast<Vec2*>(&bits);
    float maximum;
    float sum = vector.x * vector.x + vector.y * vector.y;
    float magnitude;
    if ((float)(double)nw4r::math::FAbs(sum) <= c[9]) {
        magnitude = c[3];
    } else {
        magnitude = sum * rsqrtf__Ff(sum);
    }

    maximum = soValueAccesser::getConstantFloat(
        reinterpret_cast<soModuleAccesser*>(object->accesser), 0xfa0, 0);
    float current = object->accesser->modules->work->slot12(0x11000001);
    float divisor = soValueAccesser::getConstantFloat(
        reinterpret_cast<soModuleAccesser*>(object->accesser), 0xfa1, 0);
    float value = current + magnitude / divisor;
    if (value > maximum) {
        value = maximum;
    }
    if (value < c[10]) {
        value = c[6];
    }
    object->accesser->modules->work->slot13(0x11000001, value);
    object->slot43();
}
