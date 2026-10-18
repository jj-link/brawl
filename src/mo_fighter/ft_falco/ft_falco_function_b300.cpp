#pragma force_active on
typedef unsigned int u32;

struct FtWork {
    int m_pad[3];
    void** m_table;
};

extern "C" void fn_108_B300(FtWork* work, void* value, u32 index) {
    work->m_table[index] = value;
}
