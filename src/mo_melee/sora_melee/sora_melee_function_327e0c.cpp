#pragma force_active on
struct Vec3 { int x,y,z; };
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
struct Access;
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5(int, int);
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
 virtual void slot34(int, Access*);
};
struct Modules { char pad[0x64]; Object_vptr_0* X; char pad2[8]; Object_vptr_0* Y; };
struct Access { char pad[0xd8]; Modules* modules; };
struct Object { char pad[0x60]; Access* access; char pad2[0x1f54]; int* P; };
extern "C" {
void fn_27_1D8370(void*, const Param*);
void fn_27_327E0C(Object* object, int resource, int team, Vec3 position, int parameter, float facing) {
 Param p;
 p.resource=resource;
 p.team=team;
 p.teamOwner=team;
 p.teamAnother=team;
 p.index=-1;
 p.owner=-1;
 p.reserved0=0;
 p.reserved1=0;
 p.position=position;
 p.facing=facing;
 p.parameter=parameter;
 p.variant=0;
 p.reserved2=0;
 p.motion=0x35f;
 p.reserved3=0;
 p.flags.first=1;
 p.flags.second=0;
 p.flags.third=0;
 p.flags.fourth=0;
 p.flags.fifth=1;
 p.flags.sixth=0;
 p.flags.seventh=0;
 p.flags.eighth=0;
 p.flags.ninth=0;
 p.flags.tenth=0;
 p.situation=3;
 p.status=0xff;
 fn_27_1D8370(object,&p);
 Access* access=object->access;
 Object_vptr_0* module=access->modules->X;
 module->slot5(*object->P,0x10000003);
 module->slot5(*object->P,0x10000004);
 access->modules->Y->slot34(0,access);
}
}