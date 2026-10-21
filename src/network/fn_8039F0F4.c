#pragma force_active on
typedef struct Context {
    unsigned int unk0;
    unsigned int flags;
    int position;
    unsigned char unkC[0x14];
    unsigned char data[0x10];
    int start;
    int length;
} Context;

extern unsigned char *lbl_805A1170;
extern unsigned char lbl_8059FD7C[7];
extern int lbl_805A1190;

extern void fn_80397748(void *, int, int);
extern void fn_80397818(void *, const void *, int);
extern int fn_8039EDE8(void *, int, void *, int, int *);
extern int fn_80398BD8(void *, int, int);

int fn_8039F0F4(Context *self)
{
    int length;
    int result;
    int mode;
    unsigned char *buffer = lbl_805A1170;
    int total;
    fn_80397748(buffer, 0, 0x400);
    fn_80397818(buffer, lbl_8059FD7C, 0x3FE);
    buffer += 6;
    mode = 1;
    self->start = self->position + 6;
    if (self->flags & 0x100000) {
        mode = 2;
    }
    do {
        result = fn_8039EDE8(self->data, mode, buffer, 0x3FE, &length);
        if (result != 0) {
            return result;
        }
        buffer += length;
        buffer[0] = 13;
        buffer[1] = 10;
        total = length + 8;
        if (0x3FE - total <= 0) {
            return -11;
        }
    } while (0);
    if (result == 0) {
        result = fn_80398BD8(lbl_805A1170, total, lbl_805A1190);
        if (result == 0) {
            self->position += total;
            self->length = self->position - self->start - 2;
        }
    }
    return result;
}
