#pragma force_active on
extern "C" {
extern const float lbl_27_rodata_B70;

struct FloatPair {
    float first;
    float second;
};

unsigned long long fn_27_7EBF4()
{
    FloatPair values;
    values.first = lbl_27_rodata_B70;
    values.second = lbl_27_rodata_B70;

    return *reinterpret_cast<unsigned long long*>(&values);
}
}
