#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int value;
};

extern "C" int fn_70_922C(const Data* data) {
    return static_cast<int>((data->value << 4) & 0xE0000000u) >> 30;
}
