#pragma force_active on
extern "C" void fn_27_AB6C8();

struct fn_27_Inner {
    virtual void vf0();
    virtual void vf1(int idx);
};

struct fn_27_Outer {
    int unk0;
    fn_27_Inner* unk4;
    int unk8;
};

extern "C" void fn_27_76C4C(fn_27_Outer* self, int idx) {
    fn_27_Inner* inner = self->unk4;
    int n = (idx <= -1) ? self->unk8 : idx;
    inner->vf1(n);
    fn_27_AB6C8();
}
