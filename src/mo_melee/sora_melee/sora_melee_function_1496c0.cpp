#pragma force_active on
typedef int s32;

struct Obj {
    char pad[0x94];
    s32 m_94;
};

struct Entry {
    Obj* m_0;
    s32 m_4;
    s32 m_8;
};

extern Entry lbl_27_bss_3210[];

extern "C" {
s32 fn_27_1496C0(s32 p0, s32 p1) {
    return lbl_27_bss_3210[p1].m_0->m_94;
}
}
