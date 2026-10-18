#pragma force_active on
struct FtDonkeyWork {
    unsigned char pad[0xc];
    int* m_counts;
};

extern "C" void fn_92_9AD0(FtDonkeyWork* work, unsigned int index) {
    work->m_counts[index]--;
}
