#pragma force_active on
struct HomerunData {
    unsigned char pad[0x188];
    int value;
    float amount;
};

extern "C" void fn_88_4158(HomerunData* data, int* value, float* amount)
{
    *value = data->value;
    *amount = data->amount;
}
