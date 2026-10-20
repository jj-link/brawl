#pragma force_active on
struct StageEntry
{
    unsigned char data[0x0C];
};

extern "C" StageEntry* fn_40_1E374(StageEntry* entries, int index)
{
    return (StageEntry*)((char*)entries + index * 0xA0 + 0x0C);
}
