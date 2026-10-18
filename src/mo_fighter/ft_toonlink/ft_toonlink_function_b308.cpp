#pragma force_active on
struct FtWork {
    char pad[0xc];
    int *m_counts;
};

extern "C" {
void fn_121_B308(FtWork *work, unsigned int index)
{
    work->m_counts[index]--;
}
}
