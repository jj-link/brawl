#pragma force_active on
struct Data {
    char pad[0x188];
    int value;
    float amount;
};

extern "C" void fn_60_6180(Data* data, int* value, float* amount) {
    *value = data->value;
    *amount = data->amount;
}
