#pragma force_active on
typedef unsigned char u8;

struct Target {
    virtual void v0();
    virtual Target* v1();
    virtual void v2();
    virtual void v3();
    u8 pad[0x50 - 0x04];
    float m_50;
};

struct Outer {
    u8 pad[0x8];
    Target* m_target;
};

extern "C" {
void fn_27_379D4(Outer* p, float f) {
    p->m_target->v1()->m_50 = f;
}
}
