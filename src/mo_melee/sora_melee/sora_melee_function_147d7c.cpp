#pragma force_active on
struct Inner {
    char pad[0xa0];
    void* m_a0;
};

struct Entry {
    Inner* m_0;
    unsigned int m_4;
    unsigned int m_8;
};

extern Entry lbl_27_bss_3210[];

extern "C" {
void* fn_27_147D7C(void* unused, int p1)
{
    return lbl_27_bss_3210[p1].m_0->m_a0;
}
}
