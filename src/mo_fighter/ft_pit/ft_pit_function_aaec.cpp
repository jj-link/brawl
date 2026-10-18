#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct FtPitWork {
    u8 pad[0xc];
    s32 *values;
};

extern "C" void fn_112_AAEC(FtPitWork *work, s32 value, u32 index)
{
    work->values[index] *= value;
}
