#pragma force_active on
extern char lbl_41_data_2618[];

struct emObjBase {
    void* m_vtbl;
    unsigned char m_flag;
};

extern "C" void fn_41_137C0(emObjBase* p) {
    p->m_flag = 0;
    p->m_vtbl = lbl_41_data_2618;
}
