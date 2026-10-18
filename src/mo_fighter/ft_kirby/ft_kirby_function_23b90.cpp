#pragma force_active on
extern "C" const float lbl_96_rodata_528;

struct FtKirbyScalarPair {
    unsigned char prefix[8];
    float first;
    float second;
};

extern "C" void fn_96_23B90(FtKirbyScalarPair* object) {
    object->first = object->second = lbl_96_rodata_528;
}
