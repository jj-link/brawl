#include <so/stageobject.h>
#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on

struct CaptainFlags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};

struct CaptainInitialize {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3f position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    CaptainFlags flags;
};

class Object_vptr_0 {
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
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20(int, int);
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
    virtual void slot34(int, void*);
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
    virtual void slot43(float);
};

extern "C" {
extern char lbl_27_data_457C0[], lbl_27_data_CDF8[];
extern const float lbl_27_rodata_7B94;
void fn_27_1D8370(void*, const CaptainInitialize*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" void fn_27_371BEC(Object_vptr_3c* object, int resource, int parameter,
    const Vec3f* position, int unused, int special, float facing, float power)
{
    CaptainInitialize init;
    init.resource = resource;
    init.team = 0xffff;
    init.teamOwner = 0xffff;
    init.teamAnother = 0xffff;
    init.index = -1;
    init.owner = -1;
    init.reserved0 = 0;
    init.reserved1 = 0;
    __memcpy(&init.position, position, sizeof(Vec3f));
    init.facing = facing;
    init.parameter = parameter;
    init.variant = 0;
    init.situation = 5;
    init.status = 0x80;
    init.reserved2 = 0;
    init.motion = 0x35f;
    init.reserved3 = 0;
    init.flags.first = 1;
    init.flags.second = 0;
    init.flags.third = 0;
    init.flags.fourth = 0;
    init.flags.fifth = 1;
    init.flags.sixth = 0;
    init.flags.seventh = 0;
    init.flags.eighth = 0;
    init.flags.ninth = 0;
    init.flags.tenth = 0;

    fn_27_1D8370(object, &init);

    Object_vptr_0* a = *(Object_vptr_0**)(*(char**)(*(char**)((char*)object + 0x60) + 0xd8) + 0x64);
    a->slot20(special, 0x12000003);

    void* acc = *(void**)((char*)object + 0x60);
    Object_vptr_0* b = *(Object_vptr_0**)(*(char**)((char*)acc + 0xd8) + 0x70);
    b->slot34(0, acc);

    Object_vptr_0* c = *(Object_vptr_0**)(*(char**)(*(char**)((char*)object + 0x60) + 0xd8) + 0x7c);
    void* energy = c->slot6(0);
    char* e = (char*)__dynamic_cast(energy, 0, lbl_27_data_457C0, lbl_27_data_CDF8, 1);

    float v[2];
    v[0] = lbl_27_rodata_7B94;
    v[1] = power;
    *(float*)(e + 0x8) = v[0];
    *(float*)(e + 0xc) = (float)(double)power;

    object->slot43(v[0]);
}
