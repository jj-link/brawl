#pragma force_active on
extern "C" const float lbl_122_rodata_98;

struct FtSnakeFloatPair {
    unsigned char prefix[8];
    float first;
    float second;
};

extern "C" void fn_122_18D50(FtSnakeFloatPair* object) {
    object->first = object->second = lbl_122_rodata_98;
}
