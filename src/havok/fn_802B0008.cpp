#pragma force_active on
extern "C" void fn_802FC6AC(void* arg0, int arg1, int arg2);

struct Fn802B0008 {
    char pad0[0x8];
    int unk8;
    char padC[0x24];
    int unk30;
    char pad34[0x40];
    int unk74;
    char pad78;
};

extern "C" void fn_802B0008(Fn802B0008* self) {
    fn_802FC6AC((char*)self + 0x30, self->unk74, self->unk8);
    self->unk30 = 0;
    self->pad78 = 1;
}
