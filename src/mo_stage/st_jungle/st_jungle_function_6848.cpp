#pragma force_active on
struct JungleData {
    int padding[2];
    int value;
};

extern "C" int fn_51_6848(const JungleData* data) {
    return data->value >> 28;
}
