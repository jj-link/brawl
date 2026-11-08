#include <so/stageobject.h>
#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on
struct Flags {
 unsigned char first:1, second:1, third:1, fourth:1, fifth:1, sixth:1, seventh:1, eighth:1;
 unsigned char ninth:1, tenth:1, reserved:6;
};
struct Init {
 int resource, team, teamOwner, teamAnother, index, owner, reserved0, reserved1;
 Vec3f position;
 float facing;
 int parameter, variant, situation, status, reserved2, motion, reserved3;
 Flags flags;
};
struct Params { float x,y,unused,power,angle; int variant; };
extern "C" {
extern char lbl_27_data_457C0[], lbl_27_data_CDF8[];
extern const float lbl_27_rodata_6374, lbl_27_rodata_6380;
void fn_27_1D8370(void*, const Init*);
void* __dynamic_cast(void*, long, const void*, const void*, long);
double sin(double);
double cos(double);
}
extern "C" void fn_27_2DD698(StageObject* object, int resource, int team, int parameter, const Vec3f* position, int arg, float facing) {
 int variant=(*reinterpret_cast<Params**>(reinterpret_cast<char*>(object)+0x1f40))->variant;
 Init init;
 init.resource=resource;
 init.team=team; init.teamOwner=team; init.teamAnother=team;
 init.index=-1; init.owner=-1; init.reserved0=0; init.reserved1=0;
 __memcpy(&init.position, position, sizeof(Vec3f));
 init.facing=facing; init.parameter=parameter;
 init.variant=variant;
 init.reserved2=0; init.motion=0x35f; init.reserved3=0;
 init.flags.first=1; init.flags.second=0; init.flags.third=0; init.flags.fourth=0; init.flags.fifth=1;
 init.flags.sixth=0; init.flags.seventh=0; init.flags.eighth=0; init.flags.ninth=0; init.flags.tenth=0;
 init.situation=3; init.status=255;
 fn_27_1D8370(object,&init);
 object->m_moduleAccesser->getStatusModule().changeStatusForce(arg, object->m_moduleAccesser);
 soKineticEnergy* kinetic=object->m_moduleAccesser->getKineticModule().getEnergy(0);
 char* energy=static_cast<char*>(__dynamic_cast(kinetic,0,lbl_27_data_457C0,lbl_27_data_CDF8,1));
 Params* p=*reinterpret_cast<Params**>(reinterpret_cast<char*>(object)+0x1f40);
 float angle=p->angle, power=p->power;
 float vy=power*(float)sin(angle);
 float vx=facing*(power*(float)cos(angle));
 Vec2f velocity(vx,vy);
 *reinterpret_cast<Vec2f*>(energy+8)=velocity;
 Vec2f limit(lbl_27_rodata_6380,(*reinterpret_cast<Params**>(reinterpret_cast<char*>(object)+0x1f40))->y);
 *reinterpret_cast<Vec2f*>(energy+0x18)=limit;
 Vec2f accel(lbl_27_rodata_6374,-(*reinterpret_cast<Params**>(reinterpret_cast<char*>(object)+0x1f40))->x);
 *reinterpret_cast<Vec2f*>(energy+0x10)=accel;
}