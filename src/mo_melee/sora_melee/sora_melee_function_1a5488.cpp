#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern u8 lbl_27_data_34D98[];

struct soLinkWork {
    u8* m_0;
    u8* m_4;
    u32 m_8;
};

extern "C" {
void fn_27_1A5488(soLinkWork* p) {
    u32 v = p->m_8;
    u8* base = lbl_27_data_34D98;
    p->m_0 = base;
    p->m_4 = base + 0x48;
    p->m_8 = v & 0x7FFFF;
}
}
