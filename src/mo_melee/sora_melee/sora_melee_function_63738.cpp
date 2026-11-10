#include <so/so_value_accesser.h>
#pragma force_active on
#pragma scheduling on

struct Data {
    unsigned char pad00[0x28];
    float value28;
    unsigned char pad2C[4];
    unsigned int value30;
    unsigned char pad34[4];
    unsigned int : 24;
    unsigned int flag38 : 1;
};

extern "C" int fn_27_68140(float, float, float, float, float);

inline int calc(soModuleAccesser* self, unsigned int kind, int mode,
                float power, float scaled, float factor)
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

extern "C" int fn_27_63738(soModuleAccesser* self, const Data* data, int mode,
                           unsigned int unused, float power, float scale,
                           float factor)
{
    if (!data->flag38) {
        float scaled = scale * data->value28;
        unsigned int kind = data->value30 & 0x1F;
        return calc(self, kind, mode, power, scaled, factor);
    }
    return 0;
}