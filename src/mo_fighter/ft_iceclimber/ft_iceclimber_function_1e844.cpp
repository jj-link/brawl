#include <mo_fighter/ft_mario/ft_mario_initialize_types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(int, void*);
    virtual void slot4(void*, int, int, int, int, int, int, int);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual Object_vptr_0* slot13();
};

class ObjSingle {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(int);
};

struct VptrPrefix { unsigned char pad[8]; };
class ObjFirst : public VptrPrefix {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Object_vptr_0* slot4();
};

class ObjFlag {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(int, int);
};

class Physics : public VptrPrefix {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(Object_vptr_0*, int, int, int, int, int, bool, int);
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
    virtual void slot22(int);
};

struct Ob_D8 {
    ObjFirst* p0;
    unsigned char pad0[0x54 - 4];
    ObjFlag* p54;
    unsigned char pad1[0x70 - 0x58];
    Object_vptr_0* p70;
    unsigned char pad2[0x9C - 0x74];
    Physics* p9C;
};

struct Ob_60 {
    unsigned char pad[0xD8];
    Ob_D8* pD8;
};

struct Ob_arg0 {
    unsigned char pad[0x60];
    Ob_60* p60;
};

inline ObjFirst& resourceModule(Ob_D8* modules) { return *modules->p0; }
inline Physics& physicsModule(Ob_D8* modules) { return *modules->p9C; }

extern "C" {
extern f32 lbl_105_rodata_118;
extern s32 lbl_105_data_99D8;
void fn_105_C1C0(Vec3f*, f32, f32, f32);
void fn_27_1D8370(void*, const MarioMantleInitializeParam*);

void fn_105_1E844(void* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Vec3f position;
    fn_105_C1C0(&position, lbl_105_rodata_118, lbl_105_rodata_118, lbl_105_rodata_118);

    MarioMantleInitializeParam p;
    p.resource = arg1;
    p.team = arg2;
    p.teamOwner = arg2;
    p.teamAnother = arg2;
    p.index = -1;
    p.owner = -1;
    p.reserved0 = 0;
    p.reserved1 = 0;
    __memcpy(&p.position, &position, sizeof(position));
    p.facing = lbl_105_rodata_118;
    p.parameter = arg3;
    p.reserved2 = 0;
    p.situation = 2;
    p.status = 0x80;
    p.reserved3 = 0;
    p.motion = 0x35f;
    p.reserved4 = 0;
    p.flags.first = 1;
    p.flags.second = 1;
    p.flags.third = 0;
    p.flags.fourth = 0;
    p.flags.fifth = 1;
    p.flags.sixth = 0;
    p.flags.seventh = 0;
    p.flags.eighth = 0;
    p.flags.ninth = 0;
    p.flags.tenth = 0;
    fn_27_1D8370(arg0, &p);

    Ob_arg0* obj = (Ob_arg0*)arg0;
    Ob_D8* d8 = obj->p60->pD8;
    ObjFirst& resource = resourceModule(d8);
    Physics& physics = physicsModule(d8);
    s32 value = lbl_105_data_99D8;
    Object_vptr_0* first = resource.slot4();
    Object_vptr_0* result = first->slot13();
    physics.slot4(result, 0, value, value, value, 0, false, -1);
    obj->p60->pD8->p9C->slot22(2);
    if (obj->p60->pD8->p54->slot4(5, arg4) != 0) {
        obj->p60->pD8->p70->slot3(1, obj->p60);
    }
}
}
