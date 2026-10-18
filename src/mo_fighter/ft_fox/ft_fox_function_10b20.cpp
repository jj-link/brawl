#pragma force_active on
extern "C" const float lbl_97_rodata_18;

struct FoxScalarPair {
    unsigned char prefix[8];
    float first;
    float second;
};

extern "C" void fn_97_10B20(FoxScalarPair* object) {
    object->first = object->second = lbl_97_rodata_18;
}
