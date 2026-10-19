#pragma force_active on
struct NessSpeed {
    float x;
    float y;
};

struct NessEnergy {
    unsigned char padding[8];
    NessSpeed speed;
};

extern "C" NessSpeed fn_101_FF38(const NessEnergy* energy)
{
    return energy->speed;
}
