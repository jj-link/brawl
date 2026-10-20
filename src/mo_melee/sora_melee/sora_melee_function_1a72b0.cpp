#pragma force_active on
struct Entry
{
    unsigned char bytes[16];
};

extern "C" void* fn_27_1A72B0(Entry* base, unsigned int index)
{
    return &base[index].bytes[12];
}
