#pragma force_active on
extern "C" const float lbl_116_rodata_10;

struct FtPokeScalarPair {
    unsigned char prefix[8];
    float first;
    float second;
};

extern "C" void fn_116_11388(FtPokeScalarPair* object) {
    object->first = object->second = lbl_116_rodata_10;
}
