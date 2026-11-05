#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Cursor {
    char *data;
    int unused;
    int wide;
    u16 offset;
    u16 pad;
} Cursor;
extern char lbl_8053B248[];
extern u16 fn_803BD364(Cursor *, int);

static inline int is_lower(u16 c)
{
    return c >= 0x61 && c <= 0x7a;
}
static inline u16 upper(u16 c)
{
    return is_lower(c) ? c - 0x20 : c;
}
static inline u32 full_upper(u16 c, u16 *out)
{
    if (c >= 0xff41 && c <= 0xff5a) {
        *out = c - 0x20;
        return 1;
    }
    return 0;
}
static inline unsigned char next_byte(Cursor *s)
{
    return (unsigned char)s->data[s->offset++];
}
static inline u16 next(Cursor *s)
{
    if (s->wide) {
        u16 c, out;
        if (s->offset > 0x20a) return 0;
        c = *(u16 *)(s->data + s->offset);
        s->offset += 2;
        c = upper(c);
        if (full_upper(c, &out) == 1) c = out;
        return c;
    } else {
        int c;
        if (s->offset >= 0xc) return 0;
        c = (signed char)s->data[s->offset++];
        if ((*(int (**)(int, int))(lbl_8053B248 + 0x30))(c, 1)) {
            c = (u16)(((c << 8) & 0xff00) + next_byte(s));
        }
        return upper((u16)c);
    }
}
int fn_803BD624(u16 c, Cursor *s, u16 p, Cursor *pattern, int mode)
{
    while (p) {
        switch (p) {
        case '?':
            if (!c) return 0;
            break;
        case '*':
            p = fn_803BD364(pattern, mode);
            while (p == '*' || p == '?') p = fn_803BD364(pattern, mode);
            if (!p) return 1;
            while (c) {
                if (c == p) {
                    Cursor sc = *s;
                    Cursor pc = *pattern;
                    c = next(&sc);
                    p = fn_803BD364(&pc, mode);
                    if (fn_803BD624(c, &sc, p, &pc, mode)) return 1;
                }
                c = next(s);
            }
            return 0;
        default:
            if (c != p) return 0;
            break;
        }
        c = next(s);
        p = fn_803BD364(pattern, mode);
    }
    return c == 0;
}
