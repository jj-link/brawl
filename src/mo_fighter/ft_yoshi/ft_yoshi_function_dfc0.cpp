#pragma force_active on
struct YoshiData {
    unsigned char pad0x00[0x31];
    unsigned char flag31;
};

extern "C" void fn_95_DFC0(YoshiData* object) {
    object->flag31 = 1;
}
