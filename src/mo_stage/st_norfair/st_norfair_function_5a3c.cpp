#pragma force_active on
struct Fn54_5A3C
{
    unsigned int reserved[2];
    unsigned int flags;
};

extern "C" int fn_54_5A3C(Fn54_5A3C *arg)
{
    return (arg->flags >> 22) & 1;
}
