#pragma force_active on
struct Work {
    unsigned char pad[12];
    int* m_ints;
};

extern "C" int fn_105_DE3C(const Work* work, unsigned index) {
    return work->m_ints[index];
}
