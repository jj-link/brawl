#pragma force_active on
extern "C" {
void fn_80082544(int, int);

struct Obj {
    int pad0[0x58 / 4];
    int unk58;
    int pad1[(0x64 - 0x5C) / 4];
    int unk64;
};

void fn_8009B8FC(Obj* self) {
    if (self->unk58 != 0 && self->unk64 == 0) {
        fn_80082544(self->unk58, 1);
        self->unk58 = 0;
    }
}
}
