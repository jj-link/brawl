#pragma force_active on
typedef unsigned char u8;

struct Obj {
    int unk0;
    u8 unk4;
};

extern "C" void fn_802CEE7C(int unused, struct Obj* self) {
    self->unk0 = 2;
    self->unk4 = 1;
}
