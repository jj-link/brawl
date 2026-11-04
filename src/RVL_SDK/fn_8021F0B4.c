#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

typedef struct State {
    char pad[0x882];
    s16 a, b, c, d, e, f, g, h, i, j, k, l;
    u8 m, n;
    void (*callback)(int, int);
    char pad2[0x21];
    u8 type, other;
    char pad3[0x4e];
    u8 flag;
    char pad4[0x62];
    u8 *data;
} State;

extern State *lbl_804F6810[];
extern u8 lbl_805A0C90[4], lbl_805A0C94[4];
extern char lbl_8047C920[];
extern void fn_8022550C(void *, ...);

void fn_8021F0B4(int channel, int result)
{
    char *base = lbl_8047C920;
    State *s = lbl_804F6810[channel];
    int valid = -1;
    u8 *data = s->data;
    int offset, i, j, sum;
    u8 *p;

    switch (result) {
    case -1:
        s->type = 0xfd;
        break;
    case 0:
        s->type = lbl_805A0C94[channel];
        break;
    default:
        s->type = 0xfc;
        break;
    }

    s->other = lbl_805A0C90[channel];

    if ((u8)(s->type + 255) <= 1) {
        i = 0;
        for (offset = 0; i < 2; i++, offset += 16) {
            sum = 0;
            for (j = offset; j < offset + 14; j++)
                sum += data[j];

            if ((u8)(sum + 0x55) == data[offset + 14] &&
                (u8)(sum + 0xaa) == data[offset + 15])
                valid = offset;
        }

        switch (s->type) {
        case 1:
            if (valid < 0) {
                fn_8022550C(base + 0x25c);
                s->g = 0x200;
                s->h = 0x200;
                s->i = 0x200;
                s->j = 0x2cc;
                s->k = 0x2cc;
                s->l = 0x2cc;
            } else {
                int first = data[valid];
                p = (u8 *)(valid + (unsigned int)data);
                s->g = (first << 2) | ((p[3] >> 4) & 3);
                s->h = (p[1] << 2) | ((p[3] >> 2) & 3);
                s->i = (p[2] << 2) | (p[3] & 3);
                s->j = (p[4] << 2) | ((p[7] >> 4) & 3);
                s->k = (p[5] << 2) | ((p[7] >> 2) & 3);
                s->l = (p[6] << 2) | (p[7] & 3);
                s->c = (s8)p[8];
                s->b = (s8)p[9];
                s->a = (s8)p[10];
                s->f = (s8)p[11];
                s->e = (s8)p[12];
                s->d = (s8)p[13];

                fn_8022550C(base + 0x270, s->g, s->h, s->i);
                fn_8022550C(base + 0x2a0, s->j, s->k, s->l);
                fn_8022550C(base + 0x2d0, s->a, s->c, s->b);
                fn_8022550C(base + 0x2f8, s->d, s->f, s->e);
            }
            break;

        case 2: {
            int first = data[valid];
            p = (u8 *)(valid + (unsigned int)data);
            s->c = (s8)first;
            s->b = (s8)p[1];
            s->a = (s8)p[2];
            s->f = (s8)p[3];
            s->e = (s8)p[4];
            s->d = (s8)p[5];
            s->i = (s8)p[6];
            s->h = (s8)p[7];
            s->g = (s8)p[8];
            s->l = (s8)p[9];
            s->k = (s8)p[10];
            s->j = (s8)p[11];
            s->m = p[12];
            s->n = p[13];

            fn_8022550C(base + 0x320, s->a, s->c, s->b);
            fn_8022550C(base + 0x348, s->d, s->f, s->e);
            fn_8022550C(base + 0x370, s->g, s->i, s->h);
            fn_8022550C(base + 0x398, s->j, s->l, s->k);
            fn_8022550C(base + 0x3c0, s->m, s->n);
            break;
        }
        }

        s->flag = 0;
    }

    if (s->callback) {
        s->callback(channel, s->type);
        s->callback = 0;
    }
}
