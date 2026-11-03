#pragma always_inline on
#include <so/stageobject.h>
#include <so/so_module_accesser.h>
#include <mt/mt_vector.h>
#include <nw4r/math/math_arithmetic.h>
#include <math.h>
#pragma force_active on
#pragma scheduling off
#pragma optimize_for_size on
#pragma inline all
class Class_81B8 {
public:
virtual void fn_102_61A8();
virtual s8 fn_102_1B234();
virtual s8 fn_102_1BE5C();
virtual void fn_102_1BE58();
virtual void fn_102_1BE54();
virtual void fn_102_1BE50();
virtual void fn_102_1BE48();
virtual void fn_102_1BE90();
virtual void fn_102_1BE88();
virtual void fn_102_1BE80();
};
extern "C" {
extern const float lbl_102_rodata_78[];
extern const unsigned char lbl_102_data_83E8[], lbl_102_data_14F4[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_1DA24C(void*, void*, void*);
float fn_102_1B8F4(float, float);
float fn_8003DDD0(const Vec2f*, const Vec2f*);
Vec2f* fn_102_C5AC(Vec2f*, float, float);
void fn_102_1B788(void*, const Vec2f*);
}
extern "C" int fn_102_1B918(StageObject* self, Class_81B8* cmd, soModuleAccesser* accesser) {
const float* c = lbl_102_rodata_78;
if (fn_27_1DA24C(self, cmd, accesser)) return 1;
s8 group = cmd->fn_102_1B234();
if (!self->isObserv(group)) return 0;
if (cmd->fn_102_1BE5C() <= -1 || cmd->fn_102_1BE5C() >= 11) return 0;
switch (cmd->fn_102_1BE5C()) {
case 6: {
soKineticEnergy* energy = static_cast<soKineticEnergy*>(__dynamic_cast(accesser->getKineticModule().getEnergy(0), 0, lbl_102_data_83E8, lbl_102_data_14F4, 1));
Vec2f speed;
Vec2f::copy(speed, energy->getSpeed());
float sq = speed.lengthSq();
float length;
if (static_cast<float>(static_cast<double>(nw4r::math::FAbs(sq))) <= c[7]) length = c[2];
else length = sq * rsqrtf(sq);
Vec2f normal;
Vec2f::copy(normal, accesser->getGroundModule().getTouchNormal(static_cast<grCollStatus::TouchMask>(0xff), 0));
float diff = fn_102_1B8F4(normal.m_x, normal.m_y);
float angle = fn_102_1B8F4(speed.m_x, speed.m_y);
diff = angle - diff;
accesser->getPostureModule().getLr();
while (diff > c[9]) diff -= c[8];
while (diff < c[10]) diff += c[8];
float adjustment = c[2];
if (adjustment != diff) {
float theta = fn_8003DDD0(&normal, &speed);
float scale = static_cast<float>(static_cast<double>(nw4r::math::FAbs(theta)));
if (scale < c[11]) scale = c[12] * (scale / c[9]);
else scale = c[13] * (scale / c[9]);
if (diff < c[2]) scale = -scale;
adjustment = theta * scale;
}
angle -= adjustment;
while (angle < c[10]) angle += c[8];
while (angle > c[9]) angle -= c[8];
diff = static_cast<float>(cos(angle));
float sine = static_cast<float>(sin(angle));
fn_102_1B788(energy, fn_102_C5AC(&Vec2f(), length * sine, length * diff));
return 1;
}
}
return 0;
}
