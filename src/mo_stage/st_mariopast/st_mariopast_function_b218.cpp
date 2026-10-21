#pragma force_active on

struct Data {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" unsigned int fn_48_B218(const Data *arg)
{
    return (arg->flags >> 13) & 1;
}
