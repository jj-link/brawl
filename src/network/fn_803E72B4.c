#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Cursor {
    char *data;
    int unused;
    int wide;
    u16 offset;
    u16 pad;
} Cursor;
extern char lbl_805644C0[];
extern u8 lbl_8059FEE8, lbl_8059FEEC, lbl_8059FF08, lbl_8059FF09;
extern u32 fn_803D66F4(void *);
extern int fn_803D6A50(void *, void *, int, int, int);
extern int fn_803E88BC(void *, int, int);
extern u16 fn_803E612C(Cursor *, int);
extern u32 fn_803E6480(u16, Cursor *, u16, Cursor *, int);
static inline int is_lower(u16 c) { return c >= 0x61 && c <= 0x7a; }
static inline u16 upper(u16 c) { return is_lower(c) ? c - 0x20 : c; }
static inline u32 full_upper(u16 c, u16 *out) {
    if (c >= 0xff41 && c <= 0xff5a) { *out = c - 0x20; return 1; }
    return 0;
}
static inline unsigned char next_byte(Cursor *s) { return (unsigned char)s->data[s->offset++]; }
static inline u16 next(Cursor *s) {
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
        if ((*(int (**)(int, int))(lbl_805644C0 + 0x54))(c, 1)) {
            c = (u16)(((c << 8) & 0xff00) + next_byte(s));
        }
        return upper((u16)c);
    }
}
u32 fn_803E72B4(char *data, Cursor *pattern, int mode) {
    Cursor s;
    Cursor p;
    u32 result = 1;
    s.data = data;
    s.unused = 0;
    s.wide = mode;
    s.offset = 0;
    p = *pattern;
    if (fn_803D66F4(pattern) == 1) {
        if (mode == 0 && (*(u32 *)(lbl_805644C0 + 0x60) & 2) == 2) {
            u8 bytes[2];
            u32 status = 0;
            bytes[0] = lbl_8059FF08;
            bytes[1] = lbl_8059FF09;
            if (fn_803D6A50(&p, bytes, 1, 0, 2) == 0) status = 1;
            if (status == 1) {
                u8 bytes2[2];
                bytes2[0] = lbl_8059FF08;
                bytes2[1] = lbl_8059FF09;
                result = 0;
                if (fn_803D6A50(&p, bytes2, 1, 0, 2) == 0) result = 1;
                if (result == 1) {
                    s.offset += 2;
                    p.data += 2;
                }
            }
        }
    } else if ((*(u32 *)(lbl_805644C0 + 0x60) & 2) == 2 && mode == 0 &&
               fn_803D6A50(pattern, &lbl_8059FEE8, 1, 0, 1) != 0 &&
               fn_803D6A50(pattern, &lbl_8059FEEC, 1, 0, 2) != 0 &&
               fn_803E88BC(pattern, 1, 0) == 0) {
        result = 0;
    }
    if (result == 1) {
        if (s.wide) {
            u16 out;
            if (s.offset > 0x20a) result = 0;
            else {
                result = *(u16 *)(s.data + s.offset);
                s.offset += 2;
                result = upper(result);
                if (full_upper(result, &out) == 1) result = out;
            }
        } else {
            int c;
            if (s.offset >= 0xc) result = 0;
            else {
                c = (signed char)s.data[s.offset++];
                if ((*(int (**)(int, int))(lbl_805644C0 + 0x54))(c, 1))
                    c = (u16)(((c << 8) & 0xff00) + next_byte(&s));
                result = upper((u16)c);
            }
        }
        result = fn_803E6480(result, &s, fn_803E612C(&p, mode), &p, mode);
    }
    return result;
}