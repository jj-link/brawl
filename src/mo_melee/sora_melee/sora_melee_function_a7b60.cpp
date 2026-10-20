#pragma force_active on
struct SoObj {
    unsigned int m_pad[4];
    unsigned int m_value;
};

extern "C" {
bool fn_27_A7B60(SoObj* p) {
    return p->m_value != 0;
}
}
