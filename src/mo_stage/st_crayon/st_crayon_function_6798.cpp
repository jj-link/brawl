#pragma force_active on
struct CrayonData {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int flags;
};

extern "C" int fn_56_6798(const CrayonData* data) {
    return static_cast<int>((data->flags << 4) & 0xF8000000U) >> 28;
}
