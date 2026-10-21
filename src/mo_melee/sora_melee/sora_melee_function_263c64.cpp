#include <types.h>
#pragma force_active on

class YakuB {
public:
    virtual void b0(void);
    virtual void b1(void);
    virtual void b2(void);
    virtual void b3(void);
    virtual void b4(void);
    virtual void b5(void);
    virtual void b6(int a, int b);
};

class YakuC {
public:
    virtual void c0(void); virtual void c1(void); virtual void c2(void); virtual void c3(void);
    virtual void c4(void); virtual void c5(void); virtual void c6(void); virtual void c7(void);
    virtual void c8(void); virtual void c9(void); virtual void c10(void); virtual void c11(void);
    virtual void c12(void); virtual void c13(void); virtual void c14(void); virtual void c15(void);
    virtual void c16(void); virtual void c17(void); virtual void c18(void); virtual void c19(void);
    virtual void c20(void); virtual void c21(void); virtual void c22(void); virtual void c23(void);
    virtual void c24(void); virtual void c25(void); virtual void c26(void); virtual void c27(void);
    virtual void c28(void); virtual void c29(void); virtual void c30(void); virtual void c31(void);
    virtual void c32(void); virtual void c33(void); virtual void c34(void); virtual void c35(void);
    virtual void c36(void); virtual void c37(void); virtual void c38(void); virtual void c39(void);
    virtual void c40(void);
    virtual void c41(u32 idx);
};

class YakuA {
public:
    char pad0[0x14];
    YakuB* m_b;
    char pad1[0x8];
    YakuC* m_c;
};

class YakuD {
public:
    u32 count;
};

class Yakumono {
public:
    char pad0[0x180];
    YakuA* m_a;
    char pad1[0x4];
    YakuD* m_d;
    void setSituationKind(int kind);
};

void Yakumono::setSituationKind(int kind) {
    m_a->m_b->b6(kind, 1);
    if (kind == 7) {
        for (u32 i = 0; i < m_d->count; i++) {
            m_a->m_c->c41(i);
        }
    }
}
