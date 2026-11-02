#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <math.h>
#pragma force_active on

struct LaunchFlags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};

struct LaunchInitialize {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3f position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    LaunchFlags flags;
};

struct PokeRange {
    int variant;
    int reserved;
    float min;
    float max;
};

class PokeModule {
public:
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7(int, void*, void*, void*);
    virtual void* s8(int);
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15(float, int);
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
    virtual void s36(int, void*);
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43(void*);
    virtual void s44();
    virtual void s45();
};

struct PokeModuleTable {
    unsigned char pad0[0x1C];
    PokeModule* m1c;
    unsigned char pad1[0x64 - 0x20];
    PokeModule* m64;
    unsigned char pad2[0x70 - 0x68];
    PokeModule* m70;
    unsigned char pad3[0x7C - 0x74];
    PokeModule* m7c;
};

struct PokeAccesserTable {
    unsigned char pad0[0xD8];
    PokeModuleTable* table;
};

struct PokeBase {
    unsigned char pad0[0x3C];
};

class PokeObject : public PokeBase {
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
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    unsigned char pad1[0x60 - 0x40];
    soModuleAccesser* accesser;
    unsigned char pad2[0x16B4 - 0x64];
    PokeRange* range;
};

float randf();

extern "C" {
extern const float lbl_116_rodata_A8;
extern const float lbl_116_rodata_B0;
extern const char lbl_116_data_7710[], lbl_116_data_2260[];
void fn_27_1D8370(void*, const LaunchInitialize*);
void fn_116_13834(Vec2f*, float, float);
void* fn_116_971C(void*, float, float, float);
void fn_116_CB3C(Vec2f*, const Vec2f*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" void fn_116_2324C(PokeObject* object, int resource, int team, int parameter,
    const Vec3f* position, float facing, float scale, float angle)
{
    int variant = object->range->variant;
    LaunchInitialize initialize;
    initialize.resource = resource;
    initialize.team = team;
    initialize.teamOwner = team;
    initialize.teamAnother = team;
    initialize.index = -1;
    initialize.owner = -1;
    initialize.reserved0 = 0;
    initialize.reserved1 = 0;
    __memcpy(&initialize.position, position, sizeof(Vec3f));
    initialize.facing = facing;
    initialize.parameter = parameter;
    initialize.variant = variant;
    initialize.situation = 5;
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

    ((PokeAccesserTable*)object->accesser)->table->m70->s36(0, object->accesser);

    float sinValue = (float)sin(lbl_116_rodata_B0 * angle);
    float cosValue = (float)cos(lbl_116_rodata_B0 * angle);
    Vec2f pos;
    fn_116_13834(&pos, facing * (scale * cosValue), scale * sinValue);

    float value = soValueAccesser::getConstantFloat(object->accesser, 0xFA0, 0);

    PokeModule* r29 = (PokeModule*)__dynamic_cast(
        ((PokeAccesserTable*)object->accesser)->table->m7c->s8(0),
        0, lbl_116_data_7710, lbl_116_data_2260, 1);

    Vec3f vec;
    r29->s7(1, &pos,
        fn_116_971C(&vec, lbl_116_rodata_A8, lbl_116_rodata_A8, lbl_116_rodata_A8),
        object->accesser);

    Vec2f spot;
    spot.m_x = value;
    spot.m_y = lbl_116_rodata_A8;
    fn_116_CB3C(reinterpret_cast<Vec2f*>((unsigned char*)r29 + 0x20), &spot);
    *((unsigned char*)r29 + 5) |= 0x80;

    ((PokeAccesserTable*)object->accesser)->table->m1c->s43(&pos);

    float lerp = object->range->min + (object->range->max - object->range->min) * randf();
    ((PokeAccesserTable*)object->accesser)->table->m64->s15(lerp, 0x11000002);
    ((PokeAccesserTable*)object->accesser)->table->m64->s15(angle, 0x11000003);
    ((PokeAccesserTable*)object->accesser)->table->m64->s15(angle, 0x11000004);

    object->v43();
}
