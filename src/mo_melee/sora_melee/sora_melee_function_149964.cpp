#pragma force_active on

typedef int s32;
typedef unsigned int u32;

struct Entry {
    s32 m_0;
    s32 m_4;
    s32 m_8;
};

extern Entry lbl_27_bss_3210[];

extern "C" s32 fn_27_149964() {
    u32 base = (u32)lbl_27_bss_3210;
    u32 ptr = *(u32 *)(base + 0xF0);
    return *(s32 *)(ptr + 0x8C);
}
