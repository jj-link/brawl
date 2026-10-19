#pragma force_active on
typedef unsigned int u32;

struct Fn11099F0Data
{
    unsigned char pad[0x0C];
    void **entries;
};

extern "C" void *fn_110_99F0(Fn11099F0Data *data, u32 index)
{
    return data->entries[index];
}
