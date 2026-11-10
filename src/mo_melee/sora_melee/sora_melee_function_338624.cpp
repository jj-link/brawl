#include <types.h>
#pragma force_active on

struct Flags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};

struct IntVec3 {
    int x, y, z;
};

struct Param {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    IntVec3 position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    Flags flags;
};

class Object {
public:
    char pad[0x3c];
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
    virtual void slot43();
    char pad2[0x1c];
    void* unk60;
};

class Module {
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
    virtual void slot30(void*, float);
};

struct Data {
    int x;
    float y;
    float z;
    char pad[4];
};

extern "C" {
extern const float lbl_27_rodata_76C8;
extern const float lbl_27_rodata_76CC;
void fn_27_1D8370(void*, const Param*);

void fn_27_338624(Object* object, int resource, int parameter, const IntVec3* position, float facing) {
    Param p;
    p.resource = resource;
    p.team = 0xFFFF;
    p.teamOwner = 0xFFFF;
    p.teamAnother = 0xFFFF;
    p.index = -1;
    p.owner = -1;
    p.reserved0 = 0;
    p.reserved1 = 0;
    p.position = *position;
    p.facing = facing;
    p.parameter = parameter;
    p.variant = 0;
    p.situation = 2;
    p.status = 0x80;
    p.reserved2 = 0;
    p.motion = 0x35f;
    p.reserved3 = 0;
    p.flags.first = 1;
    p.flags.second = 0;
    p.flags.third = 0;
    p.flags.fourth = 0;
    p.flags.fifth = 1;
    p.flags.sixth = 0;
    p.flags.seventh = 0;
    p.flags.eighth = 0;
    p.flags.ninth = 0;
    p.flags.tenth = 0;

    fn_27_1D8370(object, &p);
    object->slot43();

    Data data;
    data.x = 0;
    data.y = lbl_27_rodata_76CC;
    data.z = lbl_27_rodata_76C8;
    data.pad[0] = 0;
    data.pad[1] = 0;
    data.pad[2] = 0;
    data.pad[3] = 0;

    Module* module = *(Module**)(*(char**)(*(char**)((char*)object + 0x60) + 0xd8) + 8);
    module->slot30(&data, lbl_27_rodata_76CC);
}
}
