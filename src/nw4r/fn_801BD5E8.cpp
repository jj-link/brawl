#pragma force_active on
struct SoObjBD5 {
    unsigned int m_pad[3];
    unsigned int m_value;
};

extern "C" {
bool fn_801BD5E8(SoObjBD5* p) {
    return p->m_value != 0;
}
}
