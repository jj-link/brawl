#pragma force_active on
typedef unsigned int u32;

class R {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual u32 v4();
};

class T {
public:
    char pad[0x94];
    float m_94;
};

class S {
public:
    virtual void v0();
    virtual T* v1(void* p);
};

class Q {
public:
    char pad[0x68];
    R* m_68;
};

class P {
public:
    char pad[0xd8];
    Q* m_d8;
};

class Self {
public:
    char pad[0x3c];
    P* m_3c;
    S* m_40;
};

extern "C" {
void fn_27_5EC88(Self* self, float v, void* p) {
    if (self->m_3c->m_d8->m_68->v4() != 1) {
        T* t = self->m_40->v1(p);
        t->m_94 += v;
    }
}
}
