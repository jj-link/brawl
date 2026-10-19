#pragma force_active on
struct SamusWork
{
    unsigned char padding[0x0C];
    void** entries;
};

extern "C" void fn_94_B0B0(SamusWork* work, void* value, unsigned int index)
{
    work->entries[index] = value;
}
