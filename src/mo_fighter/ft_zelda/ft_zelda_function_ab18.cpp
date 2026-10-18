#pragma force_active on
typedef struct FtWork {
    char pad[0xc];
    int *values;
} FtWork;

extern "C" void fn_104_AB18(FtWork *work, int value, unsigned int index)
{
    work->values[index] -= value;
}
