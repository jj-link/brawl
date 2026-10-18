#pragma force_active on
struct Entry {
    char* m_0;
    int m_4;
    int m_8;
};

extern Entry lbl_27_bss_3210[];

extern "C" void* fn_27_149274(void* unused, int p1) {
    return *(void**)(lbl_27_bss_3210[p1].m_0 + 0xB8);
}
