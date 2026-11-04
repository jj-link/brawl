#pragma force_active on
extern "C" void fn_801935E4(void*, void*, int, float);

struct Obj {
    char pad0[0x10];
    unsigned int count;
    unsigned short* idx;
    float f18;
    char pad1c[4];
    float f20;
    float f24;
    float (*fn)(Obj*, float, float, float);
    char sub[4];
    char* data;
};

extern "C" void fn_80198C60(Obj* self, float f) {
    self->f18 = self->fn(self, self->f20, self->f24, f);
    if (self->data != 0) {
        float v = self->f18;
        unsigned int i = 0;
        int off = 0;
        for (; i < self->count; i++) {
            unsigned short e = *(unsigned short*)((char*)self->idx + off);
            if (!(e & 0x8000)) {
                int n = e & 0x3fff;
                fn_801935E4(self->sub, self->data + n * 0x44, n, v);
            }
            off += 2;
        }
    }
}