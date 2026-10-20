#pragma force_active on
struct JungleData {
    unsigned char padding[8];
    int value;
};

extern "C" int fn_51_D884(const JungleData* data) {
    return data->value >> 29;
}
