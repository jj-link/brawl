#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Buffer {
    u8 *base;
    u8 *current;
    int mode;
    u8 wrapped;
    u8 padding[3];
    u32 capacity;
    u32 total;
} Buffer;

extern const u8 lbl_8040DE50[];
extern void fn_802696FC(Buffer *, u8, int);

void fn_80269400(Buffer *self, unsigned short value)
{
    int mode;
    u32 used1, used2, used3;
    u8 *p1, *p2, *p3, *p4;
    u8 *base1, *base2, *base3;

    mode = self->mode;
    if (mode != 8) {
        fn_802696FC(self, lbl_8040DE50[mode], mode);
    }

    base1 = self->base;
    used1 = self->current - base1;
    if (used1 >= self->capacity) {
        self->wrapped = 1;
        self->total += used1;
        self->current = base1;
    }

    p1 = self->current;
    *p1 = (u8)(value >> 8);
    p2 = p1 + 1;
    base2 = self->base;
    used2 = p2 - base2;
    self->current = p2;
    if (used2 >= self->capacity) {
        self->wrapped = 1;
        self->total += used2;
        self->current = base2;
    }

    p3 = self->current;
    *p3 = (u8)value;
    p4 = p3 + 1;
    base3 = self->base;
    used3 = p4 - base3;
    self->current = p4;
    if (used3 >= self->capacity) {
        self->wrapped = 1;
        self->total += used3;
        self->current = base3;
    }

    *self->current = 0;
}
