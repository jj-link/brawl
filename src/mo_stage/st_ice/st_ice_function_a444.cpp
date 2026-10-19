#pragma force_active on
struct Data {
    unsigned char padding[8];
    int value;
};

extern "C" int fn_62_A444(const Data* data) {
    return data->value >> 30;
}
