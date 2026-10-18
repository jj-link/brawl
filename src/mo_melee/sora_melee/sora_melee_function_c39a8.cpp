#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_27_C3DCC();

class Inner {
public:
    virtual void v0();
    virtual void v3(int idx);
    virtual void v4();
    virtual int v5();
};

struct Outer {
    u32 pad[3];
    Inner* m_inner;
};

extern "C" void fn_27_C39A8(Outer* self) {
    int count = self->m_inner->v5();
    for (int i = 0; i < count; i++) {
        self->m_inner->v3(i);
        fn_27_C3DCC();
    }
}
