#pragma force_active on
struct Entry {
    void* m_0;
    int m_4;
    int m_8;
};

extern Entry lbl_27_bss_3210[];

extern "C" {
void* fn_27_14925C(int p0, int p1) {
    char* base = (char*)lbl_27_bss_3210[p1].m_0;
    return *(void**)(base + 0xb4);
}
}
