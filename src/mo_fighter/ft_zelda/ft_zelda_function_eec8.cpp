#include <ft/ft_common_data_accesser.h>
#include <so/so_module_accesser.h>
#include <so/status/so_status_module_impl.h>
#include <so/situation/so_situation_module_impl.h>
#include <so/kinetic/so_kinetic_module_impl.h>
#pragma force_active on
struct ZeldaSpeed { float x, y; };
class Obj { public:
 virtual ~Obj(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual int check();
};
class Sit { public:
 virtual ~Sit(); virtual void v2(); virtual void v3(); virtual int getKind();
};
class Kin { public:
 virtual ~Kin(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void* getEnergy(int); virtual void v8(); virtual void v9(); virtual void clearSpeedAll(); virtual void v11(); virtual void v12(); virtual void v13(); virtual ZeldaSpeed getSumSpeed(const short&);
};
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* __memcpy(void*, const void*, unsigned long);
extern const char lbl_104_data_72B4[], lbl_104_data_7138[], lbl_104_data_2404[];
extern const float lbl_104_rodata_58;
}
extern "C" void fn_104_EEC8(void*, soModuleAccesser* accesser) {
 if (((Obj*)&accesser->getStatusModule())->check() == 0x115) {
  soSituationModule* situation=&accesser->getSituationModule();
  Kin* kinetic=(Kin*)&accesser->getKineticModule();
  float* params=*(float**)((char*)g_ftCommonDataAccesser.getData((ftKind)13)+0x88);
  unsigned char* gravity=(unsigned char*)__dynamic_cast(kinetic->getEnergy(1),0,lbl_104_data_72B4,lbl_104_data_2404,1);
  unsigned char* stop=(unsigned char*)__dynamic_cast(kinetic->getEnergy(3),0,lbl_104_data_7138,lbl_104_data_2404,1);
  short mask=-1;
  Vec2f speed;
  ZeldaSpeed sum=kinetic->getSumSpeed(mask);
  __memcpy(&speed,&sum,sizeof(speed));
  kinetic->clearSpeedAll();
  speed.m_x/=params[0];
  speed.m_y/=params[1];
  Vec2f newSpeed;
  newSpeed.m_x=speed.m_x;
  newSpeed.m_y=lbl_104_rodata_58;
  *(float*)(stop+8)=newSpeed.m_x;
  *(float*)(stop+12)=newSpeed.m_y;
  stop[5]|=0x80;
  if (((Sit*)situation)->getKind()!=0) {
   *(float*)(gravity+12)=speed.m_y;
   gravity[5]|=0x80;
  }
 }
}