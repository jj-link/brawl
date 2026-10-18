#pragma force_active on
struct FloatHolder {
    char pad[0x14];
    float* values;
};

extern "C" void fn_98_A0A8(FloatHolder* obj, int index, float value)
{
    float* p = obj->values;
    p[index] = p[index] - value;
}
