#pragma force_active on
extern "C" const float lbl_112_rodata_34;

struct FtPitPair {
    unsigned char prefix[8];
    float first;
    float second;
};

extern "C" void fn_112_112AC(FtPitPair* object) {
    object->first = object->second = lbl_112_rodata_34;
}
