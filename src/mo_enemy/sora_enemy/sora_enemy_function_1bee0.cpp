#pragma force_active on
struct UnkStruct
{
    int f00;
    float f04;
    float f08;
    float f0C;
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    float f24;
    float f28;
    char f2C;
    int f30;
    int f34;
    float f38;
    float f3C;
};

extern "C" void fn_41_1BEE0(UnkStruct* dst, const UnkStruct* src)
{
    dst->f00 = src->f00;
    dst->f04 = src->f04;
    dst->f08 = src->f08;
    dst->f0C = src->f0C;
    dst->f10 = src->f10;
    dst->f14 = src->f14;
    dst->f18 = src->f18;
    dst->f1C = src->f1C;
    dst->f20 = src->f20;
    dst->f24 = src->f24;
    dst->f28 = src->f28;
    dst->f2C = src->f2C;
    dst->f30 = src->f30;
    dst->f34 = src->f34;
    dst->f38 = src->f38;
    dst->f3C = src->f3C;
}
