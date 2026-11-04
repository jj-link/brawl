#include <so/so_value_accesser.h>
#pragma force_active on
#pragma fp_contract off
class KineticRaw {
public:
 virtual void isNull(); virtual void activate(); virtual void deactivate(); virtual void addEnergy(); virtual void eraseEnergy(); virtual void eraseEnergyAll(); virtual void getEnergy(); virtual void isContain(); virtual void updateEnergy(); virtual void clearSpeedAll(); virtual void suspendEnergyAll(); virtual void resumeEnergyAll(); virtual void unableEnergyAll(); virtual unsigned long long getSumSpeed(short*);
};
struct Pair { float x; float y; };
inline Pair toPair(unsigned long long value) { return *(Pair*)&value; }
inline float addValues(float a, const Vec3f& b) { return a + b.m_y; }
struct Out { unsigned short id; float x; float y; unsigned char flag; };
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_27_22A914(void*);
extern "C" int fn_27_22B3B8(void*, unsigned long, Out*);
extern void* lbl_27_bss_5780;
extern float lbl_27_rodata_2440;
extern float lbl_27_rodata_2450;
extern "C" void fn_27_181C98(void*, soModuleAccesser* obj) {
 switch (obj->m_enumerationStart->m_statusModule->getStatusKind()) {
 case 0xb5: case 0xb6: case 0xb7: case 0xb8: case 0xb9: case 0xbb: {
  unsigned int touch = obj->m_enumerationStart->m_groundModule->isTouch((grCollStatus::TouchMask)8,0);
  if (obj->m_enumerationStart->m_areaModule->getEnviromentElementChecker()->isWater() == 1 && touch == 1) {
   if (obj->m_enumerationStart->m_workManageModule->getInt(0x10000027) <= 0) {
    Vec3f pos = obj->m_enumerationStart->m_postureModule->getPos();
    float water = obj->m_enumerationStart->m_areaModule->getEnviromentElementChecker()->getWaterSurfaceY();
    float scale = obj->m_enumerationStart->m_postureModule->getScale();
    float height = lbl_27_rodata_2450 * soValueAccesser::getConstantFloat(obj,0xbe5,0);
    height *= scale;
    if (water < pos.m_y + height) obj->m_enumerationStart->m_statusModule->changeStatusRequest(0,obj);
   }
  }
  break;
 }
 case 0xb3: {
  if (obj->m_enumerationStart->m_groundModule->isTouch((grCollStatus::TouchMask)8,0)) {
   obj->m_enumerationStart->m_statusModule->changeStatusRequest(0xb4,obj);
  } else {
   short flag = -1;
   Pair speed = toPair(((KineticRaw*)obj->m_enumerationStart->m_kineticModule)->getSumSpeed(&flag));
   if (speed.y > lbl_27_rodata_2440) {
    int key = obj->m_enumerationStart->m_workManageModule->getInt(0x20000002);
    if (!lbl_27_bss_5780) {
     void* p = __nw__FUlQ25Heaps8HeapType(0x54,2);
     if (p) p=fn_27_22A914(p);
     lbl_27_bss_5780=p;
    }
    Out out;
    if ((unsigned int)(fn_27_22B3B8(lbl_27_bss_5780,key,&out)==1)==1) {
     Vec3f pos = obj->m_enumerationStart->m_postureModule->getPos();
     if (pos.m_y > addValues(out.x, obj->m_enumerationStart->m_motionModule->getTransNTranslate()))
      obj->m_enumerationStart->m_statusModule->changeStatusRequest(0xb6,obj);
     else obj->m_enumerationStart->m_statusModule->changeStatusRequest(0xb4,obj);
    }
   }
  }
  break;
 }
 case 0xb4: {
  int key = obj->m_enumerationStart->m_workManageModule->getInt(0x20000002);
  if (!lbl_27_bss_5780) {
   void* p=__nw__FUlQ25Heaps8HeapType(0x54,2);
   if (p) p=fn_27_22A914(p);
   lbl_27_bss_5780=p;
  }
  Out out;
  if ((unsigned int)(fn_27_22B3B8(lbl_27_bss_5780,key,&out)==1)==1) {
   Vec3f pos=obj->m_enumerationStart->m_postureModule->getPos();
   if (pos.m_y > addValues(out.x, obj->m_enumerationStart->m_motionModule->getTransNTranslate()))
    obj->m_enumerationStart->m_statusModule->changeStatusRequest(0xb5,obj);
  }
  break;
 }
 }
}