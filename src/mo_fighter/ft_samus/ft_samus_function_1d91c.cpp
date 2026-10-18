#pragma force_active on
extern "C" const float lbl_94_rodata_88;

struct FtSamusScalarPair {
    unsigned char prefix[8];
    float first;
    float second;
};

extern "C" void fn_94_1D91C(FtSamusScalarPair* object) {
    object->first = object->second = lbl_94_rodata_88;
}
