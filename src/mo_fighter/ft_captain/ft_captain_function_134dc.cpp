#pragma force_active on
extern const float lbl_100_rodata_84;

struct FloatPair {
    float x;
    float y;
};

extern "C" FloatPair fn_100_134DC() {
    FloatPair p;
    p.x = lbl_100_rodata_84;
    p.y = lbl_100_rodata_84;
    return p;
}
