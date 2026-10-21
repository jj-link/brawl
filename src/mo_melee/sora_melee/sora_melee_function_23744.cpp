#pragma force_active on
class VBase {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual float getValue();
};
struct Inner { char pad[0x54]; VBase* m_54; };
struct Mid { char pad[0xd8]; Inner* m_d8; };
struct Outer { char pad[8]; Mid* m_08; char pad2[0x3c-0xc]; float m_3c; char pad3[0x68-0x40]; float m_68; };

extern const float lbl_27_rodata_38C;

extern "C" float fn_27_23744(const Outer* p) {
    float v = p->m_08->m_d8->m_54->getValue();
    if (lbl_27_rodata_38C != v) {
        return p->m_3c * v;
    }
    return p->m_3c * p->m_68;
}
