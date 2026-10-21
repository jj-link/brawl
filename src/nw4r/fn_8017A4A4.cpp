#pragma force_active on

struct S {
    void* table;
};

extern "C" void fn_801747D8(S* self);
extern "C" unsigned char lbl_80465500[];

extern "C" S* fn_8017A4A4(S* self) {
    fn_801747D8(self);
    self->table = lbl_80465500;
    return self;
}
