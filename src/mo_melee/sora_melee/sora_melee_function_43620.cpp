#pragma force_active on
struct fnInner {
    virtual void v0();
    virtual void* v1();
};

struct fnOuter {
    char pad[0x30];
    int unk30;
    char pad2[0x58 - 0x34];
    fnInner* unk58;
};

extern "C" void fn_27_41E20(void* p, int a);

extern "C" void fn_27_43620(fnOuter* self) {
    fn_27_41E20(self->unk58->v1(), self->unk30);
}
