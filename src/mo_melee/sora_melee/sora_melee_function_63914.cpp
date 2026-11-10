#pragma force_active on
#include <so/so_value_accesser.h>
extern "C" int fn_27_68140(float, float, float, float, float);
extern const float lbl_27_rodata_8E8;
struct Data {
    unsigned char pad00[8];
    float power;
    float damage;
    unsigned char pad10[0x54];
    float multiplier;
    unsigned char pad68[4];
    unsigned int kind;
    unsigned char pad70[4];
    unsigned int flags;
};
inline int calc(soModuleAccesser* self, unsigned int kind, int mode, float power, float scaled, float factor)
{
    if (kind == 0x14 && mode == 0) {
        float a = soValueAccesser::getConstantFloat(self, 0x7ED, 0);
        float b = soValueAccesser::getConstantFloat(self, 0x7EE, 0);
        float c = factor * (scaled * b);
        float d = soValueAccesser::getConstantFloat(self, 0x7EF, 0);
        float e = soValueAccesser::getConstantFloat(self, 0x7E3, 0);
        return fn_27_68140(power, e, d, c, a);
    }
    if (kind == 3) {
        float a = soValueAccesser::getConstantFloat(self, 0x7E2, 0);
        float b = soValueAccesser::getConstantFloat(self, 0x7EC, 0);
        float c = scaled * b;
        float d = soValueAccesser::getConstantFloat(self, 0x7E4, 0);
        float e = soValueAccesser::getConstantFloat(self, 0x7E3, 0);
        return fn_27_68140(power, e, d, c, a);
    }
    float a = soValueAccesser::getConstantFloat(self, 0x7E2, 0);
    float b = soValueAccesser::getConstantFloat(self, 0x7E4, 0);
    float c = soValueAccesser::getConstantFloat(self, 0x7E3, 0);
    return fn_27_68140(power, c, b, scaled, a);
}
extern "C" int fn_27_63914(soModuleAccesser* accesser, const Data* obj, int flag, float scale)
{
    float damage = obj->damage;
    if (damage > lbl_27_rodata_8E8) {
        float power = obj->power;
        if (!((obj->flags >> 7) & 1)) {
            unsigned int kind = obj->kind & 0x1F;
            float scaled = scale * obj->multiplier;
            return calc(accesser, kind, flag, power, scaled, damage);
        }
        return 0;
    }
    return 0;
}
