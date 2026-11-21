#pragma force_active on
#include <types.h>
#include <so/event/so_event_system.h>
extern "C" {
extern char lbl_27_bss_AC0[];
extern char lbl_27_data_3CB8[];
extern char __RTTI__11soEventUnit[];
void* __dynamic_cast(void*, long, const void*, const void*, long);
float fn_27_379A0(void*, void*);
}
struct ElemView { virtual void v0(); virtual void v1(); virtual void invoke(void*, void*, void*, void*, int, float, float); };
struct ListView { virtual void v0(); virtual void v1(); virtual ElemView** get(int); virtual void v3(); virtual int size(); };
struct EvUnitView { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual ListView* getObserverListSub(); };
struct HitGroupArrayView { virtual void v0(); virtual void* getGroup(void*); virtual void v2(); };
struct Arg1View { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual int method_44(int, int); };
struct Arg3View { char pad[0x24]; unsigned char f24; char pad2[2]; unsigned char f27; };
class soCollisionHitModuleImpl {
public:
virtual void isNull(); virtual ~soCollisionHitModuleImpl();
virtual void fn_27_42F88(); virtual void fn_27_43044(); virtual void fn_27_430F8(); virtual void fn_27_43184(); virtual void fn_27_431DC(); virtual void fn_27_43480(); virtual void fn_27_43504(); virtual void fn_27_43528(); virtual void fn_27_435A4(); virtual void fn_27_43620(); virtual void fn_27_43664(); virtual void fn_27_436CC(); virtual void fn_27_43724(); virtual void fn_27_4377C(); virtual void fn_27_437E4(); virtual void fn_27_4384C(); virtual void fn_27_438B4(); virtual void fn_27_43910(); virtual void fn_27_43B78(); virtual void fn_27_43BAC(); virtual void fn_27_43C04(); virtual void fn_27_43CE0(); virtual void fn_27_43DA4(); virtual void fn_27_44000(); virtual void fn_27_4425C(); virtual void fn_27_444B8(); virtual void fn_27_44720(); virtual void fn_27_4497C(); virtual void fn_27_44BD8(); virtual void fn_27_44E48(); virtual void fn_27_44E7C(); virtual void fn_27_44EB0(); virtual int fn_27_44F40(int);
char _4[0x20]; short m_24; short m_26; void* m_28; void* m_2c; char _30[8]; char m_38[0x20]; HitGroupArrayView* m_58;
};
static bool checkManageId(const soCollisionHitModuleImpl* self, s32& mId) { mId=self->m_24; return soEventSystem::getInstance()->getInstanceManager().isContain(mId); }
static inline ListView* selectList(soCollisionHitModuleImpl* self) {
ListView* sel; short evId; soEventManager* mgr; EvUnitView* unit; ListView* cur; int flag; s32 mId;
if(self->m_24<=-1){sel=(ListView*)lbl_27_bss_AC0;goto LOOP;} if(self->m_28!=0)goto CHECK_CACHE;
if(self->m_24<=-1 || !checkManageId(self,mId)){flag=0;goto CHECK_VALID;}
if(soEventSystem::getInstance()->getManager(self->m_24)->getObserverCapacity(self->m_26)==0){self->m_28=0;flag=0;goto CHECK_VALID;}
evId=self->m_26; mgr=soEventSystem::getInstance()->getManager(self->m_24);
if(mgr->getObserverCapacity(evId)==0)cur=0;else{unit=(EvUnitView*)__dynamic_cast(mgr->getEventUnit(evId),0,lbl_27_data_3CB8,__RTTI__11soEventUnit,0);if(unit==0)cur=0;else cur=unit->getObserverListSub();}
self->m_28=cur;flag=(cur!=0);
CHECK_VALID:if(flag)goto CHECK_CACHE;sel=(ListView*)lbl_27_bss_AC0;goto LOOP;
CHECK_CACHE:mgr=soEventSystem::getInstance()->getManager(self->m_24);if(mgr->getObserverCapacity(self->m_26)==0){self->m_28=0;sel=(ListView*)lbl_27_bss_AC0;}else sel=(ListView*)self->m_28;
LOOP:return sel;
}
extern "C" void fn_27_45510(soCollisionHitModuleImpl* self, Arg1View* arg1, void* arg2, Arg3View* arg3, void* arg4) {
ListView* sel; int invokeFlag; int i; ElemView** e;
invokeFlag=1; if(arg1->method_44(arg3->f24,arg3->f27)!=0 || self->fn_27_44F40(0)!=1)invokeFlag=0;
sel=selectList(self);
for(i=0;i<sel->size();i++){float val=*(float*)((u8*)self->m_58->getGroup(arg4)+0x14);e=sel->get(i);(*e)->invoke(arg1,arg3,arg4,self->m_2c,invokeFlag,fn_27_379A0(self->m_38,arg4),val);}
}
