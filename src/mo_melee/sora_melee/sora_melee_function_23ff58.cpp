#pragma force_active on
extern "C" void fn_27_23F008(void*);
extern "C" unsigned char lbl_27_data_4D690[];

struct Object {
    unsigned char pad0[0x3C];
    void* vtable;
    unsigned char pad40[0x8C];
    unsigned char cc;
    unsigned char cd;
    unsigned char ceFlag : 1;
    unsigned char ceRest : 7;
    unsigned char cf;
    unsigned char d0;
    unsigned char d1;
    unsigned char d2;
    unsigned char d3;
    unsigned char d4;
};

extern "C" Object* fn_27_23FF58(Object* self) {
    fn_27_23F008(self);
    self->vtable = lbl_27_data_4D690;
    self->cc = 0;
    self->cd = 0;
    self->ceFlag = 0;
    self->d1 = 0;
    self->d2 = 1;
    self->d3 = 2;
    self->d4 = 3;
    return self;
}
