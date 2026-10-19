#pragma force_active on
struct soRet {
    float m_value;
};

struct soIface {
    virtual void f0();
    virtual soRet* f1();
};

struct soHolder {
    unsigned char m_pad[0x40];
    soIface* m_iface;
};

extern "C" {
float fn_27_5F2A4(soHolder* p) {
    return p->m_iface->f1()->m_value;
}
}
