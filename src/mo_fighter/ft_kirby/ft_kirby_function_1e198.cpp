#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int value;
};

extern "C" int fn_96_1E198(const Data* data) {
    return static_cast<int>((data->value << 6) & 0xFE000000u) >> 26;
}
