#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct FtDonkeyWork {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    s32 *values;
};

extern "C" void fn_92_9B50(FtDonkeyWork *work, s32 value, u32 index)
{
    work->values[index] += value;
}
