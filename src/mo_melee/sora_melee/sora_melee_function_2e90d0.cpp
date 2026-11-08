#include <mt/mt_vector.h>
#pragma force_active on
struct Flags {
 unsigned char first:1, second:1, third:1, fourth:1, fifth:1, sixth:1, seventh:1, eighth:1;
 unsigned char ninth:1, tenth:1, reserved:6;
};
struct Param {
 int resource, team, teamOwner, teamAnother, index, owner, reserved0, reserved1;
 Vec3f position;
 float facing;
 int parameter, variant, situation, status, reserved2, motion, reserved3;
 Flags flags;
};
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
 virtual void slot5(int, Vec2f*, Vec3f*, void*);
 virtual void* slot6(int);
 virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16();
 virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21();
 virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25(); virtual void slot26();
 virtual void slot27(); virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
 virtual void slot32(); virtual void slot33(); virtual void slot34(int, void*);
};
struct Energy { Object_vptr_0* vtable; char pad; unsigned char flags; char pad2[2]; float value; };
struct Modules { char pad[0x70]; Object_vptr_0* a; char pad2[8]; Object_vptr_0* energy; };
struct Sub { char pad[0xd8]; Modules* modules; };
struct Params { char pad[0x18]; float value; };
struct Object { char pad[0x60]; Sub* sub; char pad2[0x1a80-0x64]; Params* params; };
extern "C" {
 extern const float lbl_27_rodata_642C;
 extern char lbl_27_data_457C0[], lbl_27_data_45940[], lbl_27_data_CDF8[];
 void fn_27_1D8370(void*, const Param*);
 void* __dynamic_cast(void*, long, const void*, const void*, long);
}
extern "C" void fn_27_2E90D0(Object* object, int resource, int team, int parameter) {
 Vec3f position;
 position.m_x = lbl_27_rodata_642C;
 position.m_y = lbl_27_rodata_642C;
 position.m_z = lbl_27_rodata_642C;
 Param initialize;
 initialize.resource = resource;
 initialize.team = team;
 initialize.teamOwner = team;
 initialize.teamAnother = team;
 initialize.index = -1;
 initialize.owner = -1;
 initialize.reserved0 = 0;
 initialize.reserved1 = 0;
 __memcpy(&initialize.position, &position, sizeof(Vec3f));
 initialize.facing = lbl_27_rodata_642C;
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
 object->sub->modules->a->slot34(0, object->sub);
 Energy* energy = (Energy*)__dynamic_cast(object->sub->modules->energy->slot6(0), 0, lbl_27_data_457C0, lbl_27_data_CDF8, 1);
 Sub* sub = object->sub;
 Vec3f vec3;
 vec3.m_x = lbl_27_rodata_642C;
 vec3.m_y = lbl_27_rodata_642C;
 vec3.m_z = lbl_27_rodata_642C;
 Vec2f vec2;
 vec2.m_x = lbl_27_rodata_642C;
 vec2.m_y = lbl_27_rodata_642C;
 ((Object_vptr_0*)energy)->slot5(0, &vec2, &vec3, sub);
 energy->flags |= 0x80;
 Energy* energy2 = (Energy*)__dynamic_cast(object->sub->modules->energy->slot6(2), 0, lbl_27_data_45940, lbl_27_data_CDF8, 1);
 energy2->value = object->params->value;
 energy2->flags |= 0x80;
}