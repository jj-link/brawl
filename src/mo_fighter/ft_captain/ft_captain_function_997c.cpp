#pragma force_active on
struct FtCaptainCounter {
    char pad[0xc];
    int* m_counts;
};

extern "C" void fn_100_997C(FtCaptainCounter* self, int index) {
    int* counts = self->m_counts;
    counts[index]++;
}
