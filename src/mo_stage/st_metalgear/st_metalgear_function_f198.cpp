#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" unsigned int fn_71_F198(const Data* data)
{
    return (data->flags >> 25) & 1;
}
