#pragma force_active on
extern "C" const float lbl_113_rodata_5C;

struct FtPikminScalarPair {
    unsigned char prefix[8];
    float first;
    float second;
};

extern "C" void fn_113_1BDC0(FtPikminScalarPair* object) {
    float v = lbl_113_rodata_5C;
    object->second = v;
    object->first = v;
}
