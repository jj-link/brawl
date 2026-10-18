#pragma force_active on
extern "C" const float lbl_95_rodata_128;

struct FtYoshiPair {
    unsigned char pad[8];
    float first;
    float second;
};

extern "C" void fn_95_17478(FtYoshiPair* object) {
    float v = lbl_95_rodata_128;
    object->second = v;
    object->first = v;
}
