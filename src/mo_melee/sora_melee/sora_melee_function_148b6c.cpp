#pragma force_active on
typedef int s32;

struct Entry {
    s32 m_0;
    s32 m_4;
    s32 m_8;
};

extern Entry lbl_27_bss_3210[];

extern "C" s32 fn_27_148B6C(void) {
    return *(s32*)((char*)*(s32*)((char*)lbl_27_bss_3210 + 0x30) + 0xA0);
}
