#pragma always_inline on
#pragma inline_max_size(1000)
#pragma inline_depth(10)
#pragma pool_data on
#pragma pool_fp_consts on
#include <types.h>
#include <math.h>
#include <mt/mt_common.h>
#include <mt/mt_vector.h>
#include <nw4r/math/math_arithmetic.h>
#include <so/so_value_accesser.h>
#include <so/so_module_accesser.h>
#include <em/em_manager.h>
#include <ft/ft_manager.h>
#include <so/so_external_value_accesser.h>
#pragma force_active on

class Team {
public:
 virtual void m0(); virtual void m1(); virtual void m2(); virtual void setTeam(int, bool);
 virtual void m4(); virtual void m5(); virtual void m6(); virtual void setOwner(int);
};
struct Info { char pad[0x6c]; u32 flags; };
class InfoSource {
public:
 virtual void m0(); virtual Info* get(int);
};
struct SpeedWords { u32 first, second; };
struct GroundViewBase { char pad[8]; };
#define V8(a) virtual void a##0(); virtual void a##1(); virtual void a##2(); virtual void a##3(); virtual void a##4(); virtual void a##5(); virtual void a##6(); virtual void a##7();
class GroundView : public GroundViewBase {
public:
 V8(a) V8(b) V8(c) V8(d) V8(e) V8(f) V8(g)
 virtual bool hasContact(int); virtual SpeedWords getContactNormal(int,int);
};
struct Self {
 char pad[0x3c]; soModuleAccesser* acc; InfoSource* source; char pad44[0x78-0x44];
 int owner; char pad7c[0xc4-0x7c]; int enemyId; int enemyMode;
};
struct Hit {
 char pad[0xc]; float damage; char pad10[0x30-0x10]; signed char team;
 char pad31[0x50-0x31]; int kind; char pad54[4]; int field58;
 char pad5c[0x74-0x5c]; u32 flags; char pad78[4]; float direction;
 char pad80[0x8c-0x80]; Vec2f vector;
};
extern "C" {
extern char lbl_41_data_644[], lbl_41_data_6A8[];
extern char __RTTI__16emStopModuleImpl[], __RTTI__12soStopModule[];
extern char __RTTI__5Enemy[], __RTTI__11StageObject[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_63914(void*, void*, float, int);
u32 fn_41_6BC0(void*);
int fn_41_FD44(void*, float);
int fn_41_FE54(void*, int, int*);
float fn_41_FEBC(void*, float, int, int, u32, u32, Vec2f*, float);
int fn_41_101E0(void*, int, float, u32);
float fn_41_103FC(void*, void*, void*, float, Vec2f*, u32, int, float, int);
void fn_41_1068C(void*, void*, Vec2f*);
float fn_41_10894(Vec2f*);
float fn_41_108AC(Vec2f*, Vec2f*);
void* fn_41_159AC(void*, int);
void fn_41_1AE94(void*);
void fn_41_10008(void*, void*, int, u32, u32);
double fn_804005AC(double);
double fn_80400B30(double);
}
static inline float ClampRange(float value, float lo, float hi) {
 float t = value - lo;
 lo = nw4r::math::FSelect(t, value, lo);
 float u = lo - hi;
 return nw4r::math::FSelect(u, hi, lo);
}
static inline float vecAngle(Vec2f* a, Vec2f* b) {
 float len = fn_41_10894(a) * fn_41_10894(b);
 float result;
 if (0.0f == len) result = 0.0f;
 else {
  float dot = fn_41_108AC(a, b);
  dot *= rsqrtf(len);
  result = (float)fn_80400B30(ClampRange(dot, -1.0f, 1.0f));
 }
 return result;
}
#define VF(i) soValueAccesser::getValueFloat(self->acc, i, 0)
#define VI(i) soValueAccesser::getValueInt(self->acc, i, 0)
extern "C" void fn_41_108F8(Self* self, Hit* hit, u32 arg) {
 float duration;
 float direction;
 float base;
 float angle;
 float power;
 float pool;
 double bias;
 pool = 0.0f;
 pool = 0.01745329238474369f;
 pool = 1.0f;
 pool = -1.0f;
 pool = 180.0f;
 pool = 2.0f;
 pool = 1.1754943508222875e-38f;
 pool = 1.5707963705062866f;
 pool = 90.0f;
 pool = 270.0f;
 bias = 4503601774854144.0;
 __dynamic_cast(&self->acc->getStopModule(), 0, __RTTI__16emStopModuleImpl, __RTTI__12soStopModule, 1);
 void* posture;
 soWorkManageModule* work;
 void* kinetic;
 kinetic = __dynamic_cast(&self->acc->getKineticModule(), 0, lbl_41_data_644, lbl_41_data_6A8, 1);
 posture = self->acc->m_enumerationStart->m_postureModule;
 work = self->acc->m_enumerationStart->m_workManageModule;
 int frames = fn_27_63914(self->acc, hit, 1.0f, 0);
 int situation = self->acc->getSituationModule().getKind();
 __dynamic_cast(self->acc->m_stageObject, 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 0);
 u32 reflect = 0;
 u32 flag = work->isFlag(0x12000000);
 u32 flag15 = work->isFlag(0x1200000f);
 u32 special = 0;
 int status = 0;
 u32 bit = 0;
 if (((hit->flags >> 5) & 1) == 1) bit = 1;
 if (self->enemyMode == 1) {
  void* enemy = emManager::getInstance()->getEnemyPtrFromId(self->enemyId);
  if (enemy != 0) special = fn_41_6BC0(enemy);
 }
 if (special == 1 && frames > 0) {
  angle = (float)frames;
  if (flag == 0) angle *= VF(0xbc6);
  else angle *= VF(0xbc7);
  frames = (int)angle;
 }
 if (flag == 1 && special == 0) {
  u32 enabled = VI(0x59e8) != 0;
  if (enabled == 1) reflect = 1;
 }
 power = hit->damage;
 power *= VF(0xbb8);
 base = VF(0xbfb);
 angle = base * VF(0xbea);
 if (hit->field58 != 0) angle *= VF(0xbf8);
 if (power < angle) power = angle;
 else {
  float scale = VF(0xbfc);
  float delta = power - angle;
  delta *= scale;
  power = angle + delta;
 }
 if (bit == 1) power *= VF(0xbcb);
 if (reflect == 1) {
  power *= VF(0xbbc);
  if (power < VF(0xbbd)) power = VF(0xbbd);
  if (power > VF(0xbbe)) power = VF(0xbbe);
 }
 if (arg == 1) {
  base = VF(0xbff);
  power *= VF(0xc00);
  power = base + power;
 }
 duration = power * VF(0xbd4);
 if (reflect == 0) {
  duration *= VF(0xbb9);
  if (flag == 1) duration *= VF(0xbba);
 } else duration = VF(0xbeb);
 int frames2 = (int)(float)fn_804005AC(duration);
 int kind2 = fn_41_FD44(self, duration);
 int kind = hit->kind;
 Vec2f velocity;
 Vec2f normal;
 Vec2f contactNormal;
 Vec2f v;
 __memcpy(&v, &hit->vector, sizeof(v));
 angle = fn_41_FEBC(self, power, kind, situation, reflect, bit, &v, hit->direction);
 int tmp = 0;
 fn_41_FE54(self, kind, &tmp);
 direction = -1.0f * hit->direction;
 float speed = power * VF(0xbd3);
 if (reflect == 0) speed *= VF(0xbbb);
 else {
  speed *= VF(0xbbf);
  if (speed < VF(0xbc0)) speed = VF(0xbc0);
  if (speed > VF(0xbc1)) speed = VF(0xbc1);
  speed *= VF(0xbec);
 }
 if ((self->source->get(0)->flags & 0x1f) == 4) status = 1;
 velocity.m_x = direction * (speed * (float)cos(angle));
 velocity.m_y = speed * (float)sin(angle);
 u32 use = 0;
 if (situation == 0) {
  GroundView* ground = reinterpret_cast<GroundView*>(&self->acc->getGroundModule());
  if (!ground->hasContact(0)) use = 1;
  else {
   __memcpy(&normal, &velocity, sizeof(normal));
   fn_41_1068C(self, ground, &normal);
   SpeedWords raw = ground->getContactNormal(8, 0);
   __memcpy(&contactNormal, &raw, sizeof(contactNormal));
   if (vecAngle(&contactNormal, &normal) < 1.5707963705062866f) use = 1;
  }
 } else use = 1;
 power = fn_41_103FC(self, kinetic, posture, speed, &velocity, reflect, kind, direction, 1);
 if (reflect == 1) {
  static_cast<Team*>(self->acc->m_enumerationStart->m_teamModule)->setOwner(self->owner);
  Fighter* fighter = g_ftManager->getFighter(g_ftManager->getEntryId(0), -1);
  if (fighter) {
   Team* team = static_cast<Team*>(self->acc->m_enumerationStart->m_teamModule);
   team->setTeam(soExternalValueAccesser::getTeamNo(fighter), true);
  } else {
   fighter = g_ftManager->getFighter(g_ftManager->getEntryId(1), -1);
   if (fighter) {
    Team* team = static_cast<Team*>(self->acc->m_enumerationStart->m_teamModule);
    team->setTeam(soExternalValueAccesser::getTeamNo(fighter), true);
   } else static_cast<Team*>(self->acc->m_enumerationStart->m_teamModule)->setTeam(hit->team, true);
  }
  work->onFlag(0x12000001);
  work->setFloat(-1.0f, 0x1100000f);
  void* effect = fn_41_159AC(kinetic, 6);
  if (power > 90.0f && power < 270.0f) fn_41_1AE94(effect);
 }
 work->onFlag(0x22000002);
 work->offFlag(0x12000004);
 work->setInt(frames2, 0x10000000);
 work->setInt(kind2, 0x1000000a);
 work->setFloat(hit->damage, 0x11000009);
 if (frames2 > 0) work->offFlag(0x22000000);
 else work->onFlag(0x22000000);
 if (use == 1) work->onFlag(0x22000001);
 else work->offFlag(0x22000001);
 work->setInt(frames, 0x10000002);
 int state = -1;
 if (!status) state = self->acc->getSituationModule().getKind() == 0;
 work->setInt(state, 0x10000003);
 work->setInt(fn_41_101E0(self, kind2, duration, use), 0x1000000b);
 fn_41_10008(self, hit, kind2, reflect, flag15);
}

static inline float clampCosine(float cosine, float upper, float lower) {
 float clamped = nw4r::math::FSelect(cosine - lower, cosine, lower);
 return nw4r::math::FSelect(clamped - upper, upper, clamped);
}
