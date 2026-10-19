#pragma force_active on
struct SoraInner {
    virtual void* f0();
    virtual void* f1();
    virtual void* f2();
    virtual void* f3();
};

struct SoraOuter {
    char pad[0x30];
    SoraInner* unk30;
};

extern "C" void fn_27_A7770(void* self, unsigned char value);

extern "C" void fn_27_A4730(SoraOuter* self, void* unused, unsigned char value) {
    void* r = self->unk30->f1();
    fn_27_A7770(r, value);
}
