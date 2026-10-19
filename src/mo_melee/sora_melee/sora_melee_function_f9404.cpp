#pragma force_active on
typedef unsigned int u32;

class fn_27_Base {
public:
    virtual void f0();
    virtual fn_27_Base* f1(u32 v);
    u32 m_word;
};

extern "C" {
void fn_27_F9404(fn_27_Base* self, fn_27_Base* other, u32 v) {
    u32* dst = (u32*)self->f1(v);
    *dst = *(u32*)other;
}
}
