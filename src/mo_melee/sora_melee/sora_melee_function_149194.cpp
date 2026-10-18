#pragma force_active on
typedef int s32;

struct Sora149Inner {
    char pad[0xa8];
    s32 m_a8;
};

struct Sora149Entry {
    Sora149Inner* m_0;
    s32 m_4;
    s32 m_8;
};

extern Sora149Entry lbl_27_bss_3210[];

extern "C" {
s32 fn_27_149194(s32 p0, s32 p1) {
    return lbl_27_bss_3210[p1].m_0->m_a8;
}
}
