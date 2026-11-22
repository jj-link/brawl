#include <so/stageobject.h>
#include <memory.h>
#pragma force_active on
struct PhysicsModulePrefix { unsigned char prefix[8]; };
class PhysicsModule : public PhysicsModulePrefix {
public:
    virtual void slot_8() = 0;
    virtual void slot_c() = 0;
    virtual void slot_10() = 0;
    virtual void slot_14() = 0;
    virtual void initialize(unsigned int, int, int, int, int, int, bool, int) = 0;
    virtual void slot_1c() = 0;
    virtual void slot_20() = 0;
    virtual void slot_24() = 0;
    virtual void slot_28() = 0;
    virtual void slot_2c() = 0;
    virtual void slot_30() = 0;
    virtual void slot_34() = 0;
    virtual void slot_38() = 0;
    virtual void slot_3c() = 0;
    virtual void slot_40() = 0;
    virtual void slot_44() = 0;
    virtual void slot_48() = 0;
    virtual void slot_4c() = 0;
    virtual void slot_50() = 0;
    virtual void slot_54() = 0;
    virtual void slot_58() = 0;
    virtual void slot_5c() = 0;
    virtual void slot_60() = 0;
    virtual void slot_64() = 0;
    virtual void slot_68() = 0;
    virtual void slot_6c() = 0;
    virtual void slot_70() = 0;
    virtual void slot_74() = 0;
    virtual void slot_78() = 0;
    virtual void slot_7c() = 0;
    virtual void slot_80() = 0;
    virtual void slot_84() = 0;
    virtual void slot_88() = 0;
    virtual void slot_8c() = 0;
    virtual void slot_90() = 0;
    virtual void slot_94() = 0;
    virtual void slot_98() = 0;
    virtual void slot_9c() = 0;
    virtual void slot_a0() = 0;
    virtual void setMode(int) = 0;
    virtual void slot_a8() = 0;
    virtual void slot_ac() = 0;
    virtual void slot_b0() = 0;
    virtual void slot_b4() = 0;
    virtual void slot_b8() = 0;
    virtual void slot_bc() = 0;
    virtual void slot_c0() = 0;
    virtual void slot_c4() = 0;
    virtual void slot_c8() = 0;
    virtual void slot_cc() = 0;
    virtual void slot_d0() = 0;
    virtual void slot_d4() = 0;
    virtual void slot_d8() = 0;
    virtual void setScale(float) = 0;
};

struct InitFlags { unsigned char first:1,second:1,third:1,fourth:1; unsigned char fifth:1,sixth:1,seventh:1,eighth:1; unsigned char ninth:1,tenth:1,reserved:6; };
struct Init { int resource,team,teamOwner,teamAnother,index,owner; int reserved0,reserved1; Vec3f position; float facing; int parameter,variant,situation,status,reserved2,motion,reserved3; InitFlags flags; };
extern "C" int lbl_116_data_C088;
inline soResourceModule& resourceFrom(const soModuleEnumeration* modules) { return *modules->m_resourceModule; }
inline void initializePhysics(int lbl, PhysicsModule* module, soResourceModule& resource) {
 module->initialize(resource.getResourceIdAccesser()->getBinResId(),10,lbl,lbl,11,0,false,-1);
}
inline soPostureModule& postureFrom(const soModuleEnumeration* modules) { return *modules->m_postureModule; }
inline void scalePhysics(PhysicsModule& module, soPostureModule& posture) {
 module.setScale(posture.getScale());
}
extern "C" {
void fn_27_1D8370(void*, const Init*);
void fn_116_2639C(StageObject* object,int resource,int team,int another,int index,int owner,int parameter,const Vec3f* position,float facing,bool special) {
 Init init;
 init.resource=resource; init.team=team; init.teamOwner=team; init.teamAnother=team; init.index=-1; init.owner=-1; init.reserved0=0; init.reserved1=0;
 __memcpy(&init.position,position,sizeof(Vec3f));
 init.facing=facing; init.parameter=parameter; init.variant=0; init.situation=2; init.status=0x80; init.reserved2=0; init.motion=0x35f; init.reserved3=0;
 init.flags.first=1; init.flags.second=1; init.flags.third=0; init.flags.fourth=0; init.flags.fifth=1; init.flags.sixth=0; init.flags.seventh=0; init.flags.eighth=0; init.flags.ninth=0; init.flags.tenth=0;
 init.teamAnother=another; init.index=index; init.owner=owner; init.flags.ninth=1;
 fn_27_1D8370(object,&init);
 object->m_moduleAccesser->getKineticModule().changeKinetic(2,object->m_moduleAccesser);
 if(special==1) {
  const soModuleEnumeration* modules=object->m_moduleAccesser->m_enumerationStart;
  initializePhysics(lbl_116_data_C088,static_cast<PhysicsModule*>(modules->m_physicsModule),resourceFrom(modules));
  object->m_moduleAccesser->getWorkManageModule().setFlag(false,0x22000000);
  object->m_moduleAccesser->getWorkManageModule().setInt(8,0x10000005);
  modules=object->m_moduleAccesser->m_enumerationStart;
  soPostureModule* posture=modules->m_postureModule;
  scalePhysics(*static_cast<PhysicsModule*>(modules->m_physicsModule), postureFrom(modules));
  static_cast<PhysicsModule*>(object->m_moduleAccesser->m_enumerationStart->m_physicsModule)->setMode(6);
  object->m_moduleAccesser->getStatusModule().changeStatusForce(1,object->m_moduleAccesser);
 }
 object->m_moduleAccesser->getWorkManageModule().onFlag(0x12000000);
}
}
