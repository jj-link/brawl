#pragma force_active on
typedef struct Buffer {
    char pad[12];
    char *data;
    int pos;
    int end;
    int unk18;
    int start;
    int limit;
} Buffer;

extern void fn_80281D60(void *, const void *, int);

void fn_80280F00(Buffer *self)
{
    int size;
    int rem;
    int offset;

    if (self->start < 0) {
        self->pos = 0;
        self->end = 0;
        return;
    }

    size = self->pos - self->start;
    if (size > self->limit) {
        self->pos = 0;
        self->end = 0;
        self->start = -1;
        self->limit = -1;
        return;
    }

    if (self->start > 0) {
        rem = size % 512;
        offset = rem != 0 ? 512 - rem : 0;
        fn_80281D60(self->data + offset, self->data + self->start, size);
        self->start = offset;
        self->pos = (size / 512 + (rem != 0)) << 9;
        self->end = self->pos;
    }
}
