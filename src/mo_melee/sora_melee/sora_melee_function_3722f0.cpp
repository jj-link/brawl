#pragma force_active on
struct soTable {
    unsigned char pad[0x18];
    int m_18;
    unsigned char pad2[0xC];
    int m_28[1];
};

extern "C" int fn_27_3722F0(soTable* t, unsigned int p1, int p2) {
    return t->m_28[p2 - t->m_18];
}
