#pragma force_active on
struct Vec3 { float x,y,z; };
struct Flags {
 unsigned char first:1, second:1, third:1, fourth:1, fifth:1, sixth:1, seventh:1, eighth:1;
 unsigned char ninth:1, tenth:1, reserved:6;
};
struct Param {
 int resource, team, teamOwner, teamAnother, index, owner;
 int reserved0, reserved1;
 Vec3 position;
 float facing;
 int parameter, variant, situation, status, reserved2, motion, reserved3;
 Flags flags;
};
class Object_vptr_0 {
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
 virtual void slot13(int, float);
};
struct Modules { char pad[0x64]; Object_vptr_0* m64; };
struct Access { char pad[0xd8]; Modules* modules; };
struct Object { char pad[0x60]; Access* access; };
extern "C" {
extern const float lbl_27_rodata_76BC;
void fn_27_1D8370(void*, const Param*);
void* __memcpy(void*, const void*, unsigned long);
void fn_27_33647C(Object* object, int resource, int team, int parameter, float value) {
 Param p;
 Vec3 position;
 position.x = lbl_27_rodata_76BC;
 position.y = lbl_27_rodata_76BC;
 position.z = lbl_27_rodata_76BC;
 p.resource = resource;
 p.team = team;
 p.teamOwner = team;
 p.teamAnother = team;
 p.index = -1;
 p.owner = -1;
 p.reserved0 = 0;
 p.reserved1 = 0;
 __memcpy(&p.position, &position, sizeof(Vec3));
 p.facing = lbl_27_rodata_76BC;
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
 object->access->modules->m64->slot13(0x11000001, value);
}
}