#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Entry {
    u32 m_0;
    u32* m_4;
    u32 m_8;
};

extern Entry lbl_27_bss_3210[];

extern "C" {
u32 fn_27_145514(u32, s32 p2, s32 p3)
{
    return lbl_27_bss_3210[p2].m_4[p3];
}
}
