#pragma force_active on
extern "C" void fn_8019564C(void*, void*, int, float);
extern float lbl_8059E8E0;

struct Obj {
    char pad0[0x10];
    unsigned int count;
    unsigned short* idx;
    float f18;
    float f1c;
    float f20;
    float f24;
    float (*fn)(Obj*, float, float, float);
    char sub[4];
    char* data;
};

extern "C" void fn_8019B19C(Obj* self) {
    self->f18 = self->fn(self, self->f20, self->f24, self->f18 + self->f1c * lbl_8059E8E0);
    if (self->data != 0) {
        float v = self->f18;
        unsigned int i = 0;
        int off = 0;
        for (; i < self->count; i++) {
            unsigned short e = *(unsigned short*)((char*)self->idx + off);
            if (!(e & 0x8000)) {
                int n = e & 0x3fff;
                fn_8019564C(self->sub, self->data + n * 0x4c, n, v);
            }
            off += 2;
        }
    }
}
