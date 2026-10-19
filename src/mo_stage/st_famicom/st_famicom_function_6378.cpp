#pragma force_active on
struct Fn68_6378Data
{
    unsigned int reserved[2];
    unsigned int flags;
};

extern "C" int fn_68_6378(void *arg)
{
    return (((Fn68_6378Data *)arg)->flags >> 25) & 1;
}
