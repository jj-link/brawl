#include <so/so_module_accesser.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(unsigned int, float); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(unsigned int);
};
struct Flags {
    unsigned char first:1, second:1, third:1, fourth:1;
    unsigned char fifth:1, sixth:1, seventh:1, eighth:1;
    unsigned char ninth:1, tenth:1, reserved:6;
};
struct Initialize {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3f position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    Flags flags;
};
struct Modules { char pad[0x64]; Object_vptr_0* work; };
struct Inner { char pad[0xd8]; Modules* modules; };
struct Object { char pad[0x60]; Inner* inner; };
extern "C" {
extern const float lbl_27_rodata_64D0;
void fn_27_1D8370(void*, const Initialize*);
}
extern "C" void fn_27_2F36CC(Object* object, int resource, int unused, int parameter, float value) {
    Vec3f position;
    position.m_x = lbl_27_rodata_64D0;
    position.m_y = lbl_27_rodata_64D0;
    position.m_z = lbl_27_rodata_64D0;
    Initialize initialize;
    initialize.resource = resource;
    initialize.team = 0xffff;
    initialize.teamOwner = 0xffff;
    initialize.teamAnother = 0xffff;
    initialize.index = -1;
    initialize.owner = -1;
    initialize.reserved0 = 0;
    initialize.reserved1 = 0;
    __memcpy(&initialize.position, &position, sizeof(Vec3f));
    initialize.facing = lbl_27_rodata_64D0;
    initialize.parameter = parameter;
    initialize.variant = 0;
    initialize.situation = 2;
    initialize.status = 0x80;
    initialize.reserved2 = 0;
    initialize.motion = 0x35f;
    initialize.reserved3 = 0;
    initialize.flags.first = 1;
    initialize.flags.second = 1;
    initialize.flags.third = 0;
    initialize.flags.fourth = 0;
    initialize.flags.fifth = 1;
    initialize.flags.sixth = 0;
    initialize.flags.seventh = 0;
    initialize.flags.eighth = 0;
    initialize.flags.ninth = 0;
    initialize.flags.tenth = 0;
    fn_27_1D8370(object, &initialize);
    Object_vptr_0* work = object->inner->modules->work;
    work->slot13(0x11000001, value);
    work->slot18(0x12000000);
}