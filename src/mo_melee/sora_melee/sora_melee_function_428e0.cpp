#pragma force_active on
struct Data {
    char pad[0x1c];
    int values[2];
};

extern "C" int fn_27_428E0(const Data* data) {
    int result = 0;
    for (int i = 0; i < 2; ++i) {
        if (data->values[i] > result)
            result = data->values[i];
    }
    return result;
}
