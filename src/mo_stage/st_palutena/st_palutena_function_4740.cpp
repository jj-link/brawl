#pragma force_active on
extern "C" const float lbl_67_rodata_10;

struct FloatPair {
    float first;
    float second;
};

extern "C" FloatPair fn_67_4740() {
    FloatPair result;
    result.first = lbl_67_rodata_10;
    result.second = lbl_67_rodata_10;
    return result;
}
