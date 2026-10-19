#pragma force_active on
extern const float lbl_98_rodata_A8;

struct PikachuFloatPair {
    float first;
    float second;
};

extern "C" PikachuFloatPair fn_98_14F58() {
    PikachuFloatPair pair;
    pair.first = lbl_98_rodata_A8;
    pair.second = lbl_98_rodata_A8;
    return pair;
}
