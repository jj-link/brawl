#pragma force_active on
struct FtWolfWork {
    char pad[0xc];
    int *m_intWorks;
};

extern "C" void fn_125_B390(FtWolfWork *work, int value, unsigned int index)
{
    work->m_intWorks[index] += value;
}
