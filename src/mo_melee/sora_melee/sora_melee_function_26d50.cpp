#pragma force_active on
struct fnInner {
    virtual void v0();
    virtual fnInner* v1();
    void* m_04;
};

struct fnOuter {
    char pad[0x28];
    fnInner* m_28;
};

extern "C" {
void fn_80133F64(void* p);

void fn_27_26D50(fnOuter* self) {
    fnInner* r = self->m_28->v1();
    fn_80133F64(r->m_04);
}
}
