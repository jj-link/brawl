#pragma force_active on
typedef struct Context {
    unsigned char pad0[8];
    int total;
    unsigned char padC[0xCC];
    unsigned char *data;
    int length;
} Context;

extern unsigned char *lbl_805A1170;
extern char lbl_80492200[];
extern int lbl_805A1190;

extern void fn_80397748(void *, int, int);
extern void fn_80397610(void *, const char *);
extern void fn_8039D440(const void *, int, void *, int, int *);
extern int fn_80398BD8(void *, int, int);

int fn_8039F5B0(Context *self)
{
    int written;
    unsigned char *buf;
    unsigned char *data;
    int pos;
    int remaining;
    int count;
    int result;

    if (self->length == 0)
        return 0;

    buf = lbl_805A1170;
    fn_80397748(buf, 0, 0x400);
    fn_80397610(buf, lbl_80492200);

    data = self->data;
    pos = 10;
    remaining = self->length;

    while (remaining > 0) {
        buf[pos++] = 0x20;
        count = remaining;
        if (remaining > 42)
            count = 42;

        fn_8039D440(data, count, buf + pos, 0x4C, &written);
        data += count;
        remaining -= count;
        pos += written;
        buf[pos++] = 13;
        buf[pos++] = 10;
    }

    result = fn_80398BD8(buf, pos, lbl_805A1190);
    if (result == 0)
        self->total += pos;

    return result;
}
