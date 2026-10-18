#pragma force_active on
extern "C" const float lbl_123_rodata_68;

struct FtSonicScalarPair {
    int pad[2];
    float first;
    float second;
};

extern "C" void fn_123_13F2C(FtSonicScalarPair* object) {
    object->first = object->second = lbl_123_rodata_68;
}
