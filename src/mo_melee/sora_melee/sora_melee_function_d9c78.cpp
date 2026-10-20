#pragma force_active on
struct Data {
    int unk0;
    int unk4;
    int flags;
    int values[3];
};

extern "C" int* fn_27_D9C78(Data* data, int index)
{
    int position = (data->flags >> 29) + index;
    if (position >= 3)
        position -= 3;
    return &data->values[position];
}
