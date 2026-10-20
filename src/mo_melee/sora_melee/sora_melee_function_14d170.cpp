#pragma force_active on
struct Obj {
    char pad[0x4c];
    int field;
};

extern "C" void fn_27_14D170(Obj *self, int v) {
    self->field += v;
}
