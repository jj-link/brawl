#pragma force_active on
struct BD50Data
{
    int value;
    float first;
    float second;
    unsigned char flags[4];
};

extern "C" void fn_105_BD50(
    BD50Data *data,
    int value,
    float first,
    float second,
    unsigned char flag0,
    unsigned char flag1,
    unsigned char flag2,
    unsigned char flag3)
{
    data->value = value;
    data->first = first;
    data->second = second;
    data->flags[0] = flag0;
    data->flags[1] = flag1;
    data->flags[2] = flag2;
    data->flags[3] = flag3;
}
