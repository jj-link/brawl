#pragma force_active on
struct Inner {
    unsigned char pad[0x1c];
    unsigned char* m_1c;
};

struct Entry {
    Inner* m_0;
    unsigned int m_4[2];
};

extern Entry lbl_27_bss_3210[];

extern "C" {
unsigned char* fn_27_14554C(int unused, int kind, int idx);
}

extern "C" unsigned char* fn_27_14554C(int unused, int kind, int idx)
{
    if (kind == 0x10) {
        kind = 0xf;
    }
    return lbl_27_bss_3210[kind].m_0->m_1c + (idx << 3);
}
