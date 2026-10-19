#pragma force_active on
struct Unk44 {
    unsigned char pad[0x2c];
    float m_val;
};

struct Holder {
    unsigned char pad[0x44];
    Unk44* m_p;
};

struct Global {
    unsigned char pad[0x58];
    float m_lo;
    float m_hi;
};

extern Global* lbl_805A0360;

extern "C" int fn_27_110B9C(Holder* self, float x) {
    Unk44* p = self->m_p;
    Global* g = lbl_805A0360;
    float off = p->m_val;
    if (x < g->m_lo + off) {
        goto ret1;
    }
    if (!(x > g->m_hi - off)) {
        goto ret0;
    }
ret1:
    return 1;
ret0:
    return 0;
}
