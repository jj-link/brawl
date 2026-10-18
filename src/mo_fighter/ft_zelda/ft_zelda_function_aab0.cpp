#pragma force_active on
struct WorkHolder {
    char pad[0xc];
    int *intWorks;
};

extern "C" void fn_104_AAB0(WorkHolder *work, unsigned int index)
{
    work->intWorks[index]--;
}
