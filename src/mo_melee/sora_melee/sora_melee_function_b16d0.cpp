#pragma force_active on
struct fn27Obj {
    int unk0;
    int unk4;
    int unk8;
    char pad[0x2C];
    int unk38;
};

extern "C" int fn_8009F474(void* a, int b, int c);

extern "C" {
void fn_27_B16D0(fn27Obj* self, void* a, int b, int c) {
    self->unk8 = b;
    self->unk4 = fn_8009F474(a, 1, 0);
    self->unk38 = c;
}
}
