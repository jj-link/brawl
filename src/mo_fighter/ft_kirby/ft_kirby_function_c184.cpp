#include <types.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/stageobject.h>
#include <mt/mt_vector.h>
#pragma force_active on
struct KirbyEvent { int kind; bool handled; unsigned char pad05[3]; unsigned int node; unsigned int pad0C; union { float valueX; unsigned char flag; }; float valueY; };
struct KirbyHandler { unsigned char pad00[0x60]; soModuleAccesser* accesser; };
class KirbyCatchModule { public:
virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14(); virtual void slot18(); virtual void slot1C(int); virtual void slot20(); virtual void slot24(); virtual void slot28(); virtual void setCatch(int,bool); virtual void slot30(); virtual void slot34(); virtual void slot38(); virtual void slot3C(); virtual void releaseCatch(int);
};
class KirbySoundModule { public: virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14(); virtual void slot18(); virtual int playSE(SndID,bool,bool,int); };
extern "C" {
float fn_27_8CAD0(void*);
void fn_27_1324D4(KirbyHandler*,KirbyEvent*,soModuleAccesser*,StageObject*,int);
void fn_96_D5C4(KirbyHandler*,soModuleAccesser*,int);
Vec3f* fn_96_BC54(Vec3f*,float,float,float);
extern const float lbl_96_rodata_4, lbl_96_rodata_8;
}
static inline KirbyCatchModule* kirbyCatch(soModuleAccesser* a) { return static_cast<KirbyCatchModule*>(a->m_enumerationStart->m_catchModule); }
extern "C" void fn_96_C184(KirbyHandler* self,KirbyEvent* event,soModuleAccesser* accesser,StageObject* object,int eventType) {
soStatusModule* status=accesser->m_enumerationStart->m_statusModule;
switch(event->kind) {
case 8: {
int kind=status->getStatusKind();
if(kind==0x112 || kind==0x117) {
float scale=fn_27_8CAD0(object);
if(scale<=accesser->getPostureModule().getScale()) { status->changeStatusRequest(0x119,self->accesser); event->node=self->accesser->getModelModule().getCorrectNodeId(0x12C); event->handled=true; }
return;
} else if((unsigned int)(kind-0x14B)<=1) {
float scale=fn_27_8CAD0(object);
if(scale<=accesser->getPostureModule().getScale()) { status->changeStatusRequest(0x14E,accesser); event->node=accesser->getModelModule().getCorrectNodeId(0x12C); event->handled=true; }
return;
} else if(kind==0x159) {
event->node=accesser->getModelModule().getCorrectNodeId(0x12C); event->handled=true; kirbyCatch(accesser)->slot1C(-1); status->changeStatusRequest(0x15A,accesser); return;
} else if(status->getStatusKind()==0x192 || status->getStatusKind()==0x193) {
float scale=fn_27_8CAD0(object);
if(scale<=accesser->getPostureModule().getScale()) { status->changeStatusRequest(0x195,self->accesser); event->node=self->accesser->getModelModule().getCorrectNodeId(0x12C); event->handled=true; }
return;
}
break;
}
case 15: status->changeStatusRequest(0x150,accesser); return;
case 20:
if(self->accesser->getWorkManageModule().isFlag(0x12000042)) {
if(self->accesser->getWorkManageModule().getInt(0x10000048)==0x20) status->changeStatusRequest(0x196,self->accesser);
} else status->changeStatusRequest(0x11A,self->accesser);
break;
case 9:
if(status->getStatusKind()<0x11B || status->getStatusKind()>0x125) {
if(status->getStatusKind()>=0x197 && status->getStatusKind()<=0x1A2) {
kirbyCatch(self->accesser)->releaseCatch(0); kirbyCatch(self->accesser)->setCatch(0,true);
if(accesser->getSituationModule().getKind()==2) status->changeStatusRequest(0xE,self->accesser); else status->changeStatusRequest(0,self->accesser);
return;
}
if(status->getStatusKind()==0x119 || status->getStatusKind()==0x11A || status->getStatusKind()==0x195 || status->getStatusKind()==0x196) break;
if(status->getStatusKind()==0x128 || status->getStatusKind()==0x127 || status->getStatusKind()==0x1A4) {
if(accesser->getWorkManageModule().isFlag(0x22000016)) {
kirbyCatch(accesser)->releaseCatch(0); kirbyCatch(accesser)->setCatch(0,false);
} else {
kirbyCatch(self->accesser)->releaseCatch(0); kirbyCatch(self->accesser)->setCatch(0,true);
if(accesser->getSituationModule().getKind()==2) status->changeStatusRequest(0xE,self->accesser); else status->changeStatusRequest(0,self->accesser);
}
return;
}
}
break;
case 24:
accesser->m_enumerationStart->m_workManageModule->setFloat(event->valueX,0x21000006);
accesser->getWorkManageModule().setFloat(event->valueY,0x21000007);
accesser->getWorkManageModule().onFlag(0x22000017);
break;
case 0x2F: {
accesser->m_enumerationStart->m_workManageModule->addInt(1,0x20000008);
accesser->getWorkManageModule().addInt(1,0x20000020);
accesser->getWorkManageModule().addInt(soValueAccesser::getConstantInt(accesser,0x5DC9,0),0x2000000A);
const soModuleEnumeration* effectModules=accesser->m_enumerationStart;
soLinkModule* link=effectModules->m_linkModule;
soEffectModule* effect=effectModules->m_effectModule;
effect->req((EfID)0xE60008,&link->getParentModelNodeGlobalPosition(6,(u32)0,false),fn_96_BC54(&Vec3f(),lbl_96_rodata_8,lbl_96_rodata_8,lbl_96_rodata_8),lbl_96_rodata_4,0,-1);
switch(soValueAccesser::getConstantInt(accesser,0x59E8,0)) {
case 0: reinterpret_cast<KirbySoundModule*>(accesser->m_enumerationStart->m_soundModule)->playSE((SndID)0xBA,false,false,0); break;
case 1: reinterpret_cast<KirbySoundModule*>(accesser->m_enumerationStart->m_soundModule)->playSE((SndID)0xBB,false,false,0); break;
case 2: reinterpret_cast<KirbySoundModule*>(accesser->m_enumerationStart->m_soundModule)->playSE((SndID)0xBC,false,false,0); break;
}
accesser->m_enumerationStart->m_controllerModule->setRumble(5,10,false,-1); break;
}
case 0x30: {
accesser->m_enumerationStart->m_workManageModule->addInt(1,0x20000009);
soWorkManageModule* work=accesser->m_enumerationStart->m_workManageModule;
work->addInt(soValueAccesser::getConstantInt(accesser,0x5DCB,0),0x2000000A);
break;
}
case 0x455:
if(status->getStatusKind()==0x116) accesser->getWorkManageModule().onFlag(0x22000018);
break;
case 0x456:
if(status->getStatusKind()==0x116 || status->getStatusKind()==0x12E || status->getStatusKind()==0x12F || status->getStatusKind()==0x130 || status->getStatusKind()==0x131 || status->getStatusKind()==0x132) {
if(accesser->getSituationModule().getKind()==2) status->changeStatusRequest(0xE,self->accesser); else status->changeStatusRequest(0,self->accesser);
return;
}
case 0x33: {
int count=accesser->getWorkManageModule().getInt(0x20000006);
int i=0;
while(i<count) {
if(event->node==(unsigned int)accesser->getWorkManageModule().getInt(0x20000000+i)) accesser->getWorkManageModule().setInt(-1,0x20000000+i);
i++;
}
if(status->getStatusKind()==0x12E) {
if(event->flag==1) accesser->getWorkManageModule().addInt(1,0x20000020);
} else if(status->getStatusKind()!=0x12F && status->getStatusKind()!=0x130) status->getStatusKind();
return;
}
case 0x17: if(event->flag) fn_96_D5C4(self,accesser,0); break;
}
if(object->soGetKind()==2) {
switch(object->soGetSubKind()) {
case 0x4D:
switch(event->kind) { case 0x838: if(accesser->m_enumerationStart->m_statusModule->getStatusKind()==0x170) accesser->m_enumerationStart->m_statusModule->changeStatusRequest(0x172,accesser); break; }
return;
case 0x66:
switch(event->kind) { case 0x838: if(accesser->m_enumerationStart->m_statusModule->getStatusKind()==0x174) accesser->m_enumerationStart->m_statusModule->changeStatusRequest(0x176,accesser); break; }
return;
}
}
fn_27_1324D4(self,event,accesser,object,eventType);
}
