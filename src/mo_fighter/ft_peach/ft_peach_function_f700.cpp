#pragma force_active on
struct Data {
    unsigned int pad[2];
    unsigned int flags;
};

extern "C" int fn_103_F700(const Data* data) {
    return (int)((data->flags << 6) & 0xFE000000u) >> 26;
}
