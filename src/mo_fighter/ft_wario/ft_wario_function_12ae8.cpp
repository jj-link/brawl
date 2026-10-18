#pragma force_active on
extern "C" const float lbl_110_rodata_80;

struct FtWarioPair {
    unsigned char prefix[8];
    float first;
    float second;
};

extern "C" void fn_110_12AE8(FtWarioPair* object) {
    object->first = object->second = lbl_110_rodata_80;
}
