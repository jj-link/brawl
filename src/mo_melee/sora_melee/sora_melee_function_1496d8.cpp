#pragma force_active on
struct Sub {
    char pad[0x98];
    void* m_98;
};

struct Entry {
    Sub* m_0;
    int m_4;
    int m_8;
};

extern Entry lbl_27_bss_3210[];

extern "C" {
void* fn_27_1496D8(void* unused, int p1)
{
    return lbl_27_bss_3210[p1].m_0->m_98;
}
}
