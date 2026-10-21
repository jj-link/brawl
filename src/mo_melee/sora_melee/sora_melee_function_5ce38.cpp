#pragma force_active on

struct SoObj {
    float m_f0;
    float m_f4;
    char pad[0x8C];
    float m_f94;
};

struct SoIface {
    virtual void v0();
    virtual SoObj* get(int index);
    virtual void v2();
    virtual int size();
};

struct SoHolder {
    char pad[0x40];
    SoIface* m_iface;
};

extern "C" float lbl_27_rodata_82C;

extern "C" void fn_27_5CE38(SoHolder* self, float fval) {
    int count = self->m_iface->size();
    float c = lbl_27_rodata_82C;
    for (int i = 0; i < count; i++) {
        SoObj* obj = self->m_iface->get(i);
        obj->m_f0 = fval;
        obj->m_f4 = c;
        obj->m_f94 = c;
    }
}
