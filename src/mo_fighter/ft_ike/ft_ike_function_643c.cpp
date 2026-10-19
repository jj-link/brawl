#pragma force_active on
extern "C" void fn_27_D2FF0(void*, int, int);
extern "C" void fn_27_61454(void*, void*, void*, void*, void*, void*);
extern char lbl_27_bss_4694[12];
extern char lbl_27_bss_46AC[4];

struct Base {
    char pad[0xAC];
    int field;
};

extern "C" Base* fn_119_643C(Base* self, void* a, void* b) {
    fn_27_D2FF0(self, 1, 0);
    fn_27_61454(&self->field, a, self, lbl_27_bss_4694, lbl_27_bss_46AC, b);
    return self;
}
