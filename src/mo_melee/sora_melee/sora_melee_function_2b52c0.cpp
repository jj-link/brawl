#pragma force_active on
struct Data {
    unsigned int pad[2];
    unsigned long long value;
};

extern "C" unsigned long long fn_27_2B52C0(const Data* data) {
    return data->value;
}
