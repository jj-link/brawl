#pragma force_active on
extern "C" void fn_8031830C(void*, int);
extern "C" void fn_802FC6AC(void*, int, int);

struct Obj {
    virtual void v0(int);
    int unk4;
    int unk8;
    char pad[0x68];
    int unk74;
    signed char unk78;
};

extern "C" void fn_802B0050(Obj* self) {
    if (self->unk78) {
        fn_8031830C((char*)self + 0x30, self->unk8);
    } else {
        fn_802FC6AC((char*)self + 0x30, self->unk74, self->unk8);
    }
    if (self != 0) {
        self->v0(1);
    }
}
