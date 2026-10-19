#pragma force_active on
struct Src {
    int a;
    int b;
};

struct Obj {
    int m0;
    void* m4;
    int m8;
    int mC;
    int m10;
    int m14;
};

extern "C" char lbl_40_data_2018[];

extern "C" void fn_40_F95C(Obj* self, const Src* src, int x) {
    self->m0 = 0;
    self->m8 = 60;
    self->m4 = lbl_40_data_2018;
    self->mC = x;
    self->m10 = src->a;
    self->m14 = src->b;
}
