#pragma force_active on
struct PeachData {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" int fn_103_F764(const PeachData* data) {
    return static_cast<int>((data->flags << 12) & 0xFE000000u) >> 26;
}
