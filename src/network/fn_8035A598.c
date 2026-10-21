#pragma force_active on
typedef struct {
    /* 0x0 */ int count;
    /* 0x4 */ int pad4;
    /* 0x8 */ int size;
    /* 0xC */ int padC[2];
    /* 0x14 */ int base;
} S_8035A598;

int fn_8035A598(S_8035A598* self, int index) {
    if (index < 0 || index >= self->count) {
        return 0;
    }
    return self->base + self->size * index;
}
