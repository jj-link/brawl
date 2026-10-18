#pragma force_active on
struct fnObj41 {
    void* m_vt;
    unsigned char m_flag;
    void* m_ptr;
};

extern "C" unsigned char lbl_41_data_6D9C[];

extern "C" {
void fn_41_34F10(fnObj41* p) {
    p->m_flag = 0;
    unsigned char* base = lbl_41_data_6D9C;
    p->m_ptr = base;
    p->m_vt = base + 8;
}
}
