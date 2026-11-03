#include <ft/ft_common_data_accesser.h>
#include <so/so_module_accesser.h>
#pragma force_active on
struct ZeldaSpeed { float x, y; };
class Class_7E68 {
public:
 virtual void fn_104_7930(); virtual void fn_104_120EC(); virtual void fn_104_1283C(); virtual void fn_104_12838(); virtual void fn_104_12834(); virtual void fn_104_12830(); virtual void fn_104_12828(); virtual void fn_104_12870(); virtual void fn_104_12868(); virtual void fn_104_12860(); virtual void fn_104_12858(); virtual void fn_104_12850(); virtual void fn_104_127E8(); virtual void fn_104_1281C(); virtual void fn_104_12810(); virtual void fn_104_12808(); virtual void fn_104_127FC();
};
class Class_7FC8 {
public:
 virtual void fn_104_7930(); virtual void fn_104_12090(); virtual void fn_104_12990(); virtual void fn_104_12988(); virtual void fn_104_12980(); virtual void fn_104_12978(); virtual void fn_104_12970(); virtual void fn_104_12968(); virtual void fn_104_12960(); virtual void fn_104_12958(); virtual void fn_104_12950(); virtual void fn_104_12948(); virtual void fn_104_12940(); virtual void fn_104_12938(); virtual void fn_104_128E8(); virtual void fn_104_12930(); virtual void fn_104_12920();
};
class ZeldaKineticView {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12();
 virtual ZeldaSpeed getSumSpeed(const short&);
};
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const char lbl_104_data_72B4[], lbl_104_data_7138[], lbl_104_data_2404[];
extern const float lbl_104_rodata_188;
}
extern "C" void fn_104_1FD94(void*, soModuleAccesser* accesser) {
 if (accesser->getStatusModule().getStatusKind() == 0x115) {
  soSituationModule* situation = &accesser->getSituationModule();
  soKineticModule* kinetic = &accesser->getKineticModule();
  float* params = *(float**)((char*)g_ftCommonDataAccesser.getData(static_cast<ftKind>(14)) + 0x88);
  short one = 1;
  char* gravity = (char*)__dynamic_cast(kinetic->getEnergy(1), 0, lbl_104_data_72B4, lbl_104_data_2404, one);
  char* stop = (char*)__dynamic_cast(kinetic->getEnergy(3), 0, lbl_104_data_7138, lbl_104_data_2404, one);
  short mask = -1;
  Vec2f speed;
  ZeldaSpeed returnedSpeed = ((ZeldaKineticView*)kinetic)->getSumSpeed(mask);
  __memcpy(&speed, &returnedSpeed, sizeof(speed));
  kinetic->clearSpeedAll();
  speed.m_x /= params[0];
  Vec2f newSpeed;
  newSpeed.m_x = speed.m_x;
  newSpeed.m_y = lbl_104_rodata_188;
  *(float*)(stop + 8) = newSpeed.m_x;
  *(float*)(stop + 12) = newSpeed.m_y;
  stop[5] |= 0x80;
  if (situation->getKind() != 0) {
   speed.m_y /= params[1];
   *(float*)(gravity + 12) = speed.m_y;
   gravity[5] |= 0x80;
  }
 }
}