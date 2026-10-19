#pragma force_active on
struct Fn54_6508Data
{
    int field0;
    int field1;
    int field2;
};

extern "C" int fn_54_6508(Fn54_6508Data *data)
{
    return data->field2 >> 30;
}
