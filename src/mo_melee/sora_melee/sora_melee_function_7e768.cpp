#pragma force_active on
extern const float lbl_27_rodata_B70;

struct PairU32 {
    unsigned int a;
    unsigned int b;
};

union FloatPair {
    float f[2];
    struct PairU32 w;
};

extern "C" {
struct PairU32 fn_27_7E768(void)
{
    union FloatPair u;
    u.f[0] = lbl_27_rodata_B70;
    u.f[1] = lbl_27_rodata_B70;
    return u.w;
}
}
