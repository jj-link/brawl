#pragma force_active on
struct PikminData {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" int fn_113_11E74(PikminData* data) {
    return static_cast<int>((data->flags << 4) & 0xE0000000u) >> 30;
}
