#pragma force_active on
extern "C" const float lbl_119_rodata_90;

struct FtIkeScalarPair {
    unsigned char prefix[8];
    float first;
    float second;
};

extern "C" void fn_119_13428(FtIkeScalarPair* object) {
    object->first = object->second = lbl_119_rodata_90;
}
