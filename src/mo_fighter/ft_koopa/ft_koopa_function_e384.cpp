#pragma force_active on
extern "C" const float lbl_102_rodata_28;

struct KoopaData {
    int first;
    unsigned char flag;
    unsigned char padding[3];
    int second;
    int value0;
    int value1;
    int value2;
    float scalar;
    unsigned char last;
};

extern "C" void fn_102_E384(KoopaData* data, int first, int second, unsigned char last)
{
    data->first = first;
    data->flag = 0;
    data->second = second;
    data->value0 = -1;
    data->value1 = -1;
    data->value2 = -1;
    data->scalar = lbl_102_rodata_28;
    data->last = last;
}
