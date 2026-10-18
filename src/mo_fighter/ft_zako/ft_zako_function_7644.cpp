#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct FtZakoWork {
    char pad[0xc];
    s32 *arr;
};

extern "C" void fn_126_7644(FtZakoWork *work, s32 value, u32 index)
{
    work->arr[index] *= value;
}
