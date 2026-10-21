#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct soEntry {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
    u32 e;
};

class soInner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual u32 v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();

    u32 m_x;
    u32 m_y;
};

class soList {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();

    u32 m_a;
    u32 m_b;
    u32 m_c;
    soInner m_inner;
};

extern "C" soEntry* fn_27_D89E4(soList* self, s32 index) {
    self->v6();
    if (self->m_inner.v4() != 1 && index >= 0) {
        self->m_inner.v13();
    }
    return (soEntry*)((char*)self + index * 0x14 + 0x1C);
}
