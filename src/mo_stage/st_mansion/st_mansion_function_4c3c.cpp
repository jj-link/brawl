#pragma force_active on
struct Vec3 {
    float v[3];
};

extern "C" short fn_47_4C3C(const Vec3 *p)
{
    return (short)((int)(*(const unsigned int *)&p->v[2]) >> 30);
}