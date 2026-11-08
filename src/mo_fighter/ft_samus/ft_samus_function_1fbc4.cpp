#include <so/stageobject.h>
#include <memory.h>
#pragma force_active on
struct Flags { unsigned char first:1,second:1,third:1,fourth:1; unsigned char fifth:1,sixth:1,seventh:1,eighth:1; unsigned char ninth:1,tenth:1,reserved:6; };
struct Initialize { int resource,team,teamOwner,teamAnother,index,owner,reserved0,reserved1; Vec3f position; float facing; int parameter,variant,situation,status,reserved2,motion,reserved3; Flags flags; };
extern "C" {
extern const float lbl_94_rodata_A8;
void fn_94_94E0(Vec3f*,float,float,float);
void fn_27_1D8370(void*,const Initialize*);
void fn_94_1FBC4(StageObject* object,int resource,int team,int reserved0,int teamAnother,int arg5,int arg6,int parameter) {
 Vec3f position; fn_94_94E0(&position,lbl_94_rodata_A8,lbl_94_rodata_A8,lbl_94_rodata_A8);
 Initialize p; p.resource=resource;p.team=team;p.teamOwner=team;p.index=-1;p.owner=-1;p.reserved0=reserved0;p.reserved1=0;
 __memcpy(&p.position,&position,sizeof(Vec3f)); p.facing=lbl_94_rodata_A8;p.parameter=parameter;p.variant=0;p.situation=2;p.status=0x80;p.reserved2=0;p.motion=0x35f;p.reserved3=0;
 p.flags.first=1;p.flags.second=0;p.flags.third=0;p.flags.fourth=0;p.flags.fifth=1;p.flags.sixth=0;p.flags.seventh=0;p.flags.eighth=0;p.flags.ninth=0;p.flags.tenth=0;
 p.teamAnother=teamAnother;
 fn_27_1D8370(object,&p);
 soWorkManageModule* m=object->m_moduleAccesser->m_enumerationStart->m_workManageModule;
 m->setInt(team,0x20000000);m->setInt(reserved0,0x20000001);m->setInt(arg6,0x20000002);
 object->m_moduleAccesser->m_enumerationStart->m_linkModule->setModelConstraintPosOrt(3,arg6,arg5,3,1);
 object->m_moduleAccesser->m_enumerationStart->m_groundModule->setCorrect((soGroundShapeImpl::CorrectKind)0,0);
}
}