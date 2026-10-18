#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct FtFoxWork {
    u8 pad[0xc];
    s32* arr;
};

extern "C" void fn_97_B478(FtFoxWork* work, s32 value, u32 index)
{
    work->arr[index] += value;
}
