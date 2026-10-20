#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned long long value;
};

extern "C" unsigned long long fn_98_C548(const Data* data) {
    return data->value;
}
