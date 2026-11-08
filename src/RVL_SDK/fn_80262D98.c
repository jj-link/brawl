#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef struct Reader {
    s32 f00,f04,f08,f0C,f10,f14,f18,f1C,f20,f24,f28,f2C,f30,f34,f38;
    u16 f3C,f3E;
    s32 f40;
    u8 pad44[0x179A];
    u16 f17DE;
} Reader;
typedef struct Cursor { s32 f00,f04,f08,f0C,f10,f14; } Cursor;
extern s32 fn_80260FC0(u8 *, Reader *);
extern s32 fn_80261004(u16 *, Reader *);
extern s32 fn_80261264(Reader *);
extern s32 fn_80262F7C(Reader *);
extern s32 fn_802632F4(u16 *, Reader *);
extern s32 fn_80263C58(Reader *);
static inline s32 parse(Reader *a) {
    u16 x;
    s32 r = fn_80261004(&x, a);
    if (r < 0) return r;
    if (x != 4) return -0x43;
    r = fn_80261004(&x, a);
    if (r < 0) return r;
    a->f17DE = x;
    return 0;
}
static inline s32 scan(Reader *a) {
    u8 b;
    s32 r;
    s32 var = 0;
    Cursor saved = *(Cursor *)a;
    while ((u16)var != 0xFFDC) {
        r = fn_80260FC0(&b, a);
        if (r < 0) break;
        var = ((var << 8) & 0xFF00) | b;
    }
    if ((u16)var == 0xFFDC) {
        r = parse(a);
        if (r < 0) return r;
    }
    *(Cursor *)a = saved;
    return 0;
}
s32 fn_80262D98(Reader *a) {
    u16 x = 0;
    s32 r = fn_802632F4(&x, a);
    if (r < 0) return r;
    if (x != 0xFFDA) return -0x22;
    r = fn_80263C58(a);
    if (r < 0) return r;
    r = scan(a);
    if (r < 0) return r;
    if (a->f17DE == 0) return -0x50;
    r = fn_80262F7C(a);
    if (r < 0) return r;
    a->f1C = 0;
    a->f20 = 0;
    a->f24 = 0;
    a->f28 = 0;
    a->f3C = 0;
    r = fn_80261264(a);
    if (r < 0) return r;
    a->f3E = 0;
    a->f40 = 0;
    return 0;
}