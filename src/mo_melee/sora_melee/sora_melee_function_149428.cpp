#pragma force_active on

typedef int s32;

struct Entry {
    s32 m_0;
    s32 m_4[9];
};

extern Entry lbl_27_bss_3210[];

extern "C" s32 fn_27_149428() {
    return *(s32 *)((char *)lbl_27_bss_3210[0].m_4[8] + 0xB4);
}
