#pragma force_active on
extern "C" const float lbl_121_rodata_78;

struct ToonLinkScalarPair {
    unsigned char prefix[8];
    float first;
    float second;
};

extern "C" void fn_121_14684(ToonLinkScalarPair* object) {
    object->first = object->second = lbl_121_rodata_78;
}
