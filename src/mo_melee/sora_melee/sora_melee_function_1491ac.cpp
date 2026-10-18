#pragma force_active on
typedef int s32;

struct Entry {
    void* m_0;
    s32 m_4;
    s32 m_8;
};

extern Entry lbl_27_bss_3210[];

extern "C" {
s32 fn_27_1491AC(s32 p0, s32 p1) {
    return *(s32*)((char*)lbl_27_bss_3210[p1].m_0 + 0xac);
}
}
