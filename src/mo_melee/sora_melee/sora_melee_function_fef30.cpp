#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" int fn_27_FEF30(const Data* data) {
    return (int)((data->flags << 2) & 0xE0000000u) >> 30;
}
