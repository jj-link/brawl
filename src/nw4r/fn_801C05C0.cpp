#pragma force_active on
extern "C" {
void fn_801BBC1C(void*, int*, int*);
void fn_801BBC68(void*, int, int);
int fn_80202614(void*);
int fn_802026A8(void*);
}
struct In6 { float a, b, c, d, e, f; };
struct Self {
    char pad0[0xC];
    unsigned char flag;   // 0xC
    char pad0d[3];
    char* heap;           // 0x10
    char pad14[4];
    In6 params;           // 0x18
    char obj[0x178 - 0x30]; // 0x30
    float c_178;
    float c_17C;
    float c_180;
    float c_184;
    float c_188;
    float c_18C;
};
extern "C" int fn_801C05C0(Self* self, const In6* src) {
    int spC;
    int sp8;
    int r31;
    unsigned int size;
    unsigned int avail;

    self->params = *src;

    self->c_188 = (src->a > 0.1f) ? 0.1f : ((src->a < 0.0f) ? 0.0f : src->a);
    self->c_180 = (src->b > 10.0f) ? 10.0f : ((src->b < 0.0f) ? 0.0f : src->b);
    self->c_178 = (src->c > 1.0f) ? 1.0f : ((src->c < 0.0f) ? 0.0f : src->c);
    self->c_184 = (src->d > 1.0f) ? 1.0f : ((src->d < 0.0f) ? 0.0f : src->d);
    self->c_18C = (src->e > 1.0f) ? 1.0f : ((src->e < 0.0f) ? 0.0f : src->e);
    self->c_17C = (src->f > 1.0f) ? 1.0f : ((src->f < 0.0f) ? 0.0f : src->f);

    if (self->flag == 0) {
        return 1;
    }

    size = (fn_80202614(self->obj) + 0x87) & ~0x1F;
    {
        char* p = self->heap;
        if (p == 0) {
            avail = 0;
        } else {
            avail = *(unsigned int*)(p + 0x1C) - (unsigned int)p;
        }
    }
    if (size > avail) {
        return 0;
    }

    fn_801BBC1C(&self->flag, &spC, &sp8);
    r31 = fn_802026A8(self->obj);
    fn_801BBC68(&self->flag, spC, sp8);
    return (unsigned int)(-r31 | r31) >> 31;
}
