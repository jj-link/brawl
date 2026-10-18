#pragma force_active on
typedef struct WorkBlock
{
    int pad0;
    int pad1;
    int pad2;
    int *values;
} WorkBlock;

extern "C" void fn_92_9B38(WorkBlock *work, int value, unsigned int index)
{
    work->values[index] -= value;
}
