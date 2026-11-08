#include <so/so_module_accesser.h>
#pragma force_active on
struct Flags {
 unsigned char first:1, second:1, third:1, fourth:1, fifth:1, sixth:1, seventh:1, eighth:1;
 unsigned char ninth:1, tenth:1, reserved:6;
};
struct Param {
 int resource, team, teamOwner, teamAnother, index, owner;
 int reserved0, reserved1;
 Vec3f position;
 float facing;
 int parameter, variant, situation, status, reserved2, motion, reserved3;
 Flags flags;
};
struct Access;
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
 virtual void slot5(int, unsigned int, Access*);
 virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9();
 virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual void slot17(); virtual void slot18(unsigned int); virtual void slot19();
 virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24();
 virtual void slot25(); virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual void slot29();
 virtual void slot30(); virtual void slot31(); virtual void slot32(); virtual void slot33(); virtual void slot34(int, Access*);
};
struct Modules { char pad[0x64]; Object_vptr_0* work; char pad2[8]; Object_vptr_0* m70; };
struct Access { char pad[0xd8]; Modules* modules; };
struct Object { char pad[0x60]; Access* access; };
extern "C" {
extern const float lbl_27_rodata_64C4;
void fn_27_1D8370(void*, const Param*);
void fn_27_2F1D04(Object* object, int resource, int unused, int parameter) {
 Vec3f position;
 position.m_x = lbl_27_rodata_64C4;
 position.m_y = lbl_27_rodata_64C4;
 position.m_z = lbl_27_rodata_64C4;
 Param p;
 p.resource = resource;
 p.team = 0xffff;
 p.teamOwner = 0xffff;
 p.teamAnother = 0xffff;
 p.index = -1;
 p.owner = -1;
 p.reserved0 = 0;
 p.reserved1 = 0;
 __memcpy(&p.position, &position, sizeof(Vec3f));
 p.facing = lbl_27_rodata_64C4;
 p.parameter = parameter;
 p.variant = 0;
 p.situation = 2;
 p.status = 0x80;
 p.reserved2 = 0;
 p.motion = 0x35f;
 p.reserved3 = 0;
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
 fn_27_1D8370(object, &p);
 object->access->modules->work->slot5(0, 0x10000006, object->access);
 object->access->modules->m70->slot34(0, object->access);
 object->access->modules->work->slot18(0x12000000);
}
}