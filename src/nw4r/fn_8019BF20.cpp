#pragma force_active on
extern "C" void fn_80197484(void*, void*, int, void*, float);
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
    void* field30;
    char* data;
};
extern "C" void fn_8019BF20(Obj* self) {
    self->f18 = self->fn(self, self->f20, self->f24, self->f18 + self->f1c * lbl_8059E8E0);
    if (self->data != 0) {
        float v = self->f18;
        unsigned int i = 0;
        int off = 0;
        for (; i < self->count; i++) {
            unsigned short e = *(unsigned short*)((char*)self->idx + off);
            if (!(e & 0x8000)) {
                int n = e & 0x3fff;
                fn_80197484(self->sub, self->data + n * 0x218, n, self->field30, v);
            }
            off += 2;
        }
    }
}