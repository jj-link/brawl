#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" void fn_27_CBA5C(Data* data)
{
    data->flags &= 0xFFF7FFFF;
}
