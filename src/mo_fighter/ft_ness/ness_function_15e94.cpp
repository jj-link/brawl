#pragma force_active on
struct NessEnergyVec2 { float v[2]; float v2[2]; };

extern "C" float fn_101_15E94(NessEnergyVec2* speed)
{
    return speed->v2[0] * speed->v2[1];
}
