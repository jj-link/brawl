#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct FnCD44Work {
    u8 pad[0xc];
    u32* m_counts;
};

extern "C" u32 fn_113_CD44(FnCD44Work* work, u32 index) {
    return work->m_counts[index]++;
}
