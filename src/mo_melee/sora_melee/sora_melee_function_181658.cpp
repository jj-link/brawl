#include <so/so_value_accesser.h>
#include <sr/sr_common.h>
#pragma force_active on
#pragma fp_contract off

inline float addComponents(float a, const Vec3f& b) { return a + b.m_y; }
inline float addValues(const float& a, soModuleAccesser* obj) { return addComponents(a, obj->m_enumerationStart->m_motionModule->getTransNTranslate()); }
inline Vec3f makeRotation(const float& zero) { Vec3f v; v.m_x = zero; v.m_y = zero; v.m_z = zero; return v; }
struct Out { unsigned short id; float x; float y; unsigned char flag; };
extern "C" void* fn_27_22A914(void*);
extern "C" int fn_27_22B3B8(void*, unsigned long, Out*);
extern "C" void fn_27_194390(soModuleAccesser*, float*, float);
extern void* lbl_27_bss_5780;
extern float lbl_27_rodata_2440;
extern float lbl_27_rodata_244C;

extern "C" void fn_27_181658(void*, soModuleAccesser* obj) {
 int status = obj->m_enumerationStart->m_statusModule->getStatusKind();
 switch(status) {
 case 0xb5: case 0xb6: case 0xb7: case 0xb8: case 0xb9: case 0xbb: {
  int key = obj->m_enumerationStart->m_workManageModule->getInt(0x20000002);
  if (!lbl_27_bss_5780) {
   void* p = operator new(0x54, Heaps::System);
   if (p) p = fn_27_22A914(p);
   lbl_27_bss_5780 = p;
  }
  Out out;
  if ((unsigned int)(fn_27_22B3B8(lbl_27_bss_5780,key,&out)==1)==1) {
   Vec3f pos = obj->m_enumerationStart->m_postureModule->getPos();
   pos.m_y += lbl_27_rodata_244C * (addValues(out.x, obj) - pos.m_y);
   obj->m_enumerationStart->m_postureModule->setPos(&pos);
   if (lbl_27_rodata_2440 != out.y) {
    obj->m_enumerationStart->m_kineticModule->addSpeedOutside(soKineticEnergy::Outside_Wind, &Vec3f(out.y, lbl_27_rodata_2440, lbl_27_rodata_2440));
   }
   if (out.flag) obj->m_enumerationStart->m_workManageModule->incInt(0x10000014);
   if (status == 0xb7) {
    float vals[2];
    fn_27_194390(obj,vals,soValueAccesser::getConstantFloat(obj,0xc2d,0));
    obj->m_enumerationStart->m_motionModule->setRate(vals[0]);
   }
  }
  if (status == 0xbb) {
   int count = obj->m_enumerationStart->m_workManageModule->getInt(0x20000003);
   count++;
   if (count > soValueAccesser::getConstantInt(obj,0x5a4a,0)) {
    float scale = soValueAccesser::getConstantFloat(obj,0xbe9,0);
    Vec3f pos = obj->m_enumerationStart->m_postureModule->getPos();
    pos.m_y = out.x;
    obj->m_enumerationStart->m_effectModule->req((EfID)0x50,&pos,&makeRotation(lbl_27_rodata_2440),scale,0,-1);
    count = 0;
   }
   obj->m_enumerationStart->m_workManageModule->setInt(count,0x20000003);
  } else {
   int count = obj->m_enumerationStart->m_workManageModule->getInt(0x20000003);
   count++;
   if (count > soValueAccesser::getConstantInt(obj,0x5a47,0)) {
    int key = obj->m_enumerationStart->m_workManageModule->getInt(0x20000002);
    if (!lbl_27_bss_5780) {
     void* p = operator new(0x54,Heaps::System);
     if (p) p = fn_27_22A914(p);
     lbl_27_bss_5780 = p;
    }
    Out out;
    if ((unsigned int)(fn_27_22B3B8(lbl_27_bss_5780,key,&out)==1)==1) {
     float scale = soValueAccesser::getConstantFloat(obj,0xbe9,0);
     Vec3f pos = obj->m_enumerationStart->m_postureModule->getPos();
     pos.m_y = out.x;
     obj->m_enumerationStart->m_effectModule->req((EfID)0x4f,&pos,&makeRotation(lbl_27_rodata_2440),scale,0,-1);
    }
    count = 0;
   }
   obj->m_enumerationStart->m_workManageModule->setInt(count,0x20000003);
  }
  if (obj->m_enumerationStart->m_groundModule->isTouch((grCollStatus::TouchMask)8,0)) {
   obj->m_enumerationStart->m_areaModule->setAreaShapeType(3,(soAreaInstance::ShapeType)3);
  } else {
   obj->m_enumerationStart->m_areaModule->setAreaShapeType(3,(soAreaInstance::ShapeType)2);
  }
  break;
 }
 }
}
