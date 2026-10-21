#pragma force_active on
struct Obj {
    char pad[0x14];
    int unk14;
};

extern "C" void fn_8031AB44(Obj* self);

extern "C" void fn_80315738(Obj* self) {
    if (self->unk14 != 0) {
        fn_8031AB44(self);
    }
}
