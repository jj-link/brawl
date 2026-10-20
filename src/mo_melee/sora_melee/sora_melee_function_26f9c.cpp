#pragma force_active on
extern "C" void* fn_27_2EE74(void* a, void* b, int c);

class SoraInner {
public:
    virtual void v0();
    virtual void* v1(void* p);
};

class SoraOuter {
public:
    char pad[0x28];
    SoraInner* m_inner;
};

extern "C" {
void fn_27_26F9C(SoraOuter* self, void* a, void* b) {
    void* r = self->m_inner->v1(b);
    fn_27_2EE74(r, a, 0);
}
}
