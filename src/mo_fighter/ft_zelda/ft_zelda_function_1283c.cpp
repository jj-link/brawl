#pragma force_active on
extern "C" const float lbl_104_rodata_90;

struct FtScalarPair {
    unsigned char prefix[8];
    float first;
    float second;
};

extern "C" void fn_104_1283C(FtScalarPair* object) {
    object->first = object->second = lbl_104_rodata_90;
}
