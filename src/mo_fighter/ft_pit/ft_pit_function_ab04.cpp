#pragma force_active on
typedef unsigned int u32;

struct FtPitWork {
    char pad[0xc];
    u32 *values;
};

extern "C" void fn_112_AB04(FtPitWork *work, u32 value, u32 index)
{
    work->values[index] -= value;
}
