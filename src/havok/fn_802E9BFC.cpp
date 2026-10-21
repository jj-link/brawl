#pragma force_active on

extern unsigned char lbl_80488300[];
extern const float lbl_805A4428;
extern const float lbl_805A442C;

struct InputData {
    char pad[0x1C0C];
    int a;
    int b;
};

struct Input {
    char pad[0x70];
    InputData* data;
};

struct Object {
    void* vtable;
    unsigned short f4, f6;
    int f8, fC, f10, f14;
    Input* f18;
    int f1C;
    unsigned short f20, f22;
    unsigned char f24, f25;
    unsigned char flagsA : 4;
    unsigned char flagsB : 2;
    unsigned char flagsC : 2;
    unsigned char flagsD : 2;
    unsigned char flagsE : 6;
    int f28;
    unsigned short f2C, f2E;
    float f30, f34;
    void* f38;
    int f3C;
    unsigned int f40;
    int f44;
    void* f48;
    int f4C;
    unsigned int f50;
    int f54, f58;
    unsigned short f5C, f5E;
    int f60, f64;
    unsigned int f68;
    float f6C;
};

extern "C" void fn_802E9BFC(Object* self, Input* input) {
    self->f6 = 1;
    self->vtable = lbl_80488300;
    self->f18 = input;
    self->f22 = 0xFFFF;
    self->f24 = 0;
    self->f25 = 0;
    self->flagsA = 0;
    self->flagsC = 1;
    self->flagsD = 1;
    self->f28 = -47;
    self->f2C = 0;
    self->f30 = lbl_805A4428;
    self->f34 = lbl_805A4428;
    self->f38 = &self->f44;
    self->f3C = 0;
    self->f40 = 0x80000001;

    int b = input->data->b;
    int a = input->data->a;

    self->f48 = &self->f54;
    self->f4C = 0;
    self->f50 = 0x80000001;
    self->f5C = b;
    self->f5E = a;
    self->f58 = (unsigned short)a;
    self->f60 = 0;
    self->f64 = 0;
    self->f68 = 0x80000000;
    self->f6C = lbl_805A442C;
    self->flagsB = 0;
    self->f8 = 0;
    self->fC = 0;
    self->f10 = 0;
    self->f14 = 0;
    self->f1C = 0;
}
