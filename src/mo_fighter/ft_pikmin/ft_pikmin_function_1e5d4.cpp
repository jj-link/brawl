#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <mo_fighter/ft_dedede/ft_dedede_speed_ground_view.h>
#include <mt/mt_vector.h>
#pragma force_active on

struct SpeedWords { float x, y; };
struct KineticView {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void unableEnergyAll();
 virtual SpeedWords getSumSpeed(short*);
};
struct Energy {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12();
 virtual void activate();
 unsigned char nullByte, flags, pad[2];
 Vec2f speed, accel, p18, p20, p28;
 unsigned char active;
};
struct Flag { unsigned char value; };
extern "C" {
extern const float lbl_113_rodata_90, lbl_113_rodata_98;
float fn_113_182E4(float*);
unsigned int fn_113_1E50C(float*);
void fn_113_1E5B8(Vec2f*, float);
void fn_8003DBA8(Vec2f*);
void fn_113_BC00(Vec2f*, const Vec2f*);
}
extern "C" void fn_113_1E5D4(void*, unsigned char* self, soModuleAccesser* access) {
 Energy* stop;
 short attr = 1;
 Vec2f speed;
 Vec2f::copy(speed, *reinterpret_cast<const Vec2f*>(&reinterpret_cast<KineticView*>(&access->getKineticModule())->getSumSpeed(&attr)));
 access->getKineticModule().unableEnergyAll();
 soParamAccesser* params = static_cast<soParamAccesser*>(access->getWorkManageModule().getParamAccesser());
 float limit = params->getParamFloat(access, 0xfce, 0);
 if (fn_113_182E4((float*)&speed) < limit) {
  if (fn_113_1E50C((float*)&speed) == 1) {
   speed.m_x = lbl_113_rodata_98;
   speed.m_y = lbl_113_rodata_90;
  } else fn_8003DBA8(&speed);
  fn_113_1E5B8(&speed, params->getParamFloat(access, 0xfce, 0));
 }
 Flag flag = {0};
 stop = reinterpret_cast<Energy*>(self += 0x10);
 stop->active = 0;
 stop->activate();
 fn_113_BC00(&stop->speed, &speed);
 float a = params->getParamFloat(access, 0xfc7, 0);
 fn_113_BC00(&stop->p18, &Vec2f(a, a));
 float b = params->getParamFloat(access, 0xfc8, 0);
 fn_113_BC00(&stop->p20, &Vec2f(b, b));
 float c = params->getParamFloat(access, 0xfc9, 0);
 fn_113_BC00(&stop->p28, &Vec2f(c, c));
 fn_113_BC00(&stop->accel, &Vec2f(params->getParamFloat(access, 0xfc6, 0), lbl_113_rodata_90));
 reinterpret_cast<unsigned char*>(stop)[5] |= 0x80;
}
