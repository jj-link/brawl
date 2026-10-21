#pragma force_active on
struct fnObj {
    virtual void v0();
    virtual void v1(int);
    virtual void v2();
    virtual void v3();

    float m_04;
    float m_08;
    float m_0c;
    float m_10;
    float m_14;
};

extern "C" const float lbl_27_rodata_5FB0;

extern "C" void fn_27_2BEEAC(fnObj* p, int arg, float scale) {
    const float one = lbl_27_rodata_5FB0;
    if (one != scale) {
        float a = p->m_0c;
        float b = p->m_14;
        p->m_0c = a * scale;
        p->m_14 = b * scale;
        p->v1(arg);
        p->m_0c = a;
        p->m_14 = b;
    } else {
        p->v1(arg);
    }
}
