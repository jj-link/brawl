#pragma force_active on
struct SoraInner {
    char pad[0x98];
    void* m_98;
};

struct SoraOuter {
    char pad[0x120];
    SoraInner* m_120;
};

extern SoraOuter lbl_27_bss_3210;

extern "C" void* fn_27_148C2C() {
    return lbl_27_bss_3210.m_120->m_98;
}
