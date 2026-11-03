#include <so/so_value_accesser.h>
#pragma force_active on

class Work {
public:
 virtual void isNull(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual int slot4(int); virtual void slot5(int,int); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual float slot12(int); virtual void slot13(float,int); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual void slot17(); virtual void slot18(int);
};
class Posture {
public:
 virtual void isNull(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23(float);
};
class Effect {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10();
 virtual int slot11(int,int,Vec3f*,Vec3f*,int,int,int,float,int);
};
class Status {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
 virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
 virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
 virtual void slot32(); virtual void slot33(); virtual void slot34(int,void*);
};
struct Holder {
 char pad[0xc]; Posture* posture; char pad2[0x54]; Work* work;
 char pad3[8]; Status* status; char pad4[0x14]; Effect* effect;
};
struct Owner { char pad[8]; void* obj; char pad2[0xcc]; Holder* holder; };
struct Link { char pad[0x60]; Owner* owner; };
struct Data { int max; char pad[0xc]; int divisor; char pad2[4]; float mul, add; };
struct Flags {
 unsigned char first:1,second:1,third:1,fourth:1,fifth:1,sixth:1,seventh:1,eighth:1;
 unsigned char ninth:1,tenth:1,reserved:6;
};
struct Initialize {
 int resource,team,teamOwner,teamAnother,index,owner,reserved0,reserved1;
 Vec3f position; float facing;
 int parameter,variant,situation,status,reserved2,motion,reserved3;
 Flags flags;
};
struct TaskBase { char pad[0x3c]; };
class Task : public TaskBase {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
 virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
 virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
 virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
 virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
 virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual void slot43();
 char pad2[0x20]; Owner* owner;
};
extern "C" {
void fn_27_1D8370(void*, const Initialize*);
void* __dynamic_cast(void*,long,const void*,const void*,short);
Data* fn_27_14954C(void*,int);
extern char g_ftCommonDataAccesser[], lbl_27_data_9B6C0[], lbl_27_data_248[];
extern const float lbl_27_rodata_7E14, lbl_27_rodata_7E18;
void fn_27_39EA1C(Task* self,int resource,int parameter,int power,int kind,float facing,float factor) {
 Vec3f position(lbl_27_rodata_7E14,lbl_27_rodata_7E14,lbl_27_rodata_7E14);
 Initialize init;
 init.resource=resource;
 init.team=0xffff; init.teamOwner=0xffff; init.teamAnother=0xffff;
 init.index=-1; init.owner=-1; init.reserved0=0; init.reserved1=0;
 __memcpy(&init.position, &position, sizeof(Vec3f));
 init.facing=facing; init.parameter=parameter; init.variant=0; init.situation=2;
 init.status=0x80; init.reserved2=0; init.motion=0x35f; init.reserved3=0;
 init.flags.first=1; init.flags.second=0; init.flags.third=0; init.flags.fourth=0;
 init.flags.fifth=1; init.flags.sixth=0; init.flags.seventh=0; init.flags.eighth=0;
 init.flags.ninth=0; init.flags.tenth=0;
 fn_27_1D8370(self,&init);
 Owner* owner=self->owner;
 Work* work=owner->holder->work;
 work->slot5(power,0x10000005);
 work->slot13(factor,0x11000009);
 work->slot5(kind,0x10000009);
 work->slot13(lbl_27_rodata_7E18,0x1100000a);
 int effect=0x1230001;
 if(kind==0x21) effect=0x220007;
 Vec3f pos;
 Vec3f rot;
 rot.m_x=lbl_27_rodata_7E14; rot.m_y=lbl_27_rodata_7E14; rot.m_z=lbl_27_rodata_7E14;
 pos.m_x=lbl_27_rodata_7E14; pos.m_y=lbl_27_rodata_7E14; pos.m_z=lbl_27_rodata_7E14;
 work->slot5(owner->holder->effect->slot11(effect,0,&pos,&rot,0,0,0,lbl_27_rodata_7E18,-1),0x10000008);
 work=owner->holder->work;
 Link* link=(Link*)__dynamic_cast(owner->obj,0x3c,lbl_27_data_9B6C0,lbl_27_data_248,1);
 Data* data=fn_27_14954C(g_ftCommonDataAccesser,work->slot4(0x10000009));
 float base=soValueAccesser::getConstantFloat((soModuleAccesser*)owner,0xfa6,0);
 Data* other=fn_27_14954C(g_ftCommonDataAccesser,link->owner->holder->work->slot4(0x10000009));
 int level=link->owner->holder->work->slot4(0x10000005)/other->divisor;
 if(level<0) level=0; else if(level>=other->max) level=other->max;
 float scale=soValueAccesser::getConstantFloat((soModuleAccesser*)owner,level+0xfa7,0);
 float f=work->slot12(0x1100000a);
 float g=work->slot12(0x11000009);
 owner->holder->posture->slot23(f*((lbl_27_rodata_7E18/base)*(data->add+scale*(g*data->mul))));
 self->owner->holder->work->slot18(0x12000000);
 owner->holder->status->slot34(0,owner);
 self->slot43();
}
}