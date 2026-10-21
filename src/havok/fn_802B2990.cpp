#pragma force_active on
extern "C" void fn_8031830C(void* a, int b);

struct Obj {
    virtual void v0(int);
    int unk4;
    int unk8;
};

extern "C" void fn_802B2990(Obj* self) {
    fn_8031830C((char*)self + 0x30, self->unk8);
    if (self != 0) {
        self->v0(1);
    }
}
