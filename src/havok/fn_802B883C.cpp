#pragma force_active on
extern "C" void fn_802FC6AC(void* p, int a, int b);

struct Obj {
    virtual void v0(int);
    int pad4;
    int f8;
    int fC;
};

extern "C" void fn_802B883C(Obj* self) {
    fn_802FC6AC((char*)self + 0x10, self->fC, self->f8);
    if (self != 0) {
        self->v0(1);
    }
}
