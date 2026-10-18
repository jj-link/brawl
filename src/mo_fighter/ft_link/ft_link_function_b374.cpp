#pragma force_active on
typedef struct WorkHeader {
    char pad[0xc];
    int *intWorks;
} WorkHeader;

extern "C" void fn_93_B374(WorkHeader *work, int value, unsigned int index)
{
    work->intWorks[index] -= value;
}
