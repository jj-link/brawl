#pragma force_active on
struct Entry {
    void* m_0;
    unsigned int m_4;
    unsigned int m_8;
};

struct Obj {
    char pad[0x90];
    void* m_90;
};

extern Entry lbl_27_bss_3210[];

extern "C" {
void* fn_27_147D34(void* self, int p1) {
    return ((Obj*)lbl_27_bss_3210[p1].m_0)->m_90;
}
}
