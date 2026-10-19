#pragma force_active on
struct Data {
    int padding[2];
    int value;
};

extern "C" int fn_79_5734(const Data* data) {
    return data->value >> 26;
}
