#pragma force_active on
typedef struct Entry {
    void *m_0;
    int m_4;
    int m_8;
} Entry;

extern Entry lbl_27_bss_3210[];

extern "C" {
void *fn_27_148E3C(int p0, int p1)
{
    return *(void **)((char *)lbl_27_bss_3210[p1].m_0 + 0x98);
}
}
