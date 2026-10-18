#pragma force_active on
extern "C" const float lbl_120_rodata_78;

struct FtRobotScalarPair {
    unsigned char prefix[8];
    float first;
    float second;
};

extern "C" void fn_120_13B3C(FtRobotScalarPair* object) {
    object->first = object->second = lbl_120_rodata_78;
}
