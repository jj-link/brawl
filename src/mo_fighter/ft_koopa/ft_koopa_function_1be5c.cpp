#pragma force_active on
extern "C" const float lbl_102_rodata_78;

struct KoopaFloatPair {
    unsigned char prefix[8];
    float first;
    float second;
};

extern "C" void fn_102_1BE5C(KoopaFloatPair* object) {
    object->first = object->second = lbl_102_rodata_78;
}
