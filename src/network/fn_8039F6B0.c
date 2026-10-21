#pragma force_active on
typedef struct {
    unsigned char pad0[8];
    int total;
    unsigned char padC[0xD4];
    unsigned char *data;
    int length;
} Context;

extern unsigned char *lbl_805A1170;
extern char lbl_8049220C[];
extern int lbl_805A1190;

extern void fn_80397748(void *, int, int);
extern void fn_80397610(void *, const char *);
extern void fn_8039D440(const void *, int, void *, int, int *);
extern int fn_80398BD8(void *, int, int);

int fn_8039F6B0(Context *self)
{
    int written;
    unsigned char *buffer;
    unsigned char *data;
    int offset;
    int length;
    int chunk;
    int result;

    if (self->length == 0)
        return 0;

    buffer = lbl_805A1170;
    fn_80397748(buffer, 0, 0x400);
    fn_80397610(buffer, lbl_8049220C);

    data = self->data;
    offset = 0xE;
    length = self->length;

    while (length > 0) {
        buffer[offset++] = 0x20;
        chunk = length;
        if (length > 0x2A)
            chunk = 0x2A;

        fn_8039D440(data, chunk, buffer + offset, 0x4C, &written);
        data += chunk;
        length -= chunk;
        offset += written;
        buffer[offset++] = 0xD;
        buffer[offset++] = 0xA;
    }

    result = fn_80398BD8(buffer, offset, lbl_805A1190);
    if (result == 0)
        self->total += offset;

    return result;
}
