#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
struct GanonEnergy : soKineticEnergy {
    char pad[0x10];
    Vec2f limit;
    char pad2[0x1c];
    float multiplier;
};
extern "C" {
extern const char lbl_109_data_657C[], lbl_109_data_1670[];
extern const float lbl_109_rodata_2C;
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
inline void addSpeed(Vec2f& a, const Vec2f& b) {
    a.m_x += b.m_x;
    a.m_y += b.m_y;
}
extern "C" void fn_109_E470(GanonEnergy* self, soModuleAccesser* accesser) {
    switch (accesser->getKineticModule().getKineticType()) {
    case 0x64: {
        Vec2f limit;
        Vec2f::copy(limit, self->limit);
        Vec2f speed;
        Vec2f::copy(speed, self->getSpeed());
        soKineticEnergy* stop = static_cast<soKineticEnergy*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(0), 0,
            lbl_109_data_657C, lbl_109_data_1670, 1));
        addSpeed(speed, stop->getSpeed());
        limit.m_x = soValueAccesser::getConstantFloat(accesser, 0xbd5, 0);
        float multiplier = lbl_109_rodata_2C;
        float factor = soValueAccesser::getConstantFloat(accesser, 0xfae, 0);
        if ((float)(double)nw4r::math::FAbs(speed.m_x) > limit.m_x * factor) {
            limit.m_x *= factor;
            multiplier = soValueAccesser::getConstantFloat(accesser, 0xfad, 0);
        }
        self->limit = limit;
        self->multiplier = multiplier;
        break;
    }
    }
    self->updateEnergy(accesser);
}