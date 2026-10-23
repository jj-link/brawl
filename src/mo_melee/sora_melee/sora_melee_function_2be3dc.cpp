#pragma force_active on

typedef unsigned int u32;

extern "C" const float lbl_27_rodata_5FB0;

struct Vec2 {
    float x, y;
};

class fnObj {
public:
    virtual void v0();
    virtual void v3(int);

    u32 pad4[3];
    float m_10;
    float m_14;
    u32 pad18;
    u32 pad1C;
    float m_20;
    float m_24;
};

extern "C" void fn_27_2BE3DC(fnObj* p, int arg, float scale) {
    const float one = lbl_27_rodata_5FB0;
    if (one != scale) {
        Vec2 v1 = *(Vec2*)&p->m_10;
        Vec2 v2 = *(Vec2*)&p->m_20;
        p->m_10 *= scale;
        p->m_14 *= scale;
        p->m_20 *= scale;
        p->m_24 *= scale;
        p->v3(arg);
        p->m_10 = v1.x;
        p->m_14 = v1.y;
        p->m_20 = v2.x;
        p->m_24 = v2.y;
    } else {
        p->v3(arg);
    }
}
