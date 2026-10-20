#pragma force_active on
extern "C" const float lbl_125_rodata_18;

struct WolfScalarPair {
    unsigned char prefix[8];
    float first;
    float second;
};

extern "C" void fn_125_10A38(WolfScalarPair* object) {
    object->first = object->second = lbl_125_rodata_18;
}
