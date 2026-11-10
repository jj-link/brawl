#pragma force_active on
#pragma fp_contract on

class Inner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual float vf4();
};

struct Self {
    unsigned char pad0[0x14];
    Inner* m_inner;
    unsigned char pad1[0x8];
    float m_f20;
    float m_f24;
    float m_f28;
};

struct Arg {
    float m_x;
    float m_y;
    float m_z;
};

extern "C" float fn_802D0D10(Self* self, Arg* arg) {
    float r = self->m_inner->vf4();
    return r + (arg->m_z * self->m_f28 + (arg->m_x * self->m_f20 + arg->m_y * self->m_f24));
}
