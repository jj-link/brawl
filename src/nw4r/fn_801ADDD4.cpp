#pragma force_active on
struct Obj {
    void* m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
};

extern "C" char lbl_804662E8[];

extern "C" void fn_801ADDD4(Obj* self, int a, int b, int c) {
    self->m4 = a;
    self->m0 = lbl_804662E8;
    self->m8 = b;
    self->mC = c;
    self->m10 = 0;
    self->m14 = 0;
}
