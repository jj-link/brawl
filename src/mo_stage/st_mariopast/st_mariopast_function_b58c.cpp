#pragma force_active on
struct Data {
    int padding[2];
    int value;
};

extern "C" int fn_48_B58C(const Data* data) {
    return data->value >> 23;
}
