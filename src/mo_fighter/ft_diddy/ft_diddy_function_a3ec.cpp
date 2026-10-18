#pragma force_active on
typedef struct
{
    char pad[0xC];
    int *ints;
} FtWork;

extern "C" int fn_115_A3EC(FtWork *work, unsigned int index)
{
    return work->ints[index]--;
}
